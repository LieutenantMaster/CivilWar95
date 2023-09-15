/**
 * ExpansionActionChangeCodeLock.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2022 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

/*
#ifdef EXPANSIONMODBASEBUILDING
modded class ExpansionActionChangeCodeLock
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !super.ActionCondition(player, target, item) )
			return false;

		if ( !player || !player.GetIdentity() )
			return false;
		
		Print(" m_Target.CW95_GetOriginalCodeOwner() is " + m_Target.CW95_GetOriginalCodeOwner());
		Print(" player.GetIdentityUID() is " + player.GetIdentityUID());
		if ( player.GetIdentityUID() == m_Target.CW95_GetOriginalCodeOwner() )
			return true;
		
		return false;
	}
};
#endif
*/