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
	class CV95_Pistols_FNX45
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Pistols_FNX45"
		};
	};
};
class cfgWeapons
{
	class FNX45_Base;
	class FNX45 : FNX45_Base
	{
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\weapons\pistols\fnx45\data\herstal45tactical_co.paa"
		};
	};
	class CV95_FNX45_Variant_Body : FNX45
	{
		scope=0;
		hiddenSelectionsMaterials[]=
		{
			"CivilWar95\CivilWar95\Objects\Weapons\Pistols\Fnx45\data\herstal45_body.rvmat"
		};
	};
	class CV95_FNX45_Variant_Slide : FNX45
	{
		scope=0;
		hiddenSelectionsMaterials[]=
		{
			"CivilWar95\CivilWar95\Objects\Weapons\Pistols\Fnx45\data\herstal45_slide.rvmat"
		};
	};
	class CV95_FNX45_Grey_Full: FNX45
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0.514,0.514,0.514,1.0,co)"
		};
	};
	class CV95_FNX45_Tan_Full: FNX45
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0.824,0.706,0.549,1.0,co)"
		};
	};
	class CV95_FNX45_Olive_Full: FNX45
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0.35,0.36,0.28,1.0,co)"
		};
	};
	class CV95_FNX45_Grey_Body: CV95_FNX45_Variant_Body
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0.514,0.514,0.514,1.0,co)"
		};
	};
	class CV95_FNX45_Tan_Body: CV95_FNX45_Variant_Body
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0.824,0.706,0.549,1.0,co)"
		};
	};
	class CV95_FNX45_Olive_Body: CV95_FNX45_Variant_Body
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0.35,0.36,0.28,1.0,co)"
		};
	};
	class CV95_FNX45_Grey_Slide: CV95_FNX45_Variant_Slide
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0.514,0.514,0.514,1.0,co)"
		};
	};
	class CV95_FNX45_Tan_Slide: CV95_FNX45_Variant_Slide
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0.824,0.706,0.549,1.0,co)"
		};
	};
	class CV95_FNX45_Olive_Slide: CV95_FNX45_Variant_Slide
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0.35,0.36,0.28,1.0,co)"
		};
	};
};