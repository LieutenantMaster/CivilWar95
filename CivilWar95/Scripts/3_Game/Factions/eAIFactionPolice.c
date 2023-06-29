#ifdef EXPANSIONMODAI
[eAIRegisterFaction(eAIFactionPolice)]
class eAIFactionPolice : eAIFaction
{
	void eAIFactionPolice()
	{
		m_Loadout = "PoliceLoadout";
	}

	override bool IsFriendly(notnull eAIFaction other)
	{
		if (other.IsInherited(eAIFactionPolice)) return true;
		if (other.IsInherited(eAIFactionMedic)) return true;
		
		return false;
	}
};
#endif