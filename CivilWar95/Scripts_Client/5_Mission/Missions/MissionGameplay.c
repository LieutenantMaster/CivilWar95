modded class MissionGameplay
{
    // Register RPC
    void MissionGameplay()
    {
        GetRPCManager().AddRPC("RPC_Z3PP", "RPC_ReceiveZen3ppConfigOnClient", this, SingeplayerExecutionType.Client);
    }

    // Receive config sent from server -> client
    void RPC_ReceiveZen3ppConfigOnClient(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (type == CallType.Client)
        {
            Param2<int, ref array<ref ZenViewRestrictionZone>> data;

            // If data fails to read, stop here.
            if (!ctx.Read(data))
                return;

            // Data received - sync to client config
            GetZen3ppConfig().RestrictionTime = data.param1;

            // Populate restricted zones
            for (int i = 0; i < data.param2.Count(); i++)
            {
                GetZen3ppConfig().FirstPersonZones.Insert(data.param2.Get(i));
            }
        }
    }
};