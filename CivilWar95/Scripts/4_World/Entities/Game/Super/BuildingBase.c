
/**
 * BuildingBase.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

//! TODO: this code is 4 years old, need a serious rewrite
modded class BuildingBase
{
	ref protected EffectSound 		m_KnockingLoopSound;
	protected bool 					m_knockstate;
	protected int 					m_index;

	string GetLoopKnockingSoundset()
	{
		return "CV95_Knocking_SoundSet";
	}
	
	void BuildingBase()
	{
		m_knockstate 		= false;
		m_index 			= -1;

		RegisterNetSyncVariableBool( "m_knockstate" );
		RegisterNetSyncVariableInt( "m_index" );
	}

	void ~BuildingBase()
	{
		if ( m_KnockingLoopSound )
			SEffectManager.DestroySound( m_KnockingLoopSound );
	}
	void StartKnocking(int index) 		
	{
		m_knockstate = true;
		m_index = index;
		
		if ( GetGame().IsServer() )
			SetSynchDirty();
	}

	void StopKnocking() 				
	{
		m_knockstate = false;

		if ( GetGame().IsServer() )
			SetSynchDirty();
	}

	bool IsKnocking() 					
	{
		return m_knockstate;
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

#ifndef SERVER
		if ( IsKnocking() )
			PlayKnockingSound(m_index);
		else
			StopKnockingSound();
#endif
	}

	void PlayKnockingSound(int index)
	{
		if ( !m_KnockingLoopSound )
			m_KnockingLoopSound = new EffectSound;
		
		m_KnockingLoopSound = SEffectManager.PlaySound( GetLoopKnockingSoundset(), GetDoorSoundPos(index) );
		m_KnockingLoopSound.SetSoundAutodestroy( true );
		m_KnockingLoopSound.SetSoundLoop( true );
	}

	void StopKnockingSound()
	{
		m_KnockingLoopSound.SetSoundFadeOut(0.1);
		m_KnockingLoopSound.SoundStop();
	}
};