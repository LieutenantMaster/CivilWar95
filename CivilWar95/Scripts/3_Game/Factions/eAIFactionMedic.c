#ifdef EXPANSIONMODAI
[eAIRegisterFaction(eAIFactionMedic)]
class eAIFactionMedic : eAIFaction
{
	void eAIFactionMedic()
	{
		m_Loadout = "MedicLoadout";
	}

	override bool IsFriendly(notnull eAIFaction other)
	{
		return true;
	}
};
#endif