modded class MissionGameplay
{
    // Register RPC
    void MissionGameplay()
    {
        GetRPCManager().AddRPC("RPC_SharedConfig", "RPC_ReceiveSharedSettingsOnClient", this, SingeplayerExecutionType.Client);
    }

    // Receive config sent from server -> client
    void RPC_ReceiveSharedSettingsOnClient(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (type == CallType.Client)
        {
            Param2<int, ref array<ref CW95ConflictZone>> data;

            // If data fails to read, stop here.
            if (!ctx.Read(data))
                return;

            // Data received - sync to client config
            GetSharedSettings().RestrictionTime = data.param1;

            // Populate restricted zones
            for (int i = 0; i < data.param2.Count(); i++)
            {
                GetSharedSettings().ConflictZones.Insert(data.param2.Get(i));
            }
        }
    }
};