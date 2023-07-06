void main()
{
	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute, second;
    int reset_month = 6, reset_day = 11;
    GetYearMonthDay(year, month, day);
    GetHourMinuteSecond(hour, minute, second);
	year = 1995;

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
};

class CustomMission: MissionServer
{
	override void OnEvent(EventType eventTypeId, Param params) 
	{
		switch (eventTypeId)
		{
			case ClientNewEventTypeID:

				ClientNewEventParams newParams;
				Class.CastTo(newParams, params);
				PlayerIdentity identity = newParams.param1;
				string steamid = identity.GetPlainId();

				if ( !FindUserInWhitelist( "$profile:whitelist.txt", steamid ) )
				{
					Print("[CivilWar95] Connection denied to the player " + steamid);
					OnClientDisconnectedEvent(identity, NULL, 0, true);
					return;
				}
				Print("[CivilWar95] Connection granted to the player " + steamid);

			break;
		}

		super.OnEvent(eventTypeId, params);
	}

	static bool FindUserInWhitelist( string filePath, string steamid )
	{
		FileHandle file = OpenFile( filePath, FileMode.READ );

		if ( !file )
		{
			Print("[CivilWar95] ERROR !!!! Couldn't find " + filePath);
			return false;
		}

		string whitelistSteamId;
		while ( FGets( file, whitelistSteamId ) >= 1 )
		{
			if ( steamid == whitelistSteamId )
			{
				Print("Found matching steam id ! " + steamid + " == " + whitelistSteamId );
				CloseFile( file );
				return true;
			}
		}

		CloseFile( file );
		return false;
	}

	override void OnMissionStart()
 	{
		super.OnMissionStart();

		if ( IsScheaduledRestart() )
			UpdateTraderZones();
	}

	static void UpdateTraderZones()
	{
		IncrementStockForTraderzonePos("2640 200 5175", 10); 	// Zelenogorsk
		IncrementStockForTraderzonePos("6510 0 2550", 1); 		// Chernogorsk
	}

	static bool IsScheaduledRestart()
	{
		CF_Date now = CF_Date.Now(true);
		int timestamp = now.DateToEpoch();
		
		for (int i = 0; i < GetExpansionSettings().GetNotificationScheduler().Notifications.Count(); i++)
		{
			ExpansionNotificationSchedule schedule = GetExpansionSettings().GetNotificationScheduler().Notifications[i];
			if (!schedule || schedule.m_LastShownTimestamp == timestamp)
				continue;
			
			if (( schedule.Hour + 1 ) == now.GetHours() && now.GetMinutes() < 10.0)
			{
				return true;
			}
		}
		
		return false;
	}

	static void IncrementStockForTraderzonePos( vector position, float amount )
	{
		ExpansionMarketTraderZone traderZone = GetExpansionSettings().GetMarket().GetTraderZoneByPosition(position);
		if (!traderZone)
			return;
		
		traderZone.IncrementStock(amount);
		traderZone.Save();
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
};
