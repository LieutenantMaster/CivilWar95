[eAIRegisterFaction(eAIFactionMilitaire)]
class eAIFactionMilitaire : eAIFaction
{
	void eAIFactionMilitaire()
	{
		m_Loadout = "WestLoadout";
	}

	override bool IsFriendly(notnull eAIFaction other)
	{
		if (other.IsInherited(eAIFactionPolice)) return true;
		if (other.IsInherited(eAIFactionMilitaire)) return true;
		if (other.IsInherited(eAIFactionMedic)) return true;
		
		return false;
	}
};