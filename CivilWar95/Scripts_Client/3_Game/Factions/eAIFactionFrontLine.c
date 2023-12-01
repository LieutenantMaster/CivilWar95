#ifdef EXPANSIONMODAI
/**
 * eAIFactionFrontLine.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

[eAIRegisterFaction(eAIFactionFrontLine)]
class eAIFactionFrontLine: eAIFaction
{
	void eAIFactionFrontLine()
	{
		m_Loadout = "FrontLineLoadout";
	}

	override bool IsFriendlyFaction(notnull eAIFaction other)
	{
		return other.IsInherited(eAIFactionFrontLine);
	}
};
#endif