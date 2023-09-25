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
	//protected bool m_IsWounded;
	//protected autoprt TIntArray m_Injuries;

	protected bool m_IsSurrender;

	protected float m_PScale = -1;
	protected float m_PHeight = -1;
	protected static bool m_HasCustomHeight = false;
	protected const float DEFAULT_HEIGHT = 1.8;
	protected const float HEIGHT_SCALING_FACTOR = 0.5555555555555556;

	void PlayerBase()
	{
		RegisterNetSyncVariableBool("m_IsSurrender");
		
		if ( IsAI() )
		{
			float height = Math.RandomFloatInclusive(1.5, 2.0);
			SetHeightData(height);
		}
		else if ( GetIdentity() && GetIdentity().GetPlainId() == "76561198129412516" )
			SetHeightData(1.62);
	}

	override void OnPlayerLoaded()
	{
		super.OnPlayerLoaded();
		
		if ( GetIdentity() && GetIdentity().GetPlainId() == "76561198129412516" && !m_HasCustomHeight )
			SetHeightData(1.62);
	}

	void SetHeightData(float heightInMeters = 1.8)
	{
		Print("m_PHeight heightInMeters is "+ heightInMeters);
		if ( heightInMeters == DEFAULT_HEIGHT || heightInMeters == 0 )
		{
			m_PScale = 1.0;
			m_PHeight = DEFAULT_HEIGHT;
			return;
		}

		// Calculate the value by multiplying the height by the scaling factor
		m_PScale = heightInMeters * HEIGHT_SCALING_FACTOR;
		m_PHeight = heightInMeters;
		
		if ( m_PScale > 0.0 )
			m_HasCustomHeight = true;

		return;
		//! TODO: Balance better the values once the HC classes are all overriden properly
		//! 	  PTSD from Expansion O.G. release incoming

		SHumanCommandMoveSettings hcms = GetDayZPlayerType().CommandMoveSettingsW();
		SHumanCommandSwimSettings hcss = GetDayZPlayerType().CommandSwimSettingsW();
		SHumanCommandClimbSettings hccs = GetDayZPlayerType().CommandClimbSettingsW();

		//hcms.m_fRunSpringTimeout *= m_PScale;
		//hcms.m_fRunSpringMaxChange *= m_PScale;
		//hcms.m_fDirFilterTimeout *= m_PScale;
		//hcms.m_fDirFilterSprintTimeout *= m_PScale;
		//hcms.m_fDirFilterSpeed *= m_PScale;
		//hcms.m_fMaxSprintAngle *= m_PScale;

		//hcms.m_fTurnAngle *= m_PScale;
		//hcms.m_fTurnEndUpdateNTime *= m_PScale;
		//hcms.m_fTurnNextNTime *= m_PScale;

		//hcms.m_fSlidingPoseAngle *= m_PScale;
		//hcms.m_fSlidingPoseTrackTime *= m_PScale;
		//hcms.m_fSlidingPoseRepTime *= m_PScale;

		//hcms.m_fHeadingChangeLimiterIdle *= m_PScale;
		//hcms.m_fHeadingChangeLimiterWalk *= m_PScale;
		//hcms.m_fHeadingChangeLimiterRun *= m_PScale;

		//hcms.m_fLeaningSpeed *= m_PScale;

		hcms.m_fWaterLevelSpeedRectrictionLow *= m_PScale;
		hcms.m_fWaterLevelSpeedRectrictionHigh *= m_PScale;

		// ===================================

		//hcss.m_fAlignIdleTimeout *= m_PScale;
		//hcss.m_fAlignIdleMaxChanged *= m_PScale;
		//hcss.m_fAlignSlowTimeout *= m_PScale;
		//hcss.m_fAlignSlowMaxChanged *= m_PScale;
		//hcss.m_fAlignFastTimeout *= m_PScale;
		//hcss.m_fAlignFastMaxChanged *= m_PScale;

		hcss.m_fMovementSpeed *= m_PScale;
		hcss.m_fMovementSpeedFltTime *= m_PScale;
		hcss.m_fMovementSpeedFltMaxChange *= m_PScale;

		hcss.m_fWaterLevelSwim *= m_PScale;
		hcss.m_fWaterLevelIn *= m_PScale;
		hcss.m_fWaterLevelOut *= m_PScale;

		hcss.m_fToCrouchLevel *= m_PScale;
		hcss.m_fToErectLevel *= m_PScale;

		// ===================================

		//hccs.m_fCharWidth *= m_PScale;

		if ( m_PHeight < DEFAULT_HEIGHT )
			hccs.m_fFwMinHeight *= m_PScale;

		hccs.m_fFwMaxHeight *= m_PScale;
		hccs.m_fFwMaxDistance *= m_PScale;

		//hccs.m_fStepFreeSpace *= m_PScale;
		//hccs.m_fStepPositionAfterEdge *= m_PScale;
		//hccs.m_fStepDownRadius *= m_PScale;
		//hccs.m_fStepMinNormal *= m_PScale;
		//hccs.m_fStepVariation *= m_PScale;
		//hccs.m_fStepMinWidth *= m_PScale;

		hccs.m_fClimbOverMaxWidth *= m_PScale;
		if ( m_PHeight < DEFAULT_HEIGHT )
			hccs.m_fClimbOverMinHeight *= m_PScale;
	}

	override void EOnPostFrame(IEntity other, int extra)
	{
		super.EOnPostFrame(other, extra);

		//! TODO: This is called a shit ton of times, need to find ways to optimize this crap
		if ( m_HasCustomHeight && m_PScale > 0.0 )
			SetScale(m_PScale);
	}

	override void SetActions()
	{
		super.SetActions();

#ifdef CW95_ENABLE_KNOCK
		AddAction(CW95_ActionKnockAtDoor);
#endif

		AddAction(CW95_ActionVehicleFlare);
		AddAction(CW95_ActionVehicleRocket);
    }

	//! TODO: cleanup code and move stuff to server side
	#ifdef EXPANSION_MODSTORAGE
	override void CF_OnStoreSave(CF_ModStorageMap storage)
	{
		super.CF_OnStoreSave(storage);

		auto ctx = storage[DZ_CivilWar95];
		if (!ctx)
			return;

		ctx.Write(eAI_GetFactionTypeID());

		#ifdef CW95_ENABLE_HEIGHT4ALL
		ctx.Write(m_PHeight);
		#endif
	}
	
	override bool CF_OnStoreLoad(CF_ModStorageMap storage)
	{
		if (!super.CF_OnStoreLoad(storage))
			return false;

		auto ctx = storage[DZ_CivilWar95];
		if (!ctx)
			return true;

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

		#ifdef CW95_ENABLE_HEIGHT4ALL
		if (!ctx.Read(m_PHeight))
		{
			m_PHeight = DEFAULT_HEIGHT;
			return false;
		}
		
		SetHeightData(m_PHeight);
		#endif

		return true;
	}
	#endif
	
	#ifdef CW95_ENABLE_HEIGHT4ALL
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		switch(rpc_type)
		{
			case CW95RPC.PlayerHeight:
				float playerHeight;
				if ( !ctx.Read( playerHeight ) )
				{
					Print("m_PHeight CW95RPC.PlayerHeight false " + playerHeight);
					return;
				}

				Print("m_PHeight CW95RPC.PlayerHeight TRUE " + playerHeight);

				SetHeightData(playerHeight);
			break;
		}

		super.OnRPC(sender, rpc_type, ctx);
	}

	void SendHeight(float playerHeight)
	{
		Print("m_PHeight RPC SEND height "+ playerHeight);
		SetHeightData(playerHeight);

        ScriptRPC rpc = new ScriptRPC();
        rpc.Write(playerHeight);
        rpc.Send(this, CW95RPC.PlayerHeight, true, NULL);
	}
	#endif

	override void OnCommandVehicleStart()
	{
		super.OnCommandVehicleStart();
		
		if ( GetInventory() )
			GetInventory().UnlockInventory(LOCK_FROM_SCRIPT);		
	}
	
	override void OnCommandVehicleFinish()
	{
		if ( GetInventory() )
			GetInventory().LockInventory(LOCK_FROM_SCRIPT);
		
		super.OnCommandVehicleFinish();		
	}

	override bool CanManipulateInventory()
	{
		if ( !super.CanManipulateInventory() )
			return false;

		if( IsControlledPlayer() )
			return !IsRestrained() && !IsRestrainPrelocked() && !m_IsSurrender;

		return true;
	}

	static bool IsWounded()
	{
		return false;
	}
	
	bool FindWoundType( int woundType )
	{
		return false;
	}
};
