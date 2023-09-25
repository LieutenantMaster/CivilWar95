class CfgPatches
{
	class CW95_Objects_Overrides_Vanilla_Animals
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Animals_ursus_arctos"
		};
	};
};

class CfgVehicles
{
	class Projectile;
	class ArmorType;
	class Melee;
	class Zone_Head;
	class Health;

	class AnimalBase;
	class Animal_UrsusArctos: AnimalBase
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1400;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
				class Blood
				{
					hitpoints=8750;
				};
				class Shock
				{
					hitpoints=8750;
				};
			};
			class DamageZones
			{
				class Zone_Head
				{
					componentNames[]=
					{
						"Zone_Head"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.1;
					canBleed=0;
					class Health
					{
						hitpoints=440;
						transferToGlobalCoef=1;
					};
					class Blood: Health
					{
						hitpoints=8750;
					};
					class Shock: Health
					{
						hitpoints=8750;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage=0.50999999;
							};
						};
						class Projectile: Melee
						{
							class Health: Health
							{
								damage=0.25;
							};
						};
						class FragGrenade: Melee
						{
						};
					};
				};
				class Zone_Neck: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Neck"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.1;
					class Health
					{
						hitpoints=525;
						transferToGlobalCoef=1;
					};
					class ArmorType: ArmorType
					{
						class Melee: Melee
						{
							class Health: Health
							{
								damage=0.15000001;
							};
						};
						class Projectile: Projectile
						{
							class Health: Health
							{
								damage=0.25;
							};
						};
					};
				};
				class Zone_Belly: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Belly"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.0099999998;
					class Health: Health
					{
						hitpoints=700;
					};
					class ArmorType: ArmorType
					{
						class Melee: Melee
						{
							class Health: Health
							{
								damage=0.15000001;
							};
						};
					};
				};
				class Zone_Pelvis: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Pelvis"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.0099999998;
					class Health: Health
					{
						hitpoints=875;
					};
					class ArmorType: ArmorType
					{
						class Melee: Melee
						{
							class Health: Health
							{
								damage=0.15000001;
							};
						};
					};
				};
				class Zone_Legs: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Legs"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.0099999998;
					class Health: Health
					{
						hitpoints=350;
						transferToGlobalCoef=0;
					};
				};
			};
		};
	};
};
