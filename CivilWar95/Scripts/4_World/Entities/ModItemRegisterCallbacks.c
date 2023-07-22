modded class ModItemRegisterCallbacks
{	
	override void RegisterOneHanded( DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior )
	{
		super.RegisterOneHanded( pType, pBehavior );

		pType.AddItemInHandsProfileIK("CV95_MusicPlayer", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/support/handguard_m4_plastic.anm");
		pType.AddItemInHandsProfileIK("CV95_Cassette_Base", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/PunchedCard.anm");
	}
};
