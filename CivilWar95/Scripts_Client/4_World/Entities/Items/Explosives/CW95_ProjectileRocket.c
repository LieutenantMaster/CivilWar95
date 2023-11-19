/**
 * CW95_ProjectileRocket.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_ProjectileRocket: CW95_Projectile_Base
{
	EffectSound m_Sound;
	EffectSound m_ExplosionSound;
	
	protected Particle m_ParticleEfx;
	ExpansionPointLight m_FlareLight;
	ExpansionPointLight m_RocketLight;

	void CW95_ProjectileRocket()
	{
		SetAmmoType("CW95_ProjectileRocket_Ammo");
		SetParticleExplosion(ParticleList.PLASTIC_EXPLOSION);
	}

#ifndef SERVER
	void ~CW95_ProjectileRocket()
	{
		if ( m_ParticleEfx )
		{
			m_ParticleEfx.Stop();
			GetGame().ObjectDelete(m_ParticleEfx);
		}

		if ( m_Sound ) 
			m_Sound.SoundStop();

		if ( m_FlareLight )
			GetGame().ObjectDelete( m_FlareLight );

		if ( m_RocketLight )
			GetGame().ObjectDelete( m_RocketLight );
	}
#endif

	override void CW95_ClientEarlyStartEffect()
	{
		m_Sound = SEffectManager.PlaySound("Expansion_RPG_Shot_SoundSet", GetPosition());
		m_Sound.SetAutodestroy( true );

		m_ParticleEfx = Particle.PlayOnObject(ParticleList.EXPANSION_ROCKET_SMOKE, this);
	}
	
	override void CW95_ClientStartEffect()
	{
		if ( !m_FlareLight )
		{
			m_FlareLight = ExpansionPointLight.Cast( ScriptedLightBase.CreateLight( ExpansionPointLight, Vector( 0, 0, 0 ) )  ); 

			m_FlareLight.SetDiffuseColor( 1, 1, 1 );
			m_FlareLight.SetPosition( GetPosition() );
			m_FlareLight.SetRadiusTo( 10 );
			m_FlareLight.SetBrightnessTo( 1 ); 
			m_FlareLight.AttachOnObject( this, "0 0 0" );
		}
	}

	override void CW95_ClientEndEffect()
	{
		if ( m_ParticleEfx )
			m_ParticleEfx.Stop();

		if ( m_Sound ) 
			m_Sound.SoundStop();

		SEffectManager.PlaySound( "Expansion_Explosive_Large_SoundSet", GetPosition() );

		m_RocketLight = ExpansionPointLight.Cast( ScriptedLightBase.CreateLight( ExpansionPointLight, Vector( 0, 0, 0 ) ) ); 

		m_RocketLight.SetDiffuseColor( 1, 0.25, 0 );
		m_RocketLight.SetPosition( GetPosition() );
		m_RocketLight.SetRadiusTo( 60 );
		m_RocketLight.SetBrightnessTo( 4.5 ); 
		m_RocketLight.SetLifetime( 0.1 );
		m_RocketLight.SetFadeOutTime( 0.1 );
		m_RocketLight.SetFlareVisible( false );

		float distance_to_player = vector.Distance(GetPosition(), GetGame().GetPlayer().GetPosition());
		float strength_factor = Math.InverseLerp(GameConstants.CAMERA_SHAKE_GRENADE_DISTANCE, 0, distance_to_player);
		GetGame().GetPlayer().GetCurrentCamera().SpawnCameraShake(strength_factor / 8);

		vector n = GetPosition().VectorToAngles();

		Particle p1 = Particle.Play(ParticleList.IMPACT_DIRT_RICOCHET, GetPosition() );
		p1.SetOrientation(n);
		
		Particle p2 = Particle.Play(ParticleList.IMPACT_GRAVEL_RICOCHET, GetPosition() );
		p2.SetOrientation(n);

		Particle p3 = Particle.Play(ParticleList.IMPACT_METAL_RICOCHET, GetPosition() );
		p3.SetOrientation(n);
	}
};
