/**
 * MPFP_VolumeDOWNAction.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class MPFP_VolumeDOWNActionCB: ActionContinuousBaseCB
{
	private const float REPEAT_AFTER_SEC = 0.3;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(REPEAT_AFTER_SEC);
	}
};

class MPFP_VolumeDOWNAction: ActionContinuousBase
{
	void MPFP_VolumeDOWNAction()
	{
		m_CallbackClass = MPFP_VolumeDOWNActionCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ITEM_TUNE;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_ITEM_TUNE;		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
		
		m_Text = "#STR_CW95_ACTIONS_VOLUME_DOWN";
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNone;
		m_ConditionItem = new CCINonRuined;
	}
	
	override bool HasProneException()
	{
		return true;
	}

	override bool HasTarget()
	{
		return false;
	}

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		CW95_MusicPlayer mPlayer;
		if ( Class.CastTo(mPlayer, CW95_MusicPlayer.Cast( item ) ) )
		{
			float volume = mPlayer.GetVolume() * 100;
			m_Text = "#STR_CW95_ACTIONS_VOLUME_DOWN (" + volume + "%)";
		}
	}

	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		CW95_MusicPlayer mPlayer;
		if ( Class.CastTo(mPlayer, CW95_MusicPlayer.Cast( item ) ) )
			return true;
		
		return false;
	}
};
