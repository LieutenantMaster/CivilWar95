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
	static int m_MaxDistanceUntilRuined = 80; // KM
	
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
};
