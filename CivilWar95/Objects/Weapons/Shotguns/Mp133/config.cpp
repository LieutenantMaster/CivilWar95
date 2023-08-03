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
	class CV95_Weapons_Shotguns_MP133
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Weapons_Shotguns_MP133"
		};
	};
};
class cfgWeapons
{
	class Mp133Shotgun;
	class CV95_Mp133Shotgun_Old: Mp133Shotgun
	{
		hiddenSelectionsTextures[]=
		{
			"CivilWar95\CivilWar95\Objects\Weapons\Shotguns\Mp133\data\mp133_old_co.paa"
		};
	};
	class CV95_Mp133Shotgun_Mat_Black: Mp133Shotgun
	{
		hiddenSelectionsTextures[]=
		{
			"CivilWar95\CivilWar95\Objects\Weapons\Shotguns\Mp133\data\mp133_mat_black_co.paa"
		};
	};
};
