/**
 * CW95_DynamicEffect_Base.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_DynamicEffect_Base: House
{
	Particle m_ParticleEfx;
	EffectSound m_SoundSetLoop;

	#ifndef SERVER
	void CW95_DynamicEffect_Base()
	{
		DoEffect();
    }

	override void EEDelete(EntityAI parent)
	{
		if ( m_ParticleEfx )
			m_ParticleEfx.Stop();

		if ( m_SoundSetLoop )
			StopSoundSet( m_SoundSetLoop );
	}
	#endif

    void DoEffect() {}
};

class CW95_DynamicFire_Base: CW95_DynamicEffect_Base
{
	Particle m_ParticleEfxSmoke;

	// UniversalTemperatureSource
	protected ref UniversalTemperatureSource m_UTSource;
	protected ref UniversalTemperatureSourceSettings m_UTSSettings;
	protected ref UniversalTemperatureSourceLambdaConstant m_UTSLBonfire;

	static float TIMER_HEATING_UPDATE_INTERVAL		= 2;
	static float CONST_FIRE_TEMP					= 500;
	static float PARAM_MAX_TRANSFERED_TEMPERATURE	= 10;		//! maximum value for temperature that will be transfered to player (environment)
	static float PARAM_FULL_HEAT_RADIUS				= 5;
	static float PARAM_HEAT_RADIUS					= 5;

	protected ref AreaDamageManager 	m_AreaDamage;

	void CW95_DynamicFire_Base()
	{
		CreateAreaDamage();
	}

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(CW95_ActionExtinguishByExtinguisher);
		AddAction(CW95_ActionExtinguishByLiquid);
	}
	
	void CreateAreaDamage()
	{
		//destroy area damage if some already exists
		DestroyAreaDamage();
		
		//create new area damage
		m_AreaDamage = new AreaDamageLoopedDeferred( this );
		m_AreaDamage.SetDamageComponentType(AreaDamageComponentTypes.HITZONE);
		m_AreaDamage.SetExtents("-0.30 0 -0.30", "0.80 1.0 0.80");
		m_AreaDamage.SetLoopInterval( 0.5 );
		m_AreaDamage.SetDeferDuration( 0.5 );
		m_AreaDamage.SetHitZones( { "Head","Torso","LeftHand","LeftLeg","LeftFoot","RightHand","RightLeg","RightFoot" } );
		m_AreaDamage.SetAmmoName( "FireDamage" );
		m_AreaDamage.Spawn();
	}
	
	void DestroyAreaDamage()
	{
		if ( m_AreaDamage ) 
		{
			m_AreaDamage.Destroy();
		}
	}

	void DealWaterDamage(float dmg)
	{
		CONST_FIRE_TEMP -= dmg;

		if (CONST_FIRE_TEMP <= 0)
			Delete();
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);

		#ifndef SERVER
		if ( m_ParticleEfxSmoke )
			m_ParticleEfxSmoke.Stop();
		#else
			m_UTSource.SetActive(false);
		#endif
		DestroyAreaDamage();
	}

	override void DoEffect()
	{
		// ===============================
		// Fire effect and sound
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(GetFireEffectId(), this, GetFireEffectPosition());
		PlaySoundSetLoop( m_SoundSetLoop, GetFireSoundId(), 1.0, 2.0 );
		
		// ===============================
		// Smoke effect
        m_ParticleEfxSmoke = ParticleManager.GetInstance().PlayOnObject(GetSmokeEffectId(), this, GetSmokeEffectPosition());
		
		//calculate air resistance
		float actual_height;
		if ( GetCeilingHeight( actual_height ) )
		{
			float air_resistance = GetAirResistanceForSmokeParticles( actual_height );
			
			//alter smoke height
			m_ParticleEfxSmoke.SetParameter( -1, EmitorParam.AIR_RESISTANCE, air_resistance );
		}
		
		if ( MiscGameplayFunctions.IsUnderRoof(this) )
			m_ParticleEfxSmoke.SetParameter( -1, EmitorParam.WIND, false );
		
		#ifdef SERVER
		m_UTSSettings 					= new UniversalTemperatureSourceSettings();
		m_UTSSettings.m_UpdateInterval	= TIMER_HEATING_UPDATE_INTERVAL;
		m_UTSSettings.m_AffectStat		= true;
		m_UTSSettings.m_Updateable		= true;
		m_UTSSettings.m_TemperatureMin	= 0;
		m_UTSSettings.m_TemperatureMax	= CONST_FIRE_TEMP;
		m_UTSSettings.m_TemperatureCap	= PARAM_MAX_TRANSFERED_TEMPERATURE;
		m_UTSSettings.m_RangeFull		= PARAM_FULL_HEAT_RADIUS;
		m_UTSSettings.m_RangeMax		= PARAM_HEAT_RADIUS;
		
		m_UTSLBonfire 					= new UniversalTemperatureSourceLambdaConstant();
		m_UTSource 						= new UniversalTemperatureSource(this, m_UTSSettings, m_UTSLBonfire);
		m_UTSource.SetActive(true);
		#endif
	}

	bool GetCeilingHeight( out float actual_height )
	{
		vector from = GetPosition();
		vector to = GetPosition();
		from[1] = from[1] + 1.0;
		to[1] = to[1] + 5;
		vector contactPos;
		vector contactDir;
		int contactComponent;
		
		bool hit = DayZPhysics.RaycastRV( from, to, contactPos, contactDir, contactComponent, NULL, NULL, this );
		actual_height = vector.Distance( from, contactPos ) + 1.0;
		
		return hit;
	}
	
	float GetAirResistanceForSmokeParticles( float actual_height )
	{
		float air_res;
		actual_height = Math.Clamp( actual_height, 0, 36 );
		
		air_res = ( 6 - actual_height ) * 0.33;
		air_res = Math.Clamp( air_res, 0, 2 );
		
		return air_res;
	}
	
	//Particle Positions
	//Get local fire and smoke effect position
	protected vector GetFireEffectPosition()
	{
		return Vector( 0, 0.05, 0 );
	}
	
	protected vector GetSmokeEffectPosition()
	{
		return Vector( 0, 0.05, 0 );
	}
	
	protected int GetFireEffectId()
	{
		return -1;
	}
	
	protected int GetSmokeEffectId()
	{
		return -1;
	}
	
	protected string GetFireSoundId()
	{
		return string.Empty;
	}
};

class CW95_DynamicFire_Light: CW95_DynamicFire_Base
{
	FireplaceLight m_Light;

	void CW95_DynamicFire_Light()
	{
		CONST_FIRE_TEMP						= 400;
		PARAM_MAX_TRANSFERED_TEMPERATURE	= 15;
		PARAM_FULL_HEAT_RADIUS				= 7;
		PARAM_HEAT_RADIUS					= 15;
		CreateAreaDamage();
	}

	override protected int GetFireEffectId()
	{
		return ParticleList.CAMP_SMALL_FIRE;
	}
	
	override protected int GetSmokeEffectId()
	{
		return ParticleList.CAMP_SMALL_SMOKE;
	}
	
	override protected string GetFireSoundId()
	{
		return "LightFire_SoundSet";
	}

	override void DoEffect()
	{
		super.DoEffect();

		#ifndef SERVER
		if (!m_Light)
		{
			m_Light = FireplaceLight.Cast(ScriptedLightBase.CreateLight(FireplaceLight, Vector(0,0,0), 20));
			m_Light.AttachOnObject(this);
			m_Light.FadeBrightnessTo(m_Light.m_FireplaceBrightness, 0);
			m_Light.FadeRadiusTo(m_Light.m_FireplaceRadius, 0);
		}
		#endif
	}
	
	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		
		#ifndef SERVER
		if (m_Light)
			m_Light.FadeOut();
		#endif
	}
};

class CW95_DynamicFire_Normal: CW95_DynamicFire_Base
{
	void CW95_DynamicFire_Normal()
	{
		CONST_FIRE_TEMP						= 600;
		PARAM_MAX_TRANSFERED_TEMPERATURE	= 18;
		PARAM_FULL_HEAT_RADIUS				= 10;
		PARAM_HEAT_RADIUS					= 20;
		CreateAreaDamage();
	}

	FireplaceLight m_Light;

	override protected int GetFireEffectId()
	{
		return ParticleList.CAMP_NORMAL_FIRE;
	}
	
	override protected int GetSmokeEffectId()
	{
		return ParticleList.CAMP_NORMAL_SMOKE;
	}
	
	override protected string GetFireSoundId()
	{
		return "HeavyFire_SoundSet";
	}

	override void DoEffect()
	{
		super.DoEffect();

		#ifndef SERVER
		if (!m_Light)
		{
			m_Light = FireplaceLight.Cast(ScriptedLightBase.CreateLight(FireplaceLight, Vector(0,0,0), 20));
			m_Light.AttachOnObject(this);
			m_Light.FadeBrightnessTo(m_Light.m_FireplaceBrightness, 0);
			m_Light.FadeRadiusTo(m_Light.m_FireplaceRadius, 0);
		}
		#endif
	}
	
	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		
		#ifndef SERVER
		if (m_Light)
			m_Light.FadeOut();
		#endif
	}
};

class CW95_DynamicFire_Heavy: CW95_DynamicFire_Base
{
	BonfireLight m_Light;

	void CW95_DynamicFire_Heavy()
	{
		CONST_FIRE_TEMP						= 1000;
		PARAM_MAX_TRANSFERED_TEMPERATURE	= 25;
		PARAM_FULL_HEAT_RADIUS				= 15;
		PARAM_HEAT_RADIUS					= 30;
		CreateAreaDamage();
	}

	override protected int GetFireEffectId()
	{
		return ParticleList.BONFIRE_FIRE;
	}
	
	override protected int GetSmokeEffectId()
	{
		return ParticleList.BONFIRE_SMOKE;
	}
	
	override protected string GetFireSoundId()
	{
		return "HeavyFire_SoundSet";
	}

	override void DoEffect()
	{
		super.DoEffect();

		#ifndef SERVER
		if (!m_Light)
		{
			m_Light = BonfireLight.Cast(ScriptedLightBase.CreateLight(BonfireLight, Vector(0,0,0), 1));
			m_Light.AttachOnObject(this);
			m_Light.FadeBrightnessTo(m_Light.m_FireBrightness, 0);
			m_Light.FadeRadiusTo(m_Light.m_FireRadius, 0);
		}
		#endif
	}
	
	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		
		#ifndef SERVER
		if (m_Light)
			m_Light.FadeOut();
		#endif
	}
};
