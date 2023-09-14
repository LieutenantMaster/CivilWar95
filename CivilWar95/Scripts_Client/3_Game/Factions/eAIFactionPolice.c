#ifdef EXPANSIONMODAI
/**
 * eAIFactionPolice.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

[eAIRegisterFaction(eAIFactionPolice)]
class eAIFactionPolice: eAIFaction
{
	void eAIFactionPolice()
	{
		m_Loadout = "PoliceLoadout";
	}

	override bool IsFriendly(notnull eAIFaction other)
	{
		if (other.IsInherited(eAIFactionPolice)) return true;
		if (other.IsInherited(eAIFactionMedecin)) return true;
		if (other.IsInherited(eAIFactionPompier)) return true;
		
		return false;
	}
};
#endif