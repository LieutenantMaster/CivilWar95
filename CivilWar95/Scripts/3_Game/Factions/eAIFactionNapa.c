#ifdef EXPANSIONMODAI
[eAIRegisterFaction(eAIFactionNapa)]
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

class eAIFactionNapa: eAIFaction
{
	void eAIFactionNapa()
	{
		m_Loadout = "NapaLoadout";
	}

	override bool IsFriendly(notnull eAIFaction other)
	{
		if (other.IsInherited(eAIFactionNapa)) return true;
		if (other.IsInherited(eAIFactionMedic)) return true;
		
		return false;
	}
};
#endif