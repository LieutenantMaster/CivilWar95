#ifdef EXPANSIONMODAI
[eAIRegisterFaction(eAIFactionMedic)]
/**
 * eAIFactionMedic.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class eAIFactionMedic: eAIFaction
{
	void eAIFactionMedic()
	{
		m_Loadout = "MedicLoadout";
	}

	override bool IsFriendly(notnull eAIFaction other)
	{
		return true;
	}
};
#endif