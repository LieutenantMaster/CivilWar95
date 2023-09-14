/**
 * ModItemRegisterCallbacks.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class ModItemRegisterCallbacks
{	
	override void RegisterOneHanded( DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior )
	{
		super.RegisterOneHanded( pType, pBehavior );

		pType.AddItemInHandsProfileIK("CW95_Whistle_Base", 	"dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/thermometer.anm");
		pType.AddItemInHandsProfileIK("CW95_MusicPlayer", 	"dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/support/handguard_m4_plastic.anm");
		pType.AddItemInHandsProfileIK("CW95_Cassette_Base", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/PunchedCard.anm");
		
		/*
		pType.AddItemInHandsProfileIK("CW95_MailBox_Base", 	"dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "NULL");
		pType.AddItemInHandsProfileIK("CW95_Folder_Base", 	"dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "NULL");
		pType.AddItemInHandsProfileIK("CW95_CCTV_Base", 	"dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "NULL");
		pType.AddItemInHandsProfileIK("CW95_Laptop_Base", 	"dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "NULL");
		pType.AddItemInHandsProfileIK("CW95_Key_Base", 		"dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "NULL");
		pType.AddItemInHandsProfileIK("CW95_KeyRing_Base", 	"dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "NULL");
		*/
	}
};
