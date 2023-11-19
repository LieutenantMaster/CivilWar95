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

#ifndef SERVER
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !super.ActionCondition(player, target, item) )
			return false;

		ExpansionTraderNPCBase trader = ExpansionTraderNPCBase.Cast(target.GetObject());

		if ( trader && trader.HasWhitlist() )
			return trader.IsWhistelisted(player.GetIdentity().GetId());

		return true;
	}
#endif
	
	override void OnStartClient(ActionData action_data)
	{
		super.OnStartClient(action_data);

		PlayerBase player = action_data.m_Player;
		if ( player )
			player.SetPlayerAtZeleno(vector.Distance(player.GetPosition(), Vector(2640, 200, 5170)) <= 500);
	}
};
#endif