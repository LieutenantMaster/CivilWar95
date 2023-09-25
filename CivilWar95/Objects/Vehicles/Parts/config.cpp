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
	class CW95_Vehicles_Parts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Vehicles_Parts"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class CW95_WindScreen: Inventory_Base
	{
		scope=2;
		displayName="$STR_CW95_ITEM_WINDSCREEN_NAME";
		descriptionShort="$STR_CW95_ITEM_WINDSCREEN_DESC";
		model="\dz\vehicles\parts\windscreen_box.p3d";
		weight=1000;
		itemSize[]={2,3};
		absorbency=0;
		rotationFlags=16;
		repairKitType=6;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\vehicles\parts\data\windscreen_box.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\vehicles\parts\data\windscreen_box.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\vehicles\parts\data\windscreen_box_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\vehicles\parts\data\windscreen_box_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\vehicles\parts\data\windscreen_box_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="smallprotectorcase_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="smallprotectorcase_drop_SoundSet";
					id=898;
				};
			};
		};
	};
};