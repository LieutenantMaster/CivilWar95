#ifdef EXPANSIONMODAI
[eAIRegisterFaction(eAIFactionFrontLine)]
class eAIFactionFrontLine : eAIFaction
{
	void eAIFactionFrontLine()
	{
		m_Loadout = "FrontLineLoadout";
	}

	override bool IsFriendly(notnull eAIFaction other)
	{
		return other.IsInherited(eAIFactionFrontLine);
	}
};
#endif