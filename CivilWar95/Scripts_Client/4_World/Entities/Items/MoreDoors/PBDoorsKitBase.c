modded class PBDoorsKitBase
{
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
#ifdef SERVER
		if (m_AdminLog)
			m_AdminLog.OnPlacementComplete(player, this);

		if ( hasTheGoodStuff() )
		{
			Object deployedObject = GetGame().CreateObject(j_Door(), position);
			deployedObject.SetOrientation(orientation);

			Delete();
		}

		SetIsDeploySound( true );
		SetLifetime(3888000);
#endif
	}
};
