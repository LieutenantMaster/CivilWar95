void main()
{
	// Uncomment this line to update the loot spawn pos for the mapping
	// You can then grab the updated XML file from the storage folder once the server started with this line
	// Please comment this line again once you are done
	//MissionServer.ExportLootData = true;
	
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

	if ( !FileExist( CW95_PATH_MISSION_PLAYERDATA ) )
		ExpansionStatic.MakeDirectoryRecursive( CW95_PATH_MISSION_PLAYERDATA );
};

class CustomMission: MissionServer
{
	//! ============================== PLAYER FACTION AND LOADOUT SYSTEM ==============================
	override void EquipCharacter(MenuDefaultCharacterData char_data)
	{
		if ( !IsMissionHost() )
		{
			super.EquipCharacter(char_data);
			return;
		}

		string steamID = m_player.GetIdentity().GetPlainId();
		string filename = CW95_PATH_MISSION_PLAYERDATA + steamID + ".map";
		FileHandle file;

		string factionName;
		vector spawnPos = "0 0 0";
		string loadoutType = "DEFAULT";
		float height = -1;

		file = OpenFile(filename , FileMode.READ );
		if ( file )
		{
			string line;
			if ( FGets( file, line ) != 0 )
			{
				TStringArray tokens = new TStringArray;
				line.Split( "|", tokens );

				factionName	= tokens.Get( 0 );
				loadoutType = tokens.Get( 1 );
				spawnPos 	= tokens.Get( 2 ).ToVector();
				if ( tokens.Count() > 3 )
					height 	= tokens.Get( 3 ).ToFloat();
			}
		}
		CloseFile(file);

		GetFactionData(factionName, m_player.IsMale(), loadoutType, spawnPos);

		if ( factionName == "" || factionName == "Civilian" )
			factionName = "Civil";
		
		typename factionType = eAIFaction.GetType(factionName);
		if (factionType)
		{
			eAIFaction faction = eAIFaction.Cast(factionType.Spawn());
			if (faction)
			{
				factionName = faction.GetName();
				if (m_player.GetGroup())
				{
					m_player.GetGroup().SetFaction(faction);
				} else {
					eAIGroup group = eAIGroup.GetGroupByLeader(m_player, true, faction);
				}
			}
		}

		TStringArray gear = new TStringArray;
		loadoutType.Split( ",", gear );
		if ( gear.Count() > 1 )
		{
			ExpansionObjectSpawnTools.ProcessGear(m_player, loadoutType);
		} else {
			ExpansionHumanLoadout.Apply(m_player, loadoutType, false);
		}

		m_player.SetPosition(spawnPos);
		m_player.SetHeightData(height);
	}

	void GetFactionData(out string factionName, bool isMale, out string loadoutType, out vector spawnPos)
	{
		string factionLoadout;
		vector SelectedPos;

		bool skipPosSelection = spawnPos != "0 0 0";
		bool skipLoadoutSelection = loadoutType != "DEFAULT";

		switch(factionName)
		{
			case "": // New Player !
				factionName = "Civilian";
				SelectedPos = "2474.515869 190.759171 5221.121582";
				if ( isMale )
					factionLoadout = "PlayerSurvivorLoadout";
				else
					factionLoadout = "PlayerSurvivorLoadout";
				break;
			default:
			case "Civil":
			case "Civilian":
				SelectedPos = "2760.51 206.098 5175.6";
				if ( isMale )
					factionLoadout = "AthleticShoes_Brown,Jeans_Wounded,TShirt_White,Ragged_Eyepatch,HeadCover_Improvised";
				else
					factionLoadout = "AthleticShoes_Brown,Jeans_Wounded,TShirt_White,Ragged_Eyepatch,HeadCover_Improvised";
				break;
			case "Partizan": // add for chedaki partizan respawn 
				SelectedPos = "10283 16.583 2287.63";
				if ( isMale )
					factionLoadout = "AthleticShoes_Brown,Jeans_Wounded,TShirt_White,Ragged_Eyepatch,HeadCover_Improvised";
				else
					factionLoadout = "AthleticShoes_Brown,Jeans_Wounded,TShirt_White,Ragged_Eyepatch,HeadCover_Improvised";
				break;
			case "Pompier":
				SelectedPos = "2760.51 206.098 5175.6";
				if ( isMale )
					factionLoadout = "AthleticShoes_Brown,Jeans_Wounded,TShirt_White,Ragged_Eyepatch,HeadCover_Improvised";
				else
					factionLoadout = "AthleticShoes_Brown,Jeans_Wounded,TShirt_White,Ragged_Eyepatch,HeadCover_Improvised";
				break;
			case "Police":
				SelectedPos = "2730.015625 200.684601 5186.806641";
				if ( isMale )
					factionLoadout = "AthleticShoes_Brown,Jeans_Wounded,TShirt_White,Ragged_Eyepatch,HeadCover_Improvised";
				else
					factionLoadout = "AthleticShoes_Brown,Jeans_Wounded,TShirt_White,Ragged_Eyepatch,HeadCover_Improvised";
				break;
			case "Medecin":
			case "Medic":
				SelectedPos = "2729.891846 200.718246 5186.811035";
				if ( isMale )
					factionLoadout = "AthleticShoes_Brown,Jeans_Wounded,TShirt_White,Ragged_Eyepatch,HeadCover_Improvised";
				else
					factionLoadout = "AthleticShoes_Brown,Jeans_Wounded,TShirt_White,Ragged_Eyepatch,HeadCover_Improvised";
				break;
			case "Militaire":
				SelectedPos = "2729.811035 200.711975 5186.775879";
				if ( isMale )
					factionLoadout = "TTSKOBoots,Armband_CDF,TTSKOPants,Ragged_Eyepatch,HeadCover_Improvised,TShirt_Beige";
				else
					factionLoadout = "TTSKOBoots,Armband_CDF,TTSKOPants,Ragged_Eyepatch,HeadCover_Improvised,TShirt_Beige";
				break;
			case "Napa":
				SelectedPos = "5752.89 117.377 4591.47";
				if ( isMale )
					factionLoadout = "AthleticShoes_Brown,Jeans_Wounded,TShirt_White,Ragged_Eyepatch,HeadCover_Improvised";
				else
					factionLoadout = "AthleticShoes_Brown,Jeans_Wounded,TShirt_White,Ragged_Eyepatch,HeadCover_Improvised";
				break;
			case "Chedaki":
				SelectedPos = "10283 16.583 2287.63";
				if ( isMale )
					factionLoadout = "TTSKOBoots,Armband_Chedaki,BDUPants,Ragged_Eyepatch,HeadCover_Improvised,TShirt_Green";
				else
					factionLoadout = "TTSKOBoots,Armband_Chedaki,BDUPants,Ragged_Eyepatch,HeadCover_Improvised,TShirt_Green";
				break;
		}

		if ( !skipPosSelection )
			spawnPos = SelectedPos;

		if ( !skipLoadoutSelection )
			loadoutType = factionLoadout;
	}

	//! ============================== TRADERZONE RESTOCK SYSTEM ==============================	
	override void UpdateTraderZones()
	{
		int CityRestockPercent = 10;
		int LocalRestockPercent = 3;

		IncrementStockForTraderzonePos("2640 200 5175", CityRestockPercent); 	// Zelenogorsk
		IncrementStockForTraderzonePos("6510 0 2550", LocalRestockPercent); 	// Chernogorsk
		IncrementStockForTraderzonePos("10453 13 2393", LocalRestockPercent); 	// Elecktro
		IncrementStockForTraderzonePos("9519 5 2005", LocalRestockPercent); 	// Elecktro StationService
		
		IncrementStockForTraderzonePos("4995 9 2476", LocalRestockPercent); 	// Balota
		IncrementStockForTraderzonePos("6078 158 4914", LocalRestockPercent); 	// Nadez
		IncrementStockForTraderzonePos("6930 18 1694", LocalRestockPercent); 	// ONU
	}

	override bool IsScheaduledRestart()
	{
		CF_Date now = CF_Date.Now();
		
		int hour = now.GetHours();
		int minute = now.GetMinutes();

		if ( (hour > 6 && hour < 9) || (hour > 14 && hour < 17) || (hour > -1 || hour < 24) )
		{
			if ( minute < 10 || minute > 50 )
			{
				Print("[CivilWar95]:: TRADERZONE:: IsScheaduledRestart:: TRUE");
				Print("[CivilWar95]:: Time: "+ hour + "H "+ minute + "m");
				return true;
			}
		}

		Print("[CivilWar95]:: TRADERZONE:: IsScheaduledRestart:: FALSE");
		Print("[CivilWar95]:: Time: "+ hour + "H "+ minute + "m");
		
		return false;
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
};
