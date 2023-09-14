/**
 * config.cpp
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CfgPatches
{
	class CW95_Weapons_Firearms_MosinNagant
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Weapons_Firearms_MosinNagant"
		};
	};
};
class cfgWeapons
{
	class Mosin9130;
	class CW95_Mosin9130_Old: Mosin9130
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"CivilWar95\CivilWar95\Objects\Weapons\Firearms\Mosin9130\data\mosin_9130_old_co.paa"
		};
	};
	class SawedoffMosin9130;
	class CW95_SawedoffMosin9130_Old: SawedoffMosin9130
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"CivilWar95\CivilWar95\Objects\Weapons\Firearms\Mosin9130\data\mosin_9130_old_co.paa"
		};
	};
};
