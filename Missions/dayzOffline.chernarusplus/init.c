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
	

	if ( !FileExist( CV95_PATH_MISSION_PLAYERDATA ) )
		ExpansionStatic.MakeDirectoryRecursive( CV95_PATH_MISSION_PLAYERDATA );
};

class CustomMission: MissionServer
{
	//! ============================== WHITELIST SYSTEM ==============================
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
					Print("[CivilWar95]:: LOGIN:: Connection denied to the player " + steamid);
					OnClientDisconnectedEvent(identity, NULL, 0, true);
					return;
				}
				Print("[CivilWar95]:: LOGIN:: Connection granted to the player " + steamid);

			break;
		}

		super.OnEvent(eventTypeId, params);
	}

	static bool FindUserInWhitelist( string filePath, string steamid )
	{
		FileHandle file = OpenFile( filePath, FileMode.READ );

		if ( !file )
		{
			Print("[CivilWar95]:: WHITELIST:: ERROR !!!! Couldn't find " + filePath);
			return false;
		}

		string whitelistSteamId;
		while ( FGets( file, whitelistSteamId ) >= 1 )
		{
			if ( steamid == whitelistSteamId )
			{
				Print("[CivilWar95]:: WHITELIST:: Found matching steam id ! " + steamid + " == " + whitelistSteamId );
				CloseFile( file );
				return true;
			}
		}

		CloseFile( file );
		return false;
	}

	//! ============================== PLAYER FACTION AND LOADOUT SYSTEM ==============================
	override void EquipCharacter(MenuDefaultCharacterData char_data)
	{
		Print("[CivilWar95]:: EquipCharacter");
		if ( !IsMissionHost() )
		{
			super.EquipCharacter(char_data);
			return;
		}
		string loadoutType = "DEFAULT";

		string steamID = m_player.GetIdentity().GetPlainId();
		string filename = CV95_PATH_MISSION_PLAYERDATA + steamID + ".map";

		FileHandle file;
		Print("[CivilWar95]:: !FileExist");
		if (!FileExist( filename ))
		{
			m_player.SetPosition(GetCivilianSpawns().GetRandomElement());
			if ( m_player.IsMale() )
				loadoutType = "PlayerSurvivorLoadout";
			else
				loadoutType = "PlayerSurvivorLoadout";
				
			ExpansionHumanLoadout.Apply(m_player, loadoutType, false);
			return;
		}
		Print("[CivilWar95]:: FileExist");

		int factionID;
		string factionName;
		vector spawnPos = "0 0 0";

		file = OpenFile(filename , FileMode.READ );
		if ( file )
		{
			string line;
			if ( FGets( file, line ) != 0 )
			{
				TStringArray tokens = new TStringArray;
				line.Split( "|", tokens );

				factionID	= tokens.Get( 0 ).ToInt();
				loadoutType = tokens.Get( 1 );
				spawnPos 	= tokens.Get( 2 ).ToVector();
			}
		}
		Print("[CivilWar95]:: FGets");

		typename factionType = eAIFaction.GetTypeByID(factionID);
		if (factionType)
		{
			eAIFaction faction = eAIFaction.Cast(factionType.Spawn());
			if (faction)
			{
				factionName = faction.GetName();
				if (m_player.GetGroup())
				{
					m_player.GetGroup().SetFaction(faction);
				}
				else
				{
					eAIGroup group = eAIGroup.GetGroupByLeader(m_player, true, faction);
				}
			}
		}
		Print("[CivilWar95]:: factionType");

		GetFactionData(factionName, m_player.IsMale(), loadoutType, spawnPos);

		TStringArray gear = new TStringArray;
		loadoutType.Split( ",", gear );
		if ( gear.Count() > 1 )
		{
			Print("[CivilWar95]:: ExpansionObjectSpawnTools");
			ExpansionObjectSpawnTools.ProcessGear(m_player, loadoutType);
		} else {
			Print("[CivilWar95]:: ExpansionHumanLoadout");
			ExpansionHumanLoadout.Apply(m_player, loadoutType, false);
		}

		Print("[CivilWar95]:: SetPosition");
		m_player.SetPosition(spawnPos);
	}

	void GetFactionData(string factionName, bool isMale, out string loadoutType, out vector spawnPos)
	{
		string factionLoadout;
		vector SelectedPos;

		bool skipPosSelection = spawnPos != "0 0 0";
		bool skipLoadoutSelection = loadoutType != "DEFAULT";

		switch(factionName)
		{
			default:
			case "": // civil !
				SelectedPos = GetCivilianSpawns().GetRandomElement();
				if ( isMale )
					factionLoadout = "PlayerSurvivorLoadout";
				else
					factionLoadout = "PlayerSurvivorLoadout";
			break;
			case "Police":
				SelectedPos = GetPoliceSpawns().GetRandomElement();
				if ( isMale )
					factionLoadout = "PoliceLoadout";
				else
					factionLoadout = "PoliceLoadout";
			break;
			case "Medic":
				SelectedPos = GetCivilianSpawns().GetRandomElement();
				if ( isMale )
					factionLoadout = "PlayerSurvivorLoadout";
				else
					factionLoadout = "PlayerSurvivorLoadout";
			break;
			case "Militaire":
				SelectedPos = GetChernaSpawns().GetRandomElement();
				if ( isMale )
					factionLoadout = "GorkaLoadout";
				else
					factionLoadout = "GorkaLoadout";
			break;
			case "Napa":
				SelectedPos = GetNAPASpawns().GetRandomElement();
				if ( isMale )
					factionLoadout = "EastLoadout";
				else
					factionLoadout = "EastLoadout";
			break;
			case "Chedaki":
				SelectedPos = GetChedakiSpawns().GetRandomElement();
				if ( isMale )
					factionLoadout = "TTSKOLoadout";
				else
					factionLoadout = "TTSKOLoadout";
			break;
		}

		if ( !skipPosSelection )
			spawnPos = SelectedPos;

		if ( !skipLoadoutSelection )
			loadoutType = factionLoadout;
	}

	static TVectorArray GetCivilianSpawns()
	{
		return { "2474.515869 190.759171 5221.121582",
				"2479.470215 191.753998 5221.046387",
				"2481.639648 190.843170 5245.028809",
				"2729.891846 200.718246 5186.811035"};
	}

	static TVectorArray GetChedakiSpawns()
	{
		return { "10291.471680 13.395282 2288.099609"};
	}

	static TVectorArray GetChernaSpawns()
	{
		return { "2729.811035 200.711975 5186.775879"};
	}

	static TVectorArray GetPoliceSpawns()
	{
		return { "2730.015625 200.684601 5186.806641"};
	}

	static TVectorArray GetNAPASpawns()
	{
		return { "5861.304688 139.957092 4678.910645"};
	}

	//! ============================== TRADERZONE RESTOCK SYSTEM ==============================
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
				Print("[CivilWar95]:: TRADERZONE:: IsScheaduledRestart:: TRUE");
				Print("[CivilWar95]:: Time: "+ now.GetHours() + "H "+ now.GetMinutes() + "m");
				Print("[CivilWar95]:: Target Hour: "+ schedule.Hour);
				return true;
			}
			
			Print("[CivilWar95]:: Schedule Hour: "+ schedule.Hour);
		}

		Print("[CivilWar95]:: TRADERZONE:: IsScheaduledRestart:: FALSE");
		Print("[CivilWar95]:: Time: "+ now.GetHours() + "H "+ now.GetMinutes() + "m");
		
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
