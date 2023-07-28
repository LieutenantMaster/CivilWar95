modded class AntibioticsMdfr
{
	float m_RegenTime;
	
	const float ANTIBIOTICS_STRENGTH = 1;
	
	override void Init()
	{
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= true;
		m_ID 					= eModifiers.MDF_ANTIBIOTICS;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 3;
		m_RegenTime 			= 60;
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		player.AddHealth("","",(35 / m_RegenTime));
		player.AntibioticsAttack( ANTIBIOTICS_STRENGTH * deltaT );
	}
};