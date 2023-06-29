[eAIRegisterFaction(eAIFactionChedaki)]
class eAIFactionChedaki : eAIFaction
{
	void eAIFactionChedaki()
	{
		m_Loadout = "EastLoadout";
	}

	override bool IsFriendly(notnull eAIFaction other)
	{
		if (other.IsInherited(eAIFactionChedaki)) return true;
		if (other.IsInherited(eAIFactionMedic)) return true;
		
		return false;
	}
};