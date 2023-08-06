/**
 * CV95_ActionRaiseWhistleSelf.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

//! TODO: this code is 4 years old, need serious refactoring
class CV95_ActionRaiseWhistleSelfCB: ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.MEASURE_TEMP);
	}
};

class CV95_ActionRaiseWhistleSelf: ActionContinuousBase
{
	void CV95_ActionRaiseWhistleSelf()
	{
		m_CallbackClass 	= CV95_ActionRaiseWhistleSelfCB;
		m_CommandUID 		= DayZPlayerConstants.CMD_ACTIONMOD_TAKETEMPSELF;
		m_CommandUIDProne 	= DayZPlayerConstants.CMD_ACTIONFB_TAKETEMPSELF;
		m_Text 				= "#STR_CW95_ACTIONS_WHISTLE";
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem 	= new CCINonRuined;
		m_ConditionTarget 	= new CCTSelf;
	}

	override bool HasProgress() { return false; }
	
	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item ) { return !player.IsRestrained(); }

	override void OnStartServer	( ActionData action_data ) 	{ OnAction(action_data, true);  }
	override void OnStartClient	( ActionData action_data ) 	{ OnAction(action_data, true);  }
	override void OnEndServer	( ActionData action_data ) 	{ OnAction(action_data, false); }
	override void OnEndClient	( ActionData action_data ) 	{ OnAction(action_data, false); }

	void OnAction( ActionData action_data, bool onOff )
	{
		CV95_Whistle_Base CV95_Whistle = CV95_Whistle_Base.Cast( action_data.m_MainItem );
		CV95_Whistle.SetCanWhistle( onOff );

		if( onOff )
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( CV95_Whistle.SwitchWhistleState, CV95_Whistle.GetWhistleLenghtDelay(), false );
	}
	
	override void Interrupt(ActionData action_data)
	{
		CV95_Whistle_Base CV95_Whistle = CV95_Whistle_Base.Cast( action_data.m_MainItem );
		CV95_Whistle.SetCanWhistle( false );

		super.Interrupt( action_data );
	}
	
	override protected bool CanContinue( ActionData action_data )
	{
		CV95_Whistle_Base CV95_Whistle = CV95_Whistle_Base.Cast( action_data.m_MainItem );
		return CV95_Whistle.CanWhistle();
	}
}