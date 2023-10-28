modded class MissionServer
{
	ref array<string> m_SteamIDs;
	
	void MissionServer()
	{
		m_SteamIDs = new array<string>;
	}

	override void TickScheduler(float timeslice)
	{
		super.TickScheduler(timeslice);

		// We reset
		m_SteamIDs = new array<string>;
		foreach (Man juan: m_Players)
		{
			if ( !juan.GetIdentity() )
				continue;

			m_SteamIDs.Insert(juan.GetIdentity().GetPlainId());
		}
	}

	//! ==================================== ARTY ====================================
	override void OnInit()
	{
		super.OnInit();

		// Start between 1 second and 1 hour
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( InitArty, Math.RandomIntInclusive(1000, 360000), false );

		// 60 secs
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( OnCheckOnlinePlayers, 60000, true );
	}

	void InitArty()
	{
		m_PlayArty 				 = true;
		m_ArtyDelay 			 = Math.RandomFloatInclusive(1000, 4000);
		m_MinSimultaneousStrikes = Math.RandomIntInclusive(2, 6);
		m_MaxSimultaneousStrikes = Math.RandomIntInclusive(m_MinSimultaneousStrikes, 10);

		m_FiringPos = CHERNARUS_STRIKE_POS;
	}

	//! ============================== WHITELIST SYSTEM ==============================
	override void OnEvent(EventType eventTypeId, Param params) 
	{
		switch (eventTypeId)
		{
			case ClientNewEventTypeID:
			{
				ClientNewEventParams newParams;
				Class.CastTo(newParams, params);
				PlayerIdentity identity = newParams.param1;
				string steamid = identity.GetPlainId();

				if ( FindInFile( "$profile:CW95\\Data\\blacklist.txt", steamid ) )
				{
					Print("[CivilWar95]:: LOGIN:: Blacklist:: Connection denied to the player " + steamid);
					OnClientDisconnectedEvent(identity, NULL, 0, true);
					return;
				}

				if ( !FindInFile( "$profile:CW95\\Data\\whitelist.txt", steamid ) )
				{
					Print("[CivilWar95]:: LOGIN:: Whitelist:: Connection denied to the player " + steamid);
					OnClientDisconnectedEvent(identity, NULL, 0, true);
					return;
				}
				Print("[CivilWar95]:: LOGIN:: Connection granted to the player " + steamid);
			}
			break;
		}
		
		super.OnEvent(eventTypeId, params);
	}

	void OnCheckOnlinePlayers()
	{
		WriteFile( "$profile:CW95\\Data\\online.txt", m_SteamIDs );
		
		array<string> discordUsers = new array<string>;
		array<string> steamids = new array<string>;
		array<string> username = new array<string>;
		if ( ReadFile( "$profile:CW95\\Data\\discord_online.txt", discordUsers ) )
		{
			foreach(string discordUser: discordUsers)
			{
				array<string> tokens = new array<string>;
				discordUser.Split( "|", tokens );

				steamids.Insert(tokens.Get( 0 ));
				username.Insert(tokens.Get( 1 ));
			}
		}

		return;
		
		foreach (Man juan: m_Players)
		{
			if ( !juan || !juan.GetIdentity() )
				continue;

			// Dont check dead players just in case
			if ( !juan.IsAlive() )
				continue;

			string playerSteamId = juan.GetIdentity().GetPlainId();
			int userStatus = 1;
			for (int i=0; i < steamids.Count(); i++)
			{
				if (steamids[i] == playerSteamId)
				{
					if ( username[i] == "ADMIN" || username[i] == juan.GetIdentity().GetName() )
					{
						userStatus = 0;
					} else {
						userStatus = 2;
					}
					break;
				}
			}

			if ( userStatus != 0 )
			{
				switch(userStatus)
				{
					case 1:
						Print("[CivilWar95]:: AUTO-KICK:: Player "+ juan.GetIdentity().GetName() + " (steamid:" + playerSteamId+") is not on discord");
					break;
					case 2:
						Print("[CivilWar95]:: AUTO-KICK:: Player "+ juan.GetIdentity().GetName() + " (steamid:" + playerSteamId+") has a different name on discord ("+ username[i] +")");
					break;
				}

				//GetGame().SendLogoutTime(juan, 0);
				//PlayerDisconnected(juan, juan.GetIdentity(), juan.GetIdentity().GetId());
			}
		}
	}

	static bool WriteFile( string filePath, array<string> lines )
	{
		FileHandle file = OpenFile( filePath, FileMode.WRITE );

		if ( !file )
		{
			Print("[CivilWar95]:: WriteFile:: ERROR !!!! Couldn't find " + filePath);
			return false;
		}

		foreach(string line: lines)
		{
			FPrintln(file, line);
		}

		CloseFile( file );
		return true;
	}

	static bool ReadFile( string filePath, out array<string> lines )
	{
		FileHandle file = OpenFile( filePath, FileMode.READ );

		if ( !file )
		{
			Print("[CivilWar95]:: ReadFile:: ERROR !!!! Couldn't find " + filePath);
			return false;
		}

		string line;
		while ( FGets( file, line ) >= 1 )
		{
			lines.Insert(line);
		}

		CloseFile( file );
		return true;
	}

	static bool FindInFile( string filePath, string keyword )
	{
		FileHandle file = OpenFile( filePath, FileMode.READ );

		if ( !file )
		{
			Print("[CivilWar95]:: FindInFile:: ERROR !!!! Couldn't find " + filePath);
			return false;
		}

		string word;
		while ( FGets( file, word ) >= 1 )
		{
			if ( keyword == word )
			{
				CloseFile( file );
				return true;
			}
		}

		CloseFile( file );
		return false;
	}

	//! ============================== TRADERZONE RESTOCK SYSTEM ==============================
	override void OnMissionStart()
 	{
		super.OnMissionStart();

		if ( IsScheaduledRestart() )
			UpdateTraderZones();
	}

    void UpdateTraderZones()
    {

    }

	bool IsScheaduledRestart()
	{		
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
