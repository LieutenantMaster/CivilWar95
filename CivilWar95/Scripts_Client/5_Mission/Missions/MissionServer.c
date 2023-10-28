modded class MissionServer
{
	// Called when server initializes
	override void OnInit()
	{
		super.OnInit();

		// Load config
		GetZen3ppConfig();
	}

	// Called when a player connects to the server
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);

		if (!player || !identity)
			return;

		// Delay sending of client config randomly to avoid spamming new client login along with data from other mods
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SendZen3ppConfig, Math.RandomInt(5000, 6000), false, player);
	}

	// Send combo lock config to player from server
	void SendZen3ppConfig(PlayerBase player)
	{
		if (!player || !player.GetIdentity())
			return;

		// Send client config
		Param2<int, ref array<ref ZenViewRestrictionZone>> configParams = new Param2<int, ref array<ref ZenViewRestrictionZone>>(GetZen3ppConfig().RestrictionTime, GetZen3ppConfig().FirstPersonZones);
		GetRPCManager().SendRPC("RPC_Z3PP", "RPC_ReceiveZen3ppConfigOnClient", configParams, true, player.GetIdentity());
	}
};