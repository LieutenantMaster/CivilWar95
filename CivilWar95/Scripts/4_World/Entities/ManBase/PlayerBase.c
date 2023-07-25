modded class PlayerBase
{
	private FrontLineManager m_FrontLineManager;

#ifndef SERVER
	void PlayerBase()
	{
		if (!IsAI())
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( CV95_DelayedInit, 1000, false );
	}

	void CV95_DelayedInit()
	{
		//m_FrontLineManager = new FrontLineManager();
		//m_FrontLineManager.CheckPlayerPosition();
	}
#endif

	#ifdef EXPANSION_MODSTORAGE
	override void CF_OnStoreSave(CF_ModStorageMap storage)
	{
		super.CF_OnStoreSave(storage);

		auto ctx = storage[DZ_CivilWar95];
		if (!ctx) return;

		ctx.Write(eAI_GetFactionTypeID());
	}
	
	override bool CF_OnStoreLoad(CF_ModStorageMap storage)
	{
		if (!super.CF_OnStoreLoad(storage))
			return false;

		auto ctx = storage[DZ_CivilWar95];
		if (!ctx) return true;

        int factionTypeID;
		if (!ctx.Read(factionTypeID))
			return false;
            
		typename factionType = eAIFaction.GetTypeByID(factionTypeID);
		if (factionType)
		{
			eAIFaction faction = eAIFaction.Cast(factionType.Spawn());
			if (faction)
			{
				if (GetGroup())
				{
					GetGroup().SetFaction(faction);
				}
				else
				{
					eAIGroup group = eAIGroup.GetGroupByLeader(this, true, faction);
				}
			}
		}

		return true;
	}
	#endif
	
	override EStatLevels GetStatLevelHealth()
	{
		float health = GetHealth("","");
		return GetStatLevel(health, 20, 40, 70, 85);
	}

#ifdef SERVER
	override void EEKilled(Object killer)
	{
		if ( IsAI() )
			return;

		string steamID = GetIdentity().GetPlainId();
		int factionID;
		string loadoutType = "DEFAULT";
		vector spawnPos = "0 0 0";

		string filename = CV95_PATH_MISSION_PLAYERDATA + steamID + ".map";

		FileHandle file;
		if (FileExist( filename ))
		{
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
					spawnPos 	= tokens.Get( 3 ).ToVector();
				}
			}
		}

		if ( factionID != eAI_GetFactionTypeID() )
			factionID = eAI_GetFactionTypeID();

		string output = factionID.ToString() + "|" + loadoutType + "|" + spawnPos.ToString();

		file = OpenFile(filename, FileMode.WRITE);
		FPrintln(file, output);
		CloseFile(file);
		
		super.EEKilled(killer);
	}
#endif
};