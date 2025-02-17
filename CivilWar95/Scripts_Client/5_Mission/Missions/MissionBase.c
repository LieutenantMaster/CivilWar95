#ifndef SERVER
modded class MissionBase
{
	private ref EffectSound m_ZenArtySound;

	void MissionBase()
	{
		GetRPCManager().AddRPC("ZAS_RPC", "RPC_ZAS_ReceiveAirstrikeData", this, SingeplayerExecutionType.Server);
	}

	void RPC_ZAS_ReceiveAirstrikeData(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Client)
		{
			Param1< vector > data;
			if (!ctx.Read(data))
				return;

			vector soundPosition = data.param1;
			if (soundPosition)
			{
				m_ZenArtySound = SEffectManager.PlaySound("Artillery_Distant_Barrage_SoundSet", soundPosition, 0.1, 0.1);
				m_ZenArtySound.SetAutodestroy(true);
			}
		}
	}
};
#endif