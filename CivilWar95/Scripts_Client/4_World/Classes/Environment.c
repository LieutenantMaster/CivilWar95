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
	// Calculates and return temperature of environment
	override protected float GetEnvironmentTemperature()
	{
		if (m_HeatSourceTemp > 20)
			return m_HeatSourceTemp;
		
		if ( IsWaterContact() )
			return 13;
		
		if ( IsRaining() && !IsUnderRoof() )
			return 17;

		return 20; // Degree
	}
};
