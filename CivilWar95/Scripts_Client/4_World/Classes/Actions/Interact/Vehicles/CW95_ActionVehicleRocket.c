/**
 * CW95_ActionVehicleRocket.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_ActionVehicleRocket: ActionInteractBase
{
	void CW95_ActionVehicleRocket()
	{
		m_CommandUID		= DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask		= DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon	 	= CursorIcons.LootCorpse;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem 	= new CCINone;
		m_ConditionTarget 	= new CCTNone;
	}	

	override string GetText()
	{
		return "#rocket";
	}

	override typename GetInputType()
	{
		return CW95VehicleInputRocket;
	}

	override bool HasTarget()
	{
		return false;
	}
	
	override bool CanBeUsedInVehicle()
	{
		return true;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		HumanCommandVehicle vehCommand;
		if ( !Class.CastTo( vehCommand, player.GetCommand_Vehicle() ) )
			return false;

		CarScript car;
		if ( !Class.CastTo( car, vehCommand.GetTransport() ) )
			return false;

		if ( car.HasArmement() )
			return car.CanFireFromSeatIndex( player );

		return false;
	}
};
