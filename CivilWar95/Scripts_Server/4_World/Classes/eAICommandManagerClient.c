/**
 * DayZExpansion.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

#ifdef EXPANSIONMODAI
modded class eAICommandManagerClient
{
	override eAIBase SpawnAI_Helper(PlayerBase owner, string loadout = "HumanLoadout.json")
	{
		eAIGroup group = eAIGroup.GetGroupByLeader(owner);
		eAIFormation form = group.GetFormation();
		vector pos = ExpansionAISpawnBase.GetPlacementPosition(form.ToWorld(form.GetPosition(group.Count())));

		if ( loadout == "HumanLoadout.json" )
			loadout = group.GetFaction().GetDefaultLoadout();

		eAIBase ai = SpawnAIEx(pos, loadout);

		if (ai)
		{
			ai.SetGroup(group);
			ai.Expansion_SetCanBeLooted(false);
		}

		return ai;
	}
};
#endif