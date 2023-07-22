modded class MissionServer
{
	protected float p_Time_SliceFIX = 0.025;
	protected bool p_Inpu_tabobus = true;

	void MissionServer()
    {
		GetDayZGame().Event_OnRPC.Insert(abobus_btr70_RCP);
	}

	void ~MissionServer()
    {
		GetDayZGame().Event_OnRPC.Remove(abobus_btr70_RCP);
	}

	void On_Input_abobus()
	{
		p_Inpu_tabobus = true;
	}

	void abobus_btr70_RCP(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
    {		
		private PlayerBase m_Player;
		
		if (rpc_type == MA_RPCClient.SyncBlueRoomControllsClient)
        {			
			if (sender)
            {			
				ref Param5< bool, float, float, float, PlayerBase> dayzParamsControlls;

				if (ctx.Read( dayzParamsControlls ))
				{
					m_Player = dayzParamsControlls.param5;
						
					if ( m_Player )
					{
						BlueRoom blue = BlueRoom.Cast( m_Player.GetParent() );
					
						if ( blue && m_Player == blue.CrewMember( DayZPlayerConstants.VEHICLESEAT_DRIVER ) )
						{
							float struya = dayzParamsControlls.param4;
							blue.GetControllerBlueRoom().SetabobusLeft( dayzParamsControlls.param2 );
							blue.GetControllerBlueRoom().SetabobusRight( dayzParamsControlls.param3 );
							blue.GetControllerBlueRoom().SetDirectionCameraabobus(struya);
							
							if (dayzParamsControlls.param1)
							{
								blue.ScocthSimulation();
							}
						}
					}		
				}
			}
		}
	}
};
