/**
 * CW95_AIRBase.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_AIRBase: ItemBase
{
	protected EffectSound m_SoundLoop1;
	protected EffectSound m_SoundLoop2;
	protected EffectSound m_SoundLoop3;
	protected ref TStringArray m_NameSoundSets;
	
	protected Particle m_Particle1;
	protected Particle m_Particle2;
	protected Particle m_Particle3;
	protected ref TIntArray m_NameParticles;

	void CW95_AIRBase()
	{
		SetEventMask( EntityEvent.CONTACT | EntityEvent.SIMULATE );
		SetLifetime( 7200 );

		m_NameSoundSets = new TStringArray;
		m_NameParticles = new TIntArray;
		
		#ifndef SERVER
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).Call( PlayLoop );
		#endif
	}
	
	void PlayLoop()
	{
		if ( m_NameSoundSets[0] != string.Empty )
			PlaySoundSetLoop( m_SoundLoop1, m_NameSoundSets[0], 1.0, 1.0 );

		if ( m_NameSoundSets[1] != string.Empty )
			PlaySoundSetLoop( m_SoundLoop2, m_NameSoundSets[1], 1.0, 1.0 );

		if ( m_NameSoundSets[2] != string.Empty )
			PlaySoundSetLoop( m_SoundLoop3, m_NameSoundSets[2], 1.0, 1.0 );
		
		//! TODO: allow pos offset in the futur
		if ( m_NameParticles[0] )
			m_Particle1 = Particle.PlayOnObject(m_NameParticles[0], this);

		if ( m_NameParticles[1] )
			m_Particle2 = Particle.PlayOnObject(m_NameParticles[1], this);

		if ( m_NameParticles[2] )
			m_Particle3 = Particle.PlayOnObject(m_NameParticles[2], this);
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		
		if ( GetGame() )
		{
			if ( m_SoundLoop1 )
				StopSoundSet( m_SoundLoop1 );

			if ( m_SoundLoop2 )
				StopSoundSet( m_SoundLoop2 );

			if ( m_SoundLoop3 )
				StopSoundSet( m_SoundLoop3 );
			
			if ( m_Particle1 )
			{
				m_Particle1.Stop();
				GetGame().ObjectDelete(m_Particle1);
			}
			
			if ( m_Particle2 )
			{
				m_Particle2.Stop();
				GetGame().ObjectDelete(m_Particle2);
			}
			
			if ( m_Particle3 )
			{
				m_Particle3.Stop();
				GetGame().ObjectDelete(m_Particle3);
			}
		}
	}
};
