/**
 * Environment.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class Environment
{
	protected static float m_WindMultiplier = 8.5; 		//! Default is 8.5 	| Wind 			| They are multipliers !
	protected static float m_RainMultiplier = 0.8; 		//! Default is 1.0 	| Rain 			| They are multipliers !
	
	// Calculates and return temperature of environment
	override protected float GetEnvironmentTemperature()
	{
		if ( IsWaterContact() || IsInsideBuilding() || IsUnderRoof() )
			return super.GetEnvironmentTemperature();

		float temperature;
		temperature = g_Game.GetMission().GetWorldData().GetBaseEnvTemperature();
		temperature += Math.AbsFloat( temperature * ( m_Clouds * GameConstants.ENVIRO_CLOUDS_TEMP_EFFECT ) );	//! Sun heating you
		temperature -= m_WindMultiplier * ( GetWindModifierPerSurface() * m_Wind );								//! Wind
		temperature -= Math.AbsFloat( temperature * ( m_Fog * GameConstants.ENVIRO_FOG_TEMP_EFFECT ) );			//! Fog
		
		if (m_HeatSourceTemp > temperature)
			temperature = temperature + m_HeatSourceTemp;
		
		return temperature;
	}
};
