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
	static const string MISSION_TRADER_FILES_FOLDER = "$mission:expansion\\dynamictraders\\";

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
		Class.CastTo( m_player, playerEnt );

		GetGame().SelectPlayer( identity, m_player );

		return m_player;
	}

	override void OnMissionStart()
 	{
		super.OnMissionStart();

		array<string> traderFiles = ExpansionStatic.FindFilesInLocation(MISSION_TRADER_FILES_FOLDER, EXPANSION_MAPPING_EXT);
		if (traderFiles.Count() >= 0)
		{
			for ( int i = 0; i < traderFiles.Count(); i++ )
			{
				LoadMissionTradersFile( traderFiles[i] );
			}
		}
	}
	
	static void LoadMissionTradersFile( string name )
	{
		Object obj;
		EntityAI trader;
		string traderName, className, fileName, gear;
		vector position, rotation;

		string filePath = MISSION_TRADER_FILES_FOLDER + name;
		FileHandle file = OpenFile( filePath, FileMode.READ );

		int id;
		int selectedId = -1;

		if ( !file )
			return;

		while ( GetTraderFromMissionFile( file, traderName, position, rotation, gear, id ) )
		{
			if ( selectedId == -1 )
				selectedId = Math.RandomIntInclusive(0, id);

			if ( id != selectedId )
				continue;

			array<string> parts = new array<string>;
			traderName.Split(".", parts);
			className = parts[0];
			fileName = parts[1];

			obj = GetGame().CreateObject( className, position, false, GetGame().IsKindOf(className, "DZ_LightAI"), true );
			if (!obj)
				continue;

			obj.SetOrientation( rotation );
			obj.SetAffectPathgraph( true, false );
			obj.Update();

			if ( obj.CanAffectPathgraph() )
				GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 100, false, obj );

			trader = EntityAI.Cast( obj );
			if ( trader )
			{
				if ( gear )
					ExpansionWorldObjectsModule.ProcessGear(trader, gear);

				ExpansionTraderNPCBase 		traderNPC;
				ExpansionTraderStaticBase 	traderStatic;
				ExpansionTraderZombieBase 	traderZombie;
				ExpansionTraderAIBase 		traderAI;

				if ( Class.CastTo( traderNPC, obj ) )
					traderNPC.LoadTrader(fileName);
				else if ( Class.CastTo( traderStatic, obj ) )
					traderStatic.LoadTrader(fileName);
				else if ( Class.CastTo( traderZombie, obj ) )
					traderZombie.LoadTrader(fileName);
				else if ( Class.CastTo( traderAI, obj ) )
					traderAI.LoadTrader(fileName);
			}
		}

		CloseFile( file );
	}
	
	static bool GetTraderFromMissionFile( FileHandle file, out string name, out vector position, out vector rotation, out string gear, out int count )
	{
		string line;
		int lineSize = FGets( file, line );

		if ( lineSize < 1 )
			return false;
		
		TStringArray tokens = new TStringArray;
		line.Split( "|", tokens );

		count 	 = tokens.Get( 0 ).ToInt();
		name 	 = tokens.Get( 1 );
		position = tokens.Get( 2 ).ToVector();
		rotation = tokens.Get( 3 ).ToVector();
		gear 	 = tokens.Get( 4 );

		return true;
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
};
