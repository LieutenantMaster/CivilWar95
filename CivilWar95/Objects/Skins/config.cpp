class CfgPatches
{
	class CV95_Objects_Skins
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
	class ExpansionSignDanger;
	class ExpansionSignDanger2;
	class ExpansionSignDanger3;

	class CV95_ExpansionSignDanger_Checkpoint: ExpansionSignDanger
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_board_checkpoint_co.paa"};
	}
	class CV95_ExpansionSignDanger_Blufor: ExpansionSignDanger
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_board_mp_blufor_co.paa"};
	}
	class CV95_ExpansionSignDanger_Independent: ExpansionSignDanger
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_board_mp_independent_co.paa"};
	}
	class CV95_ExpansionSignDanger_Opfor: ExpansionSignDanger
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_board_mp_opfor_co.paa"};
	}
	class CV95_ExpansionSignDanger_Stop: ExpansionSignDanger
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_board_stop_co.paa"};
	}
	class CV95_ExpansionSignDanger_Zagorie: ExpansionSignDanger
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_wooden_relic_zagorie_co.paa"};
	}
	class CV95_ExpansionSignDanger_Tree: ExpansionSignDanger
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_wooden_relic_tree_co.paa"};
	}
	class CV95_ExpansionSignDanger_Building: ExpansionSignDanger
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_wooden_relic_building_co.paa"};
	}

	class CV95_ExpansionSignDanger3_FirstAid: ExpansionSignDanger3
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_one_leg_h_firstaid_co.paa"};
	}
	class CV95_ExpansionSignDanger3_NoEntry: ExpansionSignDanger3
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_one_leg_h_noentry_co.paa"};
	}
	class CV95_ExpansionSignDanger3_NoDumping: ExpansionSignDanger3
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_one_leg_v_nodumping_co.paa"};
	}
	class CV95_ExpansionSignDanger3_Quarry: ExpansionSignDanger3
	{
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dayzexpansion\objects\basebuilding\misc\signs\data\sign_one_leg_v_quarry_co.paa"};
	}
};