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
	class CW95_Weapons_Firearms_SVD
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Weapons_Firearms_SVD"
		};
	};
};
class cfgWeapons
{
	class SVD_Base;
	class SVD : SVD_Base
	{
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\dz\weapons\firearms\svd\data\svd_co.paa"
		};
	};
	class CW95_SVD_Wood: SVD
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"CivilWar95\CivilWar95\Objects\Weapons\Firearms\Svd\data\svd_wood_co.paa"
		};
	};
	class CW95_SVD_Old: SVD
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"CivilWar95\CivilWar95\Objects\Weapons\Firearms\Svd\data\svd_old_co.paa"
		};
	};
};
