/**
 * CV95_ActionKnockAtDoor.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

//! TODO: this code is 4 years old, need serious refactoring
class CV95_ActionKnockAtDoorCB: ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT_CONSTRUCT);
	}
};

class CV95_ActionKnockAtDoor: ActionContinuousBase
{
	void CV95_ActionKnockAtDoor()
	{
		m_CallbackClass 	= CV95_ActionKnockAtDoorCB;
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
		
		if( !IsBuilding(target) )
			return false;

		BuildingBase building;
		if( Class.CastTo(building, target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(target.GetComponentIndex());
			if ( doorIndex != -1 )
			{
				return ( !building.IsDoorOpen(doorIndex) );
			}
		}

		return false;
	}

	override void OnStartServer	( ActionData action_data ) 	{ OnAction(action_data, true); }
	override void OnStartClient	( ActionData action_data ) 	{ OnAction(action_data, true); }
	override void OnEndServer	( ActionData action_data ) 	{ OnAction(action_data, false); }
	override void OnEndClient	( ActionData action_data ) 	{ OnAction(action_data, false); }
	override void Interrupt		( ActionData action_data ) 	{ OnAction(action_data, false); super.Interrupt( action_data ); }
	
	void OnAction( ActionData action_data, bool onOff )
	{
		BuildingBase building;
		if( Class.CastTo(building, action_data.m_Target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(action_data.m_Target.GetComponentIndex());
			if( doorIndex != -1 )
			{
				if( onOff )
				{
					building.StartKnocking(doorIndex);
				} else {
					building.StopKnocking();
				}
			}
		}
	}	
};