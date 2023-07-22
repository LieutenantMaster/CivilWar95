modded class AntibioticsMdfr
{
	float m_RegenTime;
	
	const float ANTIBIOTICS_STRENGTH = 1;
	
	override void Init()
	{
		m_TrackActivatedTime = true;
		m_IsPersistent = true;
		m_ID 					= eModifiers.MDF_ANTIBIOTICS;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 3;
		m_RegenTime = GetExpansionSettings().GetCV95().AntibioticsDuration;
	}	

	override void OnTick(PlayerBase player, float deltaT)
	{
		player.AddHealth("","",(GetExpansionSettings().GetCV95().TotalAntibioticsHealth / m_RegenTime));
		player.AntibioticsAttack( ANTIBIOTICS_STRENGTH * deltaT );
	}
};