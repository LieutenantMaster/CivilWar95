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
	class CV95_Pistols_Glock
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Pistols_Glock"
		};
	};
};
class cfgWeapons
{
	class Glock19_Base;
	class Glock19 : Glock19_Base
	{
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"DZ\weapons\pistols\glock\data\glock19_co.paa"
		};
	};
	class CV95_Glock19_Tan: Glock19
	{
		hiddenSelectionsTextures[]=
		{
			"CivilWar95\CivilWar95\Objects\Weapons\Pistols\Glock\data\glock19_tan_co.paa"
		};
	};
	class CV95_Glock19_Olive: Glock19
	{
		hiddenSelectionsTextures[]=
		{
			"CivilWar95\CivilWar95\Objects\Weapons\Pistols\Glock\data\glock19_olive_co.paa"
		};
	};
	class CV95_Glock19_Modern: Glock19
	{
		hiddenSelectionsTextures[]=
		{
			"CivilWar95\CivilWar95\Objects\Weapons\Pistols\Glock\data\glock19_modern_co.paa"
		};
	};
};