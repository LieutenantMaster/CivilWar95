[eAIRegisterFaction(eAIFactionMafia)]
class eAIFactionMafia : eAIFaction
{
	void eAIFactionMafia()
	{
		m_Loadout = "CivilianLoadout";
	}

	override bool IsFriendly(notnull eAIFaction other)
	{
		if (other.IsInherited(eAIFactionMafia)) return true;
		if (other.IsInherited(eAIFactionMedic)) return true;
		
		return false;
	}
};