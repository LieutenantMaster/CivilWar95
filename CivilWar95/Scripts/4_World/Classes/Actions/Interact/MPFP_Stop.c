/**
 * MPFP_Stop.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class MPFP_StopCB: ActionBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAInteract;
	}
};

class MPFP_Stop: AnimatedActionBase
{
	void MPFP_Stop()
	{
		m_CallbackClass = MPFP_StopCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ITEM_OFF;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONMOD_ITEM_OFF;		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
		
		m_Text = "#STR_CW95_ACTIONS_STOP";
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNone;
		m_ConditionItem = new CCINonRuined;
	}

	override bool HasProgress()
	{
		return false;
	}
	
	override bool HasProneException()
	{
		return true;
	}

	override bool HasTarget()
	{
		return false;
	}

	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		CV95_MusicPlayer mPlayer;
		if ( Class.CastTo(mPlayer, CV95_MusicPlayer.Cast( item ) ) )
			return mPlayer.IsBusy();
		
		return false;
	}

	override void OnEndServer( ActionData action_data )
	{	
		CV95_MusicPlayer mPlayer = CV95_MusicPlayer.Cast( action_data.m_MainItem );
		if( mPlayer )
			mPlayer.StopAllActions();
	}

	override void OnEndClient( ActionData action_data )
	{	
		CV95_MusicPlayer mPlayer = CV95_MusicPlayer.Cast( action_data.m_MainItem );
		if( mPlayer )
			mPlayer.StopAllActions();
	}
}