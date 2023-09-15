/**
 * CW95_Whistle_Base.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Whistle_Base: ItemBase
{
	protected bool m_IsWhistling;
	protected bool m_ShouldWhistle;
	
	void CW95_Whistle_Base()
	{
		RegisterNetSyncVariableBool( "m_ShouldWhistle" );
	}

	string GetLoopWhistleSoundset()
	{
		return ConfigGetString( "WhistleSoundSet" );
	}

	int GetLoopWhistleLength()
	{
		return GetGame().ConfigGetInt("WhistleLength");
	}

	int GetWhistleLengthDelay()
	{
		return GetGame().ConfigGetInt("WhistleLengthDelay");
	}

	bool ShouldWhistle()
	{
		return m_ShouldWhistle;
	}

	void StartWhistling()
	{
		m_IsWhistling = false;
		m_ShouldWhistle = true;

		SetSynchDirty();
	}

	void SetCanWhistle()
	{
		m_IsWhistling = false;
		m_ShouldWhistle = true;

		SetSynchDirty();
	}

	bool CanWhistle()
	{
		return !m_IsWhistling;
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if ( ShouldWhistle() && !m_IsWhistling )
		{
			m_IsWhistling = true;
			m_ShouldWhistle = false;

			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( PlayWhistleSound, 1000, false );
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( SetCanWhistle, GetLoopWhistleLength(), false );
		}
	}

	void PlayWhistleSound()
	{
#ifndef SERVER
		SEffectManager.PlaySound( GetLoopWhistleSoundset(), GetPosition() );
#endif
	}
	
	override void SetActions()
	{
		super.SetActions();

		AddAction(CW95_ActionRaiseWhistleSelf);
	}
};

class CW95_Whistle_Mat: CW95_Whistle_Base {};
class CW95_Whistle_Shiny: CW95_Whistle_Base {};
class CW95_Whistle_Toy: CW95_Whistle_Base {};