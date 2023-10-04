/**
 * ExpansionActionOpenTraderMenu.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

#ifdef EXPANSIONMODMARKET
modded class ExpansionActionOpenTraderMenu
{
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor(UAMaxDistances.LARGE);
	}
	
	override void OnStartClient(ActionData action_data)
	{
		super.OnStartClient(action_data);

		PlayerBase player = action_data.m_Player;
		if ( player )
			player.SetPlayerAtZeleno(vector.Distance(player.GetPosition(), Vector(2640, 200, 5170)) <= 500);
	}
};
#endif