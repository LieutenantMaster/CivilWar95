/**
 * CarScript.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class CarScript
{
	float m_OdometerMeters = 0.0;
	static int m_MaxDistanceUntilRuined = 100; // KM
	
	#ifdef SERVER
	override void OnUpdate( float dt )
    {
		//if is moving back or forward
		float velLength = GetVelocity(this).Length();
		if ( velLength > 0.1 || velLength < -0.1 )
		{			
			//meters per second
			m_OdometerMeters += velLength;

			//wait until the tick collected
			if  ( (m_OdometerMeters / 100) > 10) 
			{
				// *dt to get damage per second
				for ( int j = 0; j < GetInventory().AttachmentCount(); j++ )
				{
					ItemBase attachment = ItemBase.Cast(GetInventory().GetAttachmentFromIndex(j));
					
					int slotId;
					string slotName;		
					attachment.GetInventory().GetCurrentAttachmentSlotInfo(slotId, slotName);
					slotName.ToLower();
					
					if (!slotName.Contains("spare"))
					{
						if ( attachment && attachment.IsInherited(CarWheel) )
						{
							if ( attachment.GetHealth() > 0 )
							{
								float totaldmg = attachment.GetMaxHealth() / ( m_MaxDistanceUntilRuined * 1000 / 10);
								totaldmg += Math.RandomFloatInclusive(-0.2, 0.2) * totaldmg;

								attachment.AddHealth(-totaldmg);
							}
						}
					}
				}
				m_OdometerMeters = 0;
			}
		}
		
		super.OnUpdate( dt );
	}
	#endif

    override void OnContact( string zoneName, vector localPos, IEntity other, Contact data )
	{
		float DamageHit = data.Impulse * m_dmgContactCoef; // 0.070 Hatchback, 0.130 Sedan, 0.075 Offroad
		float m_Impulse = data.Impulse;
        if ( DamageHit <= 250 )
		{
			data.Impulse = 0.00; 
		}
		else if ( DamageHit <= 500 )
		{
			data.Impulse = 0.15 * m_Impulse; 
		}
		else if ( DamageHit <= 750 )
		{
			data.Impulse = 0.3 * m_Impulse; 
		}
		else if ( DamageHit <= 1000 )
		{
			data.Impulse = 0.4 * m_Impulse; 
		}
		else if ( DamageHit <= 1350 )
		{
			data.Impulse = 0.5 * m_Impulse; 
		}

		//On Car crashed, if invoked with out a super, it removes the car crash hit
		super.OnContact( zoneName, localPos, other, data );
	}

	override void DamageCrew(float dmg)
	{
		for ( int c = 0; c < CrewSize(); ++c )
		{
			Human crew = CrewMember( c );
			if ( !crew )
				continue;

			PlayerBase player;
			if ( Class.CastTo(player, crew ) )
			{
				float shockTemp = Math.InverseLerp(GameConstants.CARS_CONTACT_DMG_THRESHOLD, GameConstants.CARS_CONTACT_DMG_KILLCREW, dmg);
				shockTemp = Math.Clamp(shockTemp,0,1);
				float shock = Math.Lerp( 50, 150, shockTemp );
				float hp = Math.Lerp( 1, 20, shockTemp );
				
				player.AddHealth("", "Shock", -shock );
				player.AddHealth("", "Health", -hp );
			}
		}
	}
	
	override void CheckContactCache()
	{
		int contactZonesCount = m_ContactCache.Count();
		
		if (contactZonesCount == 0)
			return;		
		
		for (int i = 0; i < contactZonesCount; ++i)
		{
			string zoneName = m_ContactCache.GetKey(i);
			array<ref CarContactData> data = m_ContactCache[zoneName];

			float dmg = Math.AbsInt(data[0].impulse * m_dmgContactCoef * 0.6);
			float crewDmgBase = Math.AbsInt((data[0].impulse / dBodyGetMass(this)) * 1000 * m_dmgContactCoef);// calculates damage as if the object's weight was 1000kg instead of its actual weight

			if ( dmg < GameConstants.CARS_CONTACT_DMG_MIN )
				continue;

			int pddfFlags;
			if (dmg < GameConstants.CARS_CONTACT_DMG_THRESHOLD)
			{
				SynchCrashLightSound(true);
				pddfFlags = ProcessDirectDamageFlags.NO_TRANSFER;
			}
			else
			{
				DamageCrew(crewDmgBase);
				SynchCrashHeavySound(true);
				pddfFlags = 0;
			}
			
			ProcessDirectDamage(DT_CUSTOM, null, zoneName, "EnviroDmg", "0 0 0", dmg * 0.6, pddfFlags);
		}
		
		UpdateHeadlightState();
		UpdateLights();
		
		m_ContactCache.Clear();
	}
	
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);

		bool isGlobal;
		if (!dmgZone || dmgZone == "GlobalHealth")
			isGlobal = true;

		float dmg = damageResult.GetDamage(dmgZone, "");

		//! Apply additional dmg if ammo type is grenade or rocket
		//! One direct hit with a rocket blows up a MH6, two direct hits blow up a Merlin
		//! Grenades take several more
		float additionalDmg;
		bool explode;
		switch (ammo)
		{
			case "CW95_ProjectileRPG_Ammo":  //! Base dmg = 300
				additionalDmg = dmg * 20 - dmg;
			break;
			default:
				//! Explode if base dmg exceeded heli max health, or 1 in 50 chance if it exceeded current heli health
				if (isGlobal && (dmg > GetMaxHealth(dmgZone, "") || (Math.RandomInt(0, 50) < 1 && IsDamageDestroyed())))
					explode = true;
			break;
		}

		if (additionalDmg)
		{
			//! Explode if additional dmg exceeds current health
			if (isGlobal && additionalDmg > GetHealth(dmgZone, ""))
				explode = true;

			DecreaseHealth(dmgZone, "", additionalDmg);
		}

		if (isGlobal)
		{
			//! Always damage engine proportionally when taking global damage
			float engineMaxHealth = GetMaxHealth("Engine", "");
			float engineHealth = GetHealth("Engine", "");
			float engineHealthNew = engineMaxHealth * GetHealth01(dmgZone, "");
			if (engineHealthNew < engineHealth)
			{
				SetHealth("Engine", "", engineHealthNew);
			}
		}
	}
};
