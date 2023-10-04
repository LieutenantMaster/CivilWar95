/**
 * MPFP_Play.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class MPFP_PlayCB: ActionBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAInteract;
	}
};

class MPFP_Play: AnimatedActionBase
{
	void MPFP_Play()
	{
		m_CallbackClass = MPFP_PlayCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ITEM_ON;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONMOD_ITEM_ON;		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
		
		m_Text = "#STR_CW95_ACTIONS_PLAY";
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
		CW95_MusicPlayer mPlayer;
		if ( Class.CastTo(mPlayer, CW95_MusicPlayer.Cast( item ) ) )
			return mPlayer.CanPlay();
		
		return false;
	}
};
