/**
 * CW95VehicleInputRocket.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95VehicleInputRocket : DefaultActionInput
{	
	ref ActionTarget target_new;

	void CW95VehicleInputRocket( PlayerBase player )
	{
		SetInput( "UACW95VehicleRocket" );
		
		m_InputType = ActionInputType.AIT_CONTINUOUS;
		//m_DetectFromTarget = true;
	}
	
	/*
	override void UpdatePossibleActions( PlayerBase player, ActionTarget target, ItemBase item, int action_condition_mask )
	{
		if ( ForceActionCheck(player) )
		{
			m_SelectAction = m_ForcedActionData.m_Action;
			return;
		}
 
		m_SelectAction = NULL;
		array<ActionBase_Basic> possible_actions;
		ActionBase action;
		int i;

		if ( player && player.IsInVehicle() )
		{
			HumanCommandVehicle vehCommand = player.GetCommand_Vehicle();
			if ( vehCommand )
			{
				Transport trans = vehCommand.GetTransport();
				if ( CarScript.Cast( trans ) )
				{
					target_new = new ActionTarget(trans, null, -1, vector.Zero, -1);
					ForceActionTarget( target_new );
				}
			}
			
			if ( !target_new )
				ClearForcedTarget();
		}

		target = m_ForcedTarget;
		m_Target = m_ForcedTarget;
		
		if ( target && target.GetObject() )
		{
			target.GetObject().GetActions(Type(), possible_actions);
			if ( possible_actions )
			{
				for ( i = 0; i < possible_actions.Count(); i++)
				{
					action = ActionBase.Cast(possible_actions.Get(i));
					if ( action.Can(player, target, m_MainItem, action_condition_mask) )
					{
						m_SelectAction = action;
						return;
					}
				}
			}
		}
	}
	*/
};
