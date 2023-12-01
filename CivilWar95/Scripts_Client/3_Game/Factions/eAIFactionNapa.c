#ifdef EXPANSIONMODAI
/**
 * eAIFactionNapa.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

[eAIRegisterFaction(eAIFactionNapa)]
class eAIFactionNapa: eAIFaction
{
	void eAIFactionNapa()
	{
		m_Loadout = "NapaLoadout";
	}

	override bool IsFriendlyFaction(notnull eAIFaction other)
	{
		if (other.IsInherited(eAIFactionNapa)) return true;
		if (other.IsInherited(eAIFactionMedecin)) return true;
		if (other.IsInherited(eAIFactionPompier)) return true;
		
		return false;
	}
};
#endif