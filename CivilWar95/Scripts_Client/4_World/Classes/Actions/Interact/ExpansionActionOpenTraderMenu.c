#ifdef EXPANSIONDMODMARKET
modded class ExpansionActionOpenTraderMenu
{
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor(4.0);
	}
};
#endif