#ifdef EXPANSIONMODAI
[eAIRegisterFaction(eAIFactionMafia)]
class eAIFactionMafia : eAIFaction
{
	void eAIFactionMafia()
	{
		m_Loadout = "MafiaLoadout";
	}

	override bool IsFriendly(notnull eAIFaction other)
	{
		if (other.IsInherited(eAIFactionMafia)) return true;
		if (other.IsInherited(eAIFactionMedic)) return true;
		
		return false;
	}
};
#endif