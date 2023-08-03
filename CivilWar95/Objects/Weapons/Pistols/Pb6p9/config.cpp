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
	class CV95_Pistols_pb6p9
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Pistols_pb6p9"
		};
	};
};
class Mode_SemiAuto;
class OpticsInfoPistol;
class cfgWeapons
{
	class Pistol_Base;
	class MakarovPB_Base: Pistol_Base
	{
		scope=0;
		weight=760;
		absorbency=0;
		repairableWithKits[]={1};
		repairCosts[]={30,25};
		PPDOFProperties[]={1,0.5,10,280,4,10};
		WeaponLength=0.56051803;
		barrelArmor=4.5;
		chamberSize=1;
		chamberedRound="";
		magazines[]=
		{
			"Mag_MakarovPB_8Rnd"
		};
		chamberableFrom[]=
		{
			"Ammo_380"
		};
		ejectType=1;
		noiseShootModifier=-0.89999998;
		recoilModifier[]={1,1,1};
		swayModifier[]={1,1,0.69999999};
		drySound[]=
		{
			"DZ\sounds\weapons\firearms\PB6P9\PB6P9_dry",
			0.5,
			1,
			20
		};
		reloadMagazineSound[]=
		{
			"dz\sounds\weapons\firearms\ij70\Makarov_reload",
			0.80000001,
			1,
			20
		};
		reloadAction="ReloadIJ70";
		modes[]=
		{
			"Single"
		};
		class Single: Mode_SemiAuto
		{
			soundSetShot[]=
			{
				"PB6P9_silencerPro_SoundSet",
				"PB6P9_silencerTail_SoundSet",
				"PB6P9_silencerInteriorTail_SoundSet"
			};
			soundSetShotExt[]=
			{				
				{
					"PB6P9_silencerPro_SoundSet",
					"PB6P9_silencerTail_SoundSet",
					"PB6P9_silencerInteriorTail_SoundSet"
				}
			};
			begin1[]=
			{
				"dz\sounds\weapons\firearms\ij70\ij70_close_0",
				1,
				1,
				600
			};
			begin2[]=
			{
				"dz\sounds\weapons\firearms\ij70\ij70_close_1",
				1,
				1,
				600
			};
			soundBegin[]=
			{
				"begin1",
				0.5,
				"begin2",
				0.5
			};
			reloadTime=0.13;
			recoil="recoil_ij70";
			recoilProne="recoil_if70_prone";
			dispersion=0.012;
			magazineSlot="magazine";
			beginSilenced_Pro[]=
			{
				"dz\sounds\weapons\firearms\ij70\MakarovSilenced",
				1,
				1,
				60
			};
			beginSilenced_HomeMade[]=
			{
				"dz\sounds\weapons\firearms\ij70\MakarovSilenced",
				1,
				1,
				100
			};
			soundBeginExt[]=
			{
				
				{
					"beginSilenced_Pro",
					1
				},
				
				{
					"beginSilenced_HomeMade",
					1
				}
			};
		};
		class Particles
		{
			class OnFire
			{
				class SmokeCloud
				{
					overrideParticle="weapon_shot_winded_smoke_small";
				};
			};
			class OnOverheating
			{
				shotsToStartOverheating=3;
				maxOverheatingValue=7;
				overheatingDecayInterval=1;
				class OpenChamberSmoke
				{
					onlyIfBoltIsOpen=1;
					overrideParticle="smoking_barrel_small";
					overridePoint="Nabojnicestart";
				};
			};
		};
		class OpticsInfo: OpticsInfoPistol
		{
			memoryPointCamera="eye";
			discreteDistance[]={25};
			discreteDistanceInitIndex=0;
			modelOptics="-";
			distanceZoomMin=100;
			distanceZoomMax=100;
		};
	};
	class MakarovPB: MakarovPB_Base
	{
		scope=2;
		displayName="$STR_cfgWeapons_MakarovPB0";
		descriptionShort="$STR_cfgWeapons_MakarovPB1";
		model="\DZ\weapons\pistols\pb6p9\pb6p9.p3d";
		itemSize[]={2,2};
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
								"DZ\weapons\pistols\pb6p9\data\pb6p9.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\pistols\pb6p9\data\pb6p9.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\pistols\pb6p9\data\pb6p9_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\pistols\pb6p9\data\pb6p9_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\pistols\pb6p9\data\pb6p9_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyPB6P9: ProxyAttachment
	{
		scope=2;
		inventorySlot="pistol";
		model="\dz\weapons\pistols\pb6p9\pb6p9.p3d";
	};
};
