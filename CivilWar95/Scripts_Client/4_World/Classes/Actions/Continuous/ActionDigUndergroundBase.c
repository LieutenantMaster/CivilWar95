/**
 * ActionDigUndergroundBase.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

#ifndef DIAG
modded class ActionDigUndergroundBase
{
	override string GetText()
	{
		return "#STR_CW95_ACTIONS_DIGHOLE";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( player.IsPlacingLocal() )
			return false;

		WatchtowerKit blueprint;
		if( !Class.CastTo(blueprint, target.GetObject()) )
			return false;

        vector playerPos = player.GetPosition();
        //Temp fix till can think of something better
		if (playerPos[1] > UNDERGOUNDBASE_OFFESETHEIGHT_MIN )
			return false;

        vector kitpos = ExpansionStatic.GetSurfacePosition(blueprint.GetPosition());
		string surface_type;
		GetGame().SurfaceGetType3D( kitpos[0], kitpos[1], kitpos[2], surface_type );

		return GetGame().IsSurfaceDigable(surface_type);
	}
};
#endif