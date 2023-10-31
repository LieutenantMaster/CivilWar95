class CfgPatches
{
	class CW95_Objects_Skins
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Navigation",
			"DayZExpansion_Market_Objects",
			"DayZExpansion_Vehicles_Air_HatchBird"
		};
	};
};

class CfgVehicles
{
	class ExpansionSign_Color;
	class ExpansionSignBig_Color;
	class ExpansionSign_Baravkas: ExpansionSign_Color
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\Publicité\Baranovkas_co.paa"};
	};
	class ExpansionSignBig_Baravkas: ExpansionSignBig_Color
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\Publicité\Baranovkas_co.paa"};
	};
	class ExpansionSign_MDF: ExpansionSign_Color
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\Publicité\MDF_co.paa"};
	};
	class ExpansionSignBig_MDF: ExpansionSignBig_Color
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\Publicité\MDF_co.paa"};
	};
	class ExpansionSignDanger; 	// Big 	 square
	class ExpansionSignDanger2; // Small triangle
	class ExpansionSignDanger3; // Small square

	class CW95_ExpansionSignDanger_Checkpoint: ExpansionSignDanger
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_board_checkpoint_co.paa"};
	};
	class CW95_ExpansionSignDanger_Blufor: ExpansionSignDanger
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_board_mp_blufor_co.paa"};
	};
	class CW95_ExpansionSignDanger_Independent: ExpansionSignDanger
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_board_mp_independent_co.paa"};
	};
	class CW95_ExpansionSignDanger_Opfor: ExpansionSignDanger
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_board_mp_opfor_co.paa"};
	};
	class CW95_ExpansionSignDanger_Stop: ExpansionSignDanger
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_board_stop_co.paa"};
	};
	class CW95_ExpansionSignDanger_Zagorie: ExpansionSignDanger
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_wooden_relic_zagorie_co.paa"};
	};
	class CW95_ExpansionSignDanger_Tree: ExpansionSignDanger
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_wooden_relic_tree_co.paa"};
	};
	class CW95_ExpansionSignDanger_Building: ExpansionSignDanger
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_wooden_relic_building_co.paa"};
	};

	class CW95_ExpansionSignDanger2_RedSkull: ExpansionSignDanger2
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_danger_red_co.paa"};
	};
	class CW95_ExpansionSignDanger2_Barrage: ExpansionSignDanger2
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\ExpansionSignDanger2\sign_barage_co.paa"};
	};
	class CW95_ExpansionSignDanger2_Barrage2: ExpansionSignDanger2
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\ExpansionSignDanger2\sign_barage2_co.paa"};
	};
	class CW95_ExpansionSignDanger2_Barrage3: ExpansionSignDanger2
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\ExpansionSignDanger2\sign_barage3_co.paa"};
	};
	class CW95_ExpansionSignDanger2_Chantier: ExpansionSignDanger2
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\ExpansionSignDanger2\sign_chantier_co.paa"};
	};
	class CW95_ExpansionSignDanger2_Controle: ExpansionSignDanger2
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\ExpansionSignDanger2\sign_controle_co.paa"};
	};
	class CW95_ExpansionSignDanger2_Controle2: ExpansionSignDanger2
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\ExpansionSignDanger2\sign_controle2_co.paa"};
	};
	class CW95_ExpansionSignDanger2_NoGun: ExpansionSignDanger2
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\ExpansionSignDanger2\sign_nogun_co.paa"};
	};
	class CW95_ExpansionSignDanger2_Manif: ExpansionSignDanger2
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\ExpansionSignDanger2\sign_manif_co.paa"};
	};

	class CW95_ExpansionSignDanger3_FirstAid: ExpansionSignDanger3
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_one_leg_h_firstaid_co.paa"};
	};
	class CW95_ExpansionSignDanger3_NoEntry: ExpansionSignDanger3
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_one_leg_h_noentry_co.paa"};
	};
	class CW95_ExpansionSignDanger3_NoDumping: ExpansionSignDanger3
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_one_leg_v_nodumping_co.paa"};
	};
	class CW95_ExpansionSignDanger3_Quarry: ExpansionSignDanger3
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_one_leg_v_quarry_co.paa"};
	};
	class CW95_ExpansionSignDanger3_Cherna: ExpansionSignDanger3
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\ExpansionSignDanger3\cherna_co.paa"};
	};
	class CW95_ExpansionSignDanger3_Controle: ExpansionSignDanger3
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\ExpansionSignDanger3\controle_co.paa"};
	};
	class CW95_ExpansionSignDanger3_Etoile: ExpansionSignDanger3
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\ExpansionSignDanger3\etoile_co.paa"};
	};
	class CW95_ExpansionSignDanger3_Mairie: ExpansionSignDanger3
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\ExpansionSignDanger3\mairie_co.paa"};
	};
	class CW95_ExpansionSignDanger3_Manif: ExpansionSignDanger3
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\ExpansionSignDanger3\manif_co.paa"};
	};
	class CW95_ExpansionSignDanger3_NoGun: ExpansionSignDanger3
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\ExpansionSignDanger3\nogun_co.paa"};
	};

	class ExpansionATM_Base;
	class ExpansionATM_1: ExpansionATM_Base
	{
		scope=1;
		hiddenSelectionsTextures[] = {"\CivilWar95\CivilWar95\Objects\Skins\Data\ATM\expansion_atm_01_co.paa"};
	};
	
	class ItemMap;
	class ChernarusMap: ItemMap
	{
		scope=2;
		hiddenSelections[]=
		{
			"texture_map_closed",
			"texture_map_opened",
			"texture_legend"
		};
		hiddenSelectionsTextures[] =
		{
			"dz\gear\navigation\data\map_chernarus_co.paa",
			"CivilWar95\CivilWar95\Objects\Skins\Data\Maps\Carte_Chernarus.paa",
			"CivilWar95\CivilWar95\Objects\Skins\Data\Maps\Carte_Chernarus.paa"
		};
	};
	class CW95_ZelenoMap: ChernarusMap
	{
		scope=2;
		displayName = "$STR_CW95_ITEM_MAPZELENO_NAME";
		hiddenSelectionsTextures[] =
		{
			"dz\gear\navigation\data\map_chernarus_co.paa",
			"CivilWar95\CivilWar95\Objects\Skins\Data\Maps\Carte_Zeleno.paa",
		};
	};
	class CW95_ZelenoMap_Open: CW95_ZelenoMap {};

	class CW95_ChernoMap: ChernarusMap
	{
		scope=2;
		displayName = "$STR_CW95_ITEM_MAPCHERNO_NAME";
		hiddenSelectionsTextures[] =
		{
			"dz\gear\navigation\data\map_chernarus_co.paa",
			"CivilWar95\CivilWar95\Objects\Skins\Data\Maps\Carte_Cherno.paa"
		};
	};
	class CW95_ChernoMap_Open: CW95_ChernoMap {};

	class CW95_ChernoMetroMap: ChernarusMap
	{
		scope=0;
		displayName = "$STR_CW95_ITEM_MAPCHERNOMETRO_NAME";
		hiddenSelectionsTextures[] =
		{
			"dz\gear\navigation\data\map_chernarus_co.paa",
			"CivilWar95\CivilWar95\Objects\Skins\Data\Maps\Carte_ChernoMetro.paa"
		};
	};
	class CW95_ChernoMap_Open: CW95_ChernoMetroMap {};

	class ExpansionHatchBird;
	class ExpansionHatchBirdDoors_Driver;
	class ExpansionHatchBirdHood;
	class ExpansionHatchBirdTrunk;

	class DamageSystem;
	class DamageZones;
	class GlobalHealth;
	class Health;

	class Front;
	class Window;
	class Doors;

	class ExpansionHatchBirdBloody: ExpansionHatchBird
	{
		hiddenSelectionsMaterials[]=
		{
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"dz\vehicles\wheeled\offroadhatchback\data\offroadhatchback_lights.rvmat",
			"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_body.rvmat",
			"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_body.rvmat",
			"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_body.rvmat",
			"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_body.rvmat",
			"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_body.rvmat",
			"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_body.rvmat",
			"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_body.rvmat",
			"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_body.rvmat",
			"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_body.rvmat",
			"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_body.rvmat"
		};
		defaultSkin = "HatchBirdBloody";
		class DamageSystem: DamageSystem
		{
			class DamageZones: DamageZones
			{
				class Front: Front
				{
					class Health: Health
					{
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_body.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_body.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_body_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_body_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_body_destruct.rvmat"
								}
							}
						};
					};
				};
			};
		};
	};
	class ExpansionHatchBirdBloodyDoors_Driver: ExpansionHatchBirdDoors_Driver
	{
		hiddenSelectionsMaterials[]=
		{
			"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_door.rvmat"
		};
		defaultSkin = "HatchBirdBloody";
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
			};
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health
					{
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass.rvmat"
								}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_destruct.rvmat"
								}
							},
							
							{
								0,
								"hidden"
							}
						};
					};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[]=
						{
							"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_door.rvmat"
						};
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_door.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_door.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_door_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_door_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_door_destruct.rvmat"
								}
							}
						};
					};
				};
			};
		};
	};
	class ExpansionHatchBirdBloodyDoors_CoDriver: ExpansionHatchBirdBloodyDoors_Driver
	{
		displayName="$STR_HatchbackDoors_CoDriver0";
		descriptionShort="$STR_HatchbackDoors_CoDriver1";
		model="\DZ\vehicles\wheeled\OffroadHatchback\proxy\nivaDoors_coDriver.p3d";
		inventorySlot[]=
		{
			"NivaCoDriverDoors"
		};
		rotationFlags=4;
	};	
	class ExpansionHatchBirdBloodyHood: ExpansionHatchBirdHood
	{
		hiddenSelectionsMaterials[]=
		{
			"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_hood.rvmat"
		};
		defaultSkin = "HatchBirdBloody";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=500;
					RefTexsMats[]=
					{
						"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_hood.rvmat"
					};
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_hood.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_hood.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_hood_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_hood_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_hood_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class ExpansionHatchBirdBloodyTrunk: ExpansionHatchBirdTrunk
	{
		hiddenSelectionsMaterials[]=
		{
			"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_trunk.rvmat"
		};
		defaultSkin = "HatchBirdBloody";
		class DamageSystem: DamageSystem
		{
			class DamageZones: DamageZones
			{
				class Window: Window
				{
					class Health: Health
					{
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass.rvmat"
								}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\niva_glass_destruct.rvmat"
								}
							},
							
							{
								0,
								"hidden"
							}
						};
					};
				};
				class Doors: Doors
				{
					class Health: Health
					{
						RefTexsMats[]=
						{
							"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_trunk.rvmat"
						};
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_trunk.rvmat"
								}
							},
							
							{
								0.69999999,
								
								{
									"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_trunk.rvmat"
								}
							},
							
							{
								0.5,
								
								{
									"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_trunk_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								
								{
									"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_trunk_damage.rvmat"
								}
							},
							
							{
								0,
								
								{
									"CivilWar95\CivilWar95\Objects\Skins\Data\Vehicles\HatchbirdBloody\niva_trunk_destruct.rvmat"
								}
							}
						};
					};
				};
			};
		};
	};
};