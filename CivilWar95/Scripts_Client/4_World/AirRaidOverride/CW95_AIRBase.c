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
	protected ref TStringArray m_NameSoundSets = new TStringArray;

	void CW95_AIRBase()
	{
		SetEventMask( EntityEvent.CONTACT | EntityEvent.SIMULATE );
		SetLifetime( 7200 );

		m_NameSoundSets = new TStringArray;
		
		#ifndef SERVER
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).Call( PlayLoop );
		#endif
	}
	
	void PlayLoop()
	{
		if ( m_NameSoundSets[0] != "" )
			PlaySoundSetLoop( m_SoundLoop1, m_NameSoundSets[0], 1.0, 1.0 );

		if ( m_NameSoundSets[1] != "" )
			PlaySoundSetLoop( m_SoundLoop2, m_NameSoundSets[1], 1.0, 1.0 );

		if ( m_NameSoundSets[2] != "" )
			PlaySoundSetLoop( m_SoundLoop3, m_NameSoundSets[2], 1.0, 1.0 );
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		
		if ( GetGame() )
		{
			//! TODO: add support for lights and smokes here so we can have damaged planes for example
			if ( m_SoundLoop1 )
				StopSoundSet( m_SoundLoop1 );

			if ( m_SoundLoop2 )
				StopSoundSet( m_SoundLoop2 );

			if ( m_SoundLoop3 )
				StopSoundSet( m_SoundLoop3 );
		}
	}
};
