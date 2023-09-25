/**
 * CW95_ActionVehicleFlare.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class CW95_ActionVehicleFlare
{
	override void OnExecuteServer( ActionData action_data )
	{
		HumanCommandVehicle vehCommand = action_data.m_Player.GetCommand_Vehicle();
		if ( vehCommand )
		{
			Transport trans = vehCommand.GetTransport();
			if ( trans )
			{
				CarScript car;
				if ( Class.CastTo(car, trans) )
				{
					m_Flares = 0;

					m_FlareTimer.Run( 0.1, this, "SpawnFlare", NULL, true ); 
				}
			}
		}
	}
};
