#ifdef EXPANSIONMODAI
[eAIRegisterFaction(eAIFactionNapa)]
class eAIFactionNapa : eAIFaction
{
	void eAIFactionNapa()
	{
		m_Loadout = "EastLoadout";
	}

	override bool IsFriendly(notnull eAIFaction other)
	{
		if (other.IsInherited(eAIFactionNapa)) return true;
		if (other.IsInherited(eAIFactionMedic)) return true;
		
		return false;
	}
};
#endif