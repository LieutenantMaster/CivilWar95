/**
 * CW95_ActionRaiseWhistleSelf.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_ActionRaiseWhistleSelfCB: ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.MEASURE_TEMP);
	}
};

class CW95_ActionRaiseWhistleSelf: ActionContinuousBase
{
	void CW95_ActionRaiseWhistleSelf()
	{
		m_CallbackClass 	= CW95_ActionRaiseWhistleSelfCB;
		m_CommandUID 		= DayZPlayerConstants.CMD_ACTIONMOD_TAKETEMPSELF;
		m_CommandUIDProne 	= DayZPlayerConstants.CMD_ACTIONFB_TAKETEMPSELF;
		m_Text 				= "#STR_CW95_ACTIONS_WHISTLE";
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem 	= new CCINonRuined;
		m_ConditionTarget 	= new CCTSelf;
	}

	override bool HasProgress()
	{
		return false;
	}

	override bool HasTarget()
	{
		return false;
	}
	
	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( player && !player.IsRestrained() )
		{
			CW95_Whistle_Base whistle = CW95_Whistle_Base.Cast( item );
			if ( whistle )
				return whistle.CanWhistle();
		}

		return false;
	}

	override void OnStartServer	( ActionData action_data )
	{
		CW95_Whistle_Base whistle = CW95_Whistle_Base.Cast( action_data.m_MainItem );
		whistle.SetCanWhistle();
	}
};
