modded class MissionServer
{
	// Called when server initializes
	override void OnInit()
	{
		super.OnInit();

		// Load config
		GetSharedSettings();
	}

	// Called when a player connects to the server
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);

		if (!player || !identity)
			return;

		// Delay sending of client config randomly to avoid spamming new client login along with data from other mods
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SendSharedSettings, Math.RandomInt(5000, 6000), false, player);
	}

	// Send combo lock config to player from server
	void SendSharedSettings(PlayerBase player)
	{
		if (!player || !player.GetIdentity())
			return;

		// Send client config
		Param2<int, ref array<ref CW95ConflictZone>> configParams = new Param2<int, ref array<ref CW95ConflictZone>>(GetSharedSettings().RestrictionTime, GetSharedSettings().ConflictZones);
		GetRPCManager().SendRPC("RPC_SharedConfig", "RPC_ReceiveSharedSettingsOnClient", configParams, true, player.GetIdentity());
	}
};