/**
 * CW95_RemoveLodgedBullet.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_RemoveLodgedBulletCB: ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.SEW_WOUNDS);
	}
};

class CW95_RemoveLodgedBullet: ActionContinuousBase
{
	void CW95_RemoveLodgedBullet()
	{
		m_CallbackClass 	= CW95_RemoveLodgedBulletCB;
		m_SpecialtyWeight 	= UASoftSkillsWeight.PRECISE_MEDIUM;
		m_CommandUID 		= DayZPlayerConstants.CMD_ACTIONFB_BANDAGETARGET;
		m_FullBody 			= true;
		m_StanceMask 		= DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text 				= "#STR_CW95_ACTIONS_REMOVELODGEDBULLET";
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem 	= new CCINone;
		m_ConditionTarget 	= new CCTMan(UAMaxDistances.DEFAULT);
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		#ifndef DIAG 
		return false;
		#endif

		PlayerBase otherPlayer = PlayerBase.Cast(target.GetObject());
		if (otherPlayer)
        {
			//if (otherPlayer.IsWounded())
            //    return otherPlayer.FindWoundType(CW95_WoundTypes.Bullet);
        }

		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		if ( !action_data.m_Player.GetItemOnSlot("Gloves") )
			action_data.m_Player.HasBloodyHands();

		PlayerBase ntarget = PlayerBase.Cast(action_data.m_Target.GetObject());
		if (CanReceiveAction(action_data.m_Target))
		{
			if (ntarget.GetBleedingManagerServer() )
				ntarget.GetBleedingManagerServer().RemoveMostSignificantBleedingSourceEx(action_data.m_MainItem);

			action_data.m_MainItem.DecreaseHealth ( "", "", 2 );	
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		}
	}
};
