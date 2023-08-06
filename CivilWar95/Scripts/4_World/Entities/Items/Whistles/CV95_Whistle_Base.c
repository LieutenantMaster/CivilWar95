/**
 * CV95_Whistle_Base.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

//! TODO: this code is 4 years old, need serious refactoring
class CV95_Whistle_Base: ItemBase
{
	ref protected EffectSound 		m_WhistleLoopSound;
	protected bool 					m_Whistling;
	protected float 				m_WhistleTime;

	string GetLoopWhistleSoundset() { return "CV95_Whistle_01_SoundSet"; }
	float GetLoopWhistleLenght() 	{ return 1531; }
	float GetWhistleLenghtDelay() 	{ return 3531; }

	void SetCanWhistle(bool onOff) 	{ m_Whistling = onOff; Synchronize(); }
	void SwitchWhistleState() 		{ m_Whistling = !m_Whistling; Synchronize(); }
	bool CanWhistle() 				{ return m_Whistling; }
	
	void CV95_Whistle_Base()
	{
		m_WhistleTime 		= GetLoopWhistleLenght();
		m_Whistling 		= false;

		RegisterNetSyncVariableBool( "m_Whistling" );
		RegisterNetSyncVariableFloat( "m_WhistleTime" );
	}
	
	void ~CV95_Whistle_Base()
	{
		if ( m_WhistleLoopSound )
			SEffectManager.DestroySound( m_WhistleLoopSound );
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if ( CanWhistle() )
			InitWhistleLoop();
		
		if ( m_WhistleLoopSound && !CanWhistle() )
			StopWhistleSound();
	}
	
	// --- SYNCHRONIZATION
	void Synchronize()
	{
		if ( GetGame().IsServer() )
			SetSynchDirty();
	}

	void InitWhistleLoop()
	{
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( PlayWhistleSound, 1000, false );

		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( StopWhistleSound, m_WhistleTime, false );
	}

	void PlayWhistleSound()
	{
		if ( m_WhistleLoopSound )
			StopWhistleSound();
		else
			m_WhistleLoopSound 	= new EffectSound;
		//if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		//{
			m_WhistleLoopSound = SEffectManager.PlaySound( GetLoopWhistleSoundset(), GetPosition() );
			m_WhistleLoopSound.SetSoundAutodestroy( true );
			m_WhistleLoopSound.SetSoundLoop( false );
		//}
	}

	void StopWhistleSound()
	{
		//if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		//{
			m_WhistleLoopSound.SetSoundFadeOut(0.5);
			m_WhistleLoopSound.SoundStop();
		//}
	}
	
	override void SetActions()
	{
		super.SetActions();

		AddAction(CV95_ActionRaiseWhistleSelf);
	}	
}
