/**
 * CV95_Whistle_Shiny.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CV95_Whistle_Shiny: CV95_Whistle_Base
{
	override string GetLoopWhistleSoundset()
	{
		return "CV95_Whistle_03_SoundSet";
	}
	override float GetLoopWhistleLenght() 	{ return 1917; }
	override float GetWhistleLenghtDelay() 	{ return 2817; }
}