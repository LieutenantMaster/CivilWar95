class CfgPatches
{
	class CW95_Objects_Props_Conflict
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class CW95_ConflictFlag: Inventory_Base
	{
		scope=2;
		displayName="Conflict Flag";
		descriptionShort="PLACEHOLDER";
		model="\DZ\gear\camping\territory_flag.p3d";
		bounding="BSphere";
		overrideDrawArea="3.0";
		forceFarBubble="true";
		handheld="false";
		carveNavmesh=1;
		weight=60000;
		itemSize[]={6,6};
		physLayer="item_large";
		rotationFlags=2;
		attachments[]=
		{
			"Material_FPole_Flag"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Flag
			{
				name="$STR_CfgVehicles_TerritoryFlag_Att_Category_Flag";
				description="";
				attachmentSlots[]=
				{
					"Material_FPole_Flag"
				};
				icon="set:dayz_inventory image:tf_flag";
				selection="totem";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class AnimSourceHidden
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class flag_mast
			{
				source="user";
				initPhase=1;
				animPeriod=1;
			};

			class Base: AnimSourceShown {};
			class Support: AnimSourceShown {};
			class Pole: AnimSourceShown {};

			class Deployed: AnimSourceHidden {};
			class Material_FPole_WoodenLog: AnimSourceHidden {};
			class Material_FPole_Stones: AnimSourceHidden {};
			class Material_FPole_WoodenLog2: AnimSourceHidden {};
			class Material_FPole_MetalWire: AnimSourceHidden {};
			class Material_FPole_Rope: AnimSourceHidden {};
			class Material_FPole_Nails: AnimSourceHidden {};
			class Material_FPole_MagicStick: AnimSourceHidden {};
		};
	};
	class CW95_Prop_Base: Inventory_Base
	{
		scope=0;
		handheld="false";
		carveNavmesh=1;
	};
	class CW95_Kit_Base: Inventory_Base
	{
		scope=0;
		handheld="false";
		carveNavmesh=1;
	};
	class CW95_NAME_Kit: CW95_Kit_Base
	{
		//scope=2;
		displayName="NAME Kit";
		descriptionShort="PLACEHOLDER";
		model="\DZ\gear\camping\territory_flag_kit.p3d";
		rotationFlags=17;
		itemSize[]={1,5};
		weight=280;
		itemBehaviour=1;
	};
	class CW95_NAME_Deployed: CW95_Prop_Base
	{
		//scope=2;
		displayName="NAME";
		descriptionShort="PLACEHOLDER";
		model="\DZ\gear\camping\territory_flag.p3d";
		
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=5;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=50;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
	};
};