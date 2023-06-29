#ifdef EXPANSIONMODAI
[eAIRegisterFaction(eAIFactionMedic)]
class eAIFactionMedic : eAIFaction
{
	void eAIFactionMedic()
	{
		m_Loadout = "SurvivorLoadout";
	}

	override bool IsFriendly(notnull eAIFaction other)
	{
		return true;
	}
};
#endif