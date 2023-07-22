[CF_RegisterModule(FrontLineManager)]
class FrontLineManager: CF_ModuleWorld
{
    // ==================== SHARED ====================
    private static autoptr TVectorArray m_PolygonFrontline =
    {
        "11314.343750 1.177152 3223.869385",
        "11058.950195 79.412567 3534.696289",
        "10890.581055 204.113342 3884.905762",
        "10726.701172 256.502319 4140.828613",
        "10504.452148 108.945969 4398.995117",
        "10185.671875 225.713348 4697.570801",
        "9849.343750 179.639099 5001.323730",
        "9557.927734 186.360413 5268.455078",
        "9181.515625 198.679443 5422.257324",
        "8776.771484 311.388336 5567.965332",
        "8420.596680 234.835648 5657.008789",
        "8088.706055 258.911560 5818.906738",
        "7742.406738 214.090515 5949.395996",
        "7382.184570 242.611954 6018.202637",
        "7090.769043 273.931091 6018.202637",
        "6868.159668 304.069244 6252.954590",
        "6612.522949 329.139587 6462.125977",
        "6373.399902 371.375641 6716.953125",
        "6192.397461 361.935608 6931.630371",
        "5917.171875 319.936798 7101.623047",
        "5565.044434 314.573456 7178.523438",
        "5273.628418 305.286438 7154.239258",
        "4990.307617 285.738373 7024.721191",
        "4711.033203 286.885315 6955.915039",
        "4407.475586 277.125427 6911.392578",
        "4176.771484 297.259277 6874.965820",
        "3832.738281 321.533936 6891.155273",
        "3525.132813 340.010254 6935.677246",
        "3229.669189 355.024017 6976.151855",
        "3031.344238 359.917542 7044.958008",
        "2691.359375 335.368652 7113.764648",
        "2403.990967 310.272064 7125.907227",
        "2068.053223 246.457611 7182.572266",
        "1804.969604 270.380829 7214.951660",
        "1416.605225 234.080231 7244.740234",
        "1060.430176 174.656509 7179.980957",
        "797.346130 183.953217 7038.320801",
        "538.310181 269.907227 6941.182129",
        "174.039948 256.503174 6892.612793",
        "5.061087 303.029999 7561.472168",
        "0.000000 324.128174 9064.593750",
        "2073.430908 274.739868 9172.120117",
        "3494.473633 307.469330 9081.690430",
        "5722.927246 320.935883 8881.452148",
        "7654.253906 369.989319 8403.464844",
        "9533.906250 244.185394 7647.728516",
        "11116.250000 95.161285 6687.620605",
        "11723.422852 131.466003 6022.313965",
        "12433.943359 168.150787 4904.857422",
        "12879.633789 10.830025 3806.779297",
        "13312.406250 -12.961699 2557.877197",
        "13099.249023 -115.500046 1349.989990",
        "12246.623047 -140.522873 645.927429",
        "12001.170898 -107.657242 1563.147583",
        "11846.147461 -29.747583 2280.127197",
        "11497.346680 -9.746394 2842.085205"
    };

    // ==================== SERVER ====================
	private autoptr array< ref FrontLineEventBase > m_Events;

    // ==================== CLIENT ====================
    private bool m_IsInZone;
    private bool m_WasInZone;

    // ///////////////////////////////////////////////////////////////////////////////////////////
    // /////////////////////////////////////// SERVER SIDE ///////////////////////////////////////
    // ///////////////////////////////////////////////////////////////////////////////////////////
	
	override void OnInit()
	{
		super.OnInit();

		EnableRPC();
	}
	
	override int GetRPCMin()
	{
		return CV95SettingsRPC.INVALID;
	}
	
	override int GetRPCMax()
	{
		return CV95SettingsRPC.COUNT;
	}

    /// <summary>
    /// SERVER SIDE | Spawn a random event ahead of the player position.
    /// </summary>
    void SpawnEventAhead(vector position)
    {
        vector direction = Vector(Math.RandomFloatInclusive(0,1), 0, Math.RandomFloatInclusive(0,1)).Normalized();

        position        = position * (direction * 100);
        float radius    = Math.RandomFloatInclusive(10, 50);
        int quantity     = Math.RandomFloatInclusive(1, 10);
        int selectedEventType = FrontLineTypes.ARTI; //= Math.RandomIntInclusive(0, FrontLineTypes.COUNT - 1);

        Print("DEBUG | SERVER | SpawnEventAhead");
        switch(selectedEventType)
        {
            case FrontLineTypes.AI:
                m_Events.Insert(new FrontLineAI(position, radius, quantity));
            break;
            case FrontLineTypes.MINE:
                m_Events.Insert(new FrontLineMines(position, radius * 2, quantity * 5));
            break;
            case FrontLineTypes.ARTI:
                Print("DEBUG | SERVER | FrontLineTypes.ARTI");
                Print("DEBUG | SERVER | FrontLineTypes.ARTI | position "+ position);
                Print("DEBUG | SERVER | FrontLineTypes.ARTI | radius "+ radius * 10);
                Print("DEBUG | SERVER | FrontLineTypes.ARTI | quantity "+ quantity);
                m_Events.Insert(new FrontLineArtillery(position, radius * 10, quantity));
            break;
            case FrontLineTypes.SFX:
                m_Events.Insert(new FrontLineSoundEffect(position, -1, quantity));
            break;
        }
    }

    /// <summary>
    /// SERVER SIDE | 
    /// </summary>
    void CheckEventStatus()
    {
        if ( m_Events.Count() > 0 )
        {
            int i = 0;
            while( i < m_Events.Count() )
            {
                if ( m_Events[i].ShouldDelete() )
                {
                    m_Events.Remove(i);
                }
                else
                {
                    i++;
                }
            }

            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CheckEventStatus, 10000, false);
        }
    }

	override void OnRPC(Class sender, CF_EventArgs args)
	{
		super.OnRPC(sender, args);

		auto rpc = CF_EventRPCArgs.Cast(args);

		switch ( rpc.ID )
		{
			case CV95SettingsRPC.FrontLineTrigger:
				RPC_FrontLineTrigger(rpc.Context, rpc.Sender, rpc.Target);
            break;
		}
	}

	private void RPC_FrontLineTrigger( ParamsReadContext ctx, PlayerIdentity senderRPC, Object target )
	{
		if (!ExpansionScriptRPC.CheckMagicNumber(ctx))
			return;

        vector position;
		if ( !ctx.Read( position ) )
		{
			Error("FrontLineManager::RPC_FrontLineTrigger position");
			return;
		}

        bool isFlying;
		if ( !ctx.Read( isFlying ) )
		{
			Error("FrontLineManager::RPC_FrontLineTrigger isFlying");
			return;
		}


        //SpawnEventAhead(position, isFlying);
	}

    // ///////////////////////////////////////////////////////////////////////////////////////////
    // /////////////////////////////////////// CLIENT SIDE ///////////////////////////////////////
    // ///////////////////////////////////////////////////////////////////////////////////////////

    /// <summary>
    /// CLIENT SIDE | Check if the player is inside the frontline polygone zone.
    /// Change the frequency of checks based of the distance.
    /// If we are inside let the server know.
    /// </summary>
    void CheckPlayerPosition(bool doAdvancedDistanceCheck = false)
    {
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (!player)
        {
            float distance;
            if ( !IsPositionInPolygonFrontline(player.GetPosition(), doAdvancedDistanceCheck, distance) )
            {
                float time = Math.Max(1000 * ( distance / 10 ), 60000); // Max 1 minute
                doAdvancedDistanceCheck = distance < 400;

			    GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CheckPlayerPosition, time, false, doAdvancedDistanceCheck);
            }
            else
            {
				ExpansionNotification("Warning", "You entered a War Zone !", "DayZExpansion\\Core\\GUI\\icons\\misc\\T_HumanSkull_256x256.edds", COLOR_EXPANSION_NOTIFICATION_EXPANSION, 10).Create(player.GetIdentity());
                
                // RPC Server !
                auto rpc = ExpansionScriptRPC.Create();
                rpc.Write( player.GetPosition() );
                rpc.Send( null, CV95SettingsRPC.FrontLineTrigger, true, player.GetIdentity() );
            }
        }
    }

    /// <summary>
    /// CLIENT SIDE | Determines if a position is inside the polygon and calculates the minimum distance from the polygon.
    /// </summary>
    /// <param name="position">The position to check.</param>
    /// <param name="distance">Return the minimum distance from the polygon zone from the position</param>
    /// <returns>the boolean result indicating if the position is inside the polygon.</returns>
    static bool IsPositionInPolygonFrontline(vector position, bool doAdvancedDistanceCheck, out float distance)
    {
        int numVertices = m_PolygonFrontline.Count();
        float currentDistance;
        bool isInside;

        for (int i = 0, j = numVertices - 1; i < numVertices; j = i++)
        {
            bool isPositionAboveI = m_PolygonFrontline[i][2] > position[2];
            bool isPositionAboveJ = m_PolygonFrontline[j][2] > position[2];
            bool isPositionBetweenIJ = isPositionAboveI != isPositionAboveJ;

            bool isPositionToLeftOfLine =
                position[0] < (m_PolygonFrontline[j][0] - m_PolygonFrontline[i][0]) * (position[2] - m_PolygonFrontline[i][2]) / (m_PolygonFrontline[j][2] - m_PolygonFrontline[i][2]) + m_PolygonFrontline[i][0];

            if (isPositionBetweenIJ && isPositionToLeftOfLine)
            {
                isInside = !isInside;
            }

            // Calculate and update the minimum distance from the polygon
            if ( !isInside )
            {
                if ( doAdvancedDistanceCheck )
                {
                    currentDistance = CalculateDistance(position, m_PolygonFrontline[i], m_PolygonFrontline[j]);
                }
                else
                {
                    currentDistance = vector.Distance(position, m_PolygonFrontline[i]);
                }

                distance = Math.Min(distance, currentDistance);
            }

        }
        return true;//isInside;
    }

    /// <summary>
    /// CLIENT SIDE | Calculates the minimum distance between a point and a line segment defined by two points.
    /// </summary>
    /// <param name="point">The point for which to calculate the distance.</param>
    /// <param name="lineStart">The starting point of the line segment.</param>
    /// <param name="lineEnd">The ending point of the line segment.</param>
    /// <returns>The minimum distance between the point and the line segment.</returns>
    static float CalculateDistance(vector point, vector lineStart, vector lineEnd)
    {
        float a = point[0] - lineStart[0];
        float b = point[2] - lineStart[2];
        float c = lineEnd[0] - lineStart[0];
        float d = lineEnd[2] - lineStart[2];

        float dot = a * c + b * d;
        float lenSq = c * c + d * d;
        float param = dot / lenSq;

        float nearestX, nearestY;
        if (param < 0 || (lineStart[0] == lineEnd[0] && lineStart[2] == lineEnd[2]))
        {
            nearestX = lineStart[0];
            nearestY = lineStart[2];
        }
        else if (param > 1)
        {
            nearestX = lineEnd[0];
            nearestY = lineEnd[2];
        }
        else
        {
            nearestX = lineStart[0] + param * c;
            nearestY = lineStart[2] + param * d;
        }

        float dx = point[0] - nearestX;
        float dy = point[2] - nearestY;

        return Math.Sqrt(dx * dx + dy * dy);
    }
};
