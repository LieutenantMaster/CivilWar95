#ifdef EXPANSIONMODAI
/**
 * eAIFactionMafia.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

[eAIRegisterFaction(eAIFactionMafia)]
class eAIFactionMafia: eAIFaction
{
	void eAIFactionMafia()
	{
		m_Loadout = "MafiaLoadout";
	}

	override bool IsFriendlyFaction(notnull eAIFaction other)
	{
		if (other.IsInherited(eAIFactionMafia)) return true;
		if (other.IsInherited(eAIFactionMedecin)) return true;
		if (other.IsInherited(eAIFactionPompier)) return true;
		
		return false;
	}
};
#endif