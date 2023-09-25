/**
 * AntibioticsMdfr.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

/*
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
*/