/**
 * CW95_ActionKnockAtDoor.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_ActionKnockAtDoor: ActionSingleUseBase
{
	void CW95_ActionKnockAtDoor()
	{
		m_FullBody = false;
		m_CommandUID 		= DayZPlayerConstants.CMD_ACTIONFB_HANDCUFFTARGET;
		m_CommandUIDProne 	= DayZPlayerConstants.CMD_ACTIONFB_HANDCUFFTARGET;
		m_Text 				= "#STR_CW95_ACTIONS_KNOCK";
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem 	= new CCINone;
		m_ConditionTarget 	= new CCTCursor;
	}

	override bool HasProgress()
	{
		return false;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{		
		if( !target )
			return false;

		Fence basebuilding;
		BuildingBase building;
		if( Class.CastTo(basebuilding, target.GetObject()) )
		{
			if ( basebuilding.HasHinges() )
				return !basebuilding.IsOpened();
		}
		else if( Class.CastTo(building, target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(target.GetComponentIndex());
			if ( doorIndex != -1 )
				return !building.IsDoorOpen(doorIndex);
		}
		
		#ifdef SERVER
		return true;
		#endif
		
		return false;
	}
	
	override void OnExecuteServer( ActionData action_data)
	{
		Print("OnExecuteServer !!!! ");
		Fence basebuilding;
		BuildingBase building;
		if( Class.CastTo(basebuilding, action_data.m_Target.GetObject()) )
		{
			basebuilding.KnockAtDoor();
		}
		else if( Class.CastTo(building, action_data.m_Target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(action_data.m_Target.GetComponentIndex());
			Print("doorIndex is "+ doorIndex);
			if( doorIndex != -1 )
				building.KnockAtDoor(doorIndex);
		}
	}
};