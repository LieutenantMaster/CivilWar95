#ifdef EXPANSIONMODAI
/**
 * eAIFactionChedaki.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

[eAIRegisterFaction(eAIFactionChedaki)]
class eAIFactionChedaki: eAIFaction
{
	void eAIFactionChedaki()
	{
		m_Loadout = "ChedakiLoadout";
	}

	override bool IsFriendlyFaction(notnull eAIFaction other)
	{
		if (other.IsInherited(eAIFactionChedaki)) return true;
		if (other.IsInherited(eAIFactionMedecin)) return true;
		if (other.IsInherited(eAIFactionPompier)) return true;
		
		return false;
	}
};
#endif