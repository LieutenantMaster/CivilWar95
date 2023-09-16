/**
 * PlayerBase.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class PlayerBase
{
	private ref FrontLineManager m_FrontLineManager;
	
	ref Timer m_UpdateTimer;

	protected bool m_WasSurrender;

#ifdef DIAG
#ifndef SERVER
	void PlayerBase()
	{
		if (!IsAI())
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( CW95_DelayedInit, 1000, true );
	}
	
	void CW95_DelayedInit()
	{
		m_FrontLineManager = new FrontLineManager();
		m_FrontLineManager.CheckPlayerPosition();
	}
#endif
#endif
	
	void ~PlayerBase()
	{
		if ( m_UpdateTimer )
		{
			m_UpdateTimer.Stop();
			delete m_UpdateTimer;
		}
	}
	
	override void Init()
	{
		super.Init();
		
		m_UpdateTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
		m_UpdateTimer.Run( 0.1, this, "UpdateSurrender", NULL, true );
	}

	void UpdateSurrender()
	{
		if ( m_EmoteManager && m_EmoteManager.m_Callback )
		{
			if (m_EmoteManager.m_Callback.m_callbackID == 1113)
				m_IsSurrender = true;
			else if (m_EmoteManager.m_Callback.m_callbackID == 1114)
				m_IsSurrender = false;

			if ( m_WasSurrender != m_IsSurrender )
			{
				m_WasSurrender = m_IsSurrender;
				SetSynchDirty();
			}
		}
	}

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
		string factionName;
		string loadoutType = "DEFAULT";
		vector spawnPos = "0 0 0";

		string filename = CW95_PATH_MISSION_PLAYERDATA + steamID + ".map";

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

					factionName	= tokens.Get( 0 );
					loadoutType = tokens.Get( 1 );
					spawnPos 	= tokens.Get( 3 ).ToVector();
				}
			}
			CloseFile(file);
		}

		if ( GetGroup() )
		{
			if ( factionName != GetGroup().GetFaction().GetName() )
				factionName = GetGroup().GetFaction().GetName();
		}

		if ( factionName == "" )
			factionName = "Civilian";

		string primaryData 		= factionName + 			"|" + loadoutType + 		  "|" + spawnPos.ToString();
		string secondaryData 	= GetIdentity().GetName() + "|" + GetIdentity().GetId() + "|" + steamID;

		file = OpenFile(filename, FileMode.WRITE);
		FPrintln(file, primaryData);
		FPrintln(file, secondaryData);
		CloseFile(file);
		
		super.EEKilled(killer);
	}
#endif
};