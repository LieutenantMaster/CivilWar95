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

	private ItemBase m_VirtualCompassItem;

#ifdef DIAG
#ifndef SERVER
	void PlayerBase()
	{
		if (!IsAI())
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( CW95_DelayedInit, 1000, false );
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
		if ( m_VirtualCompassItem )
			HideVirtualCompass();
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(CV95_ActionKnockAtDoor);
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

	private void UpdateVirtualCompass()
	{
		// the camera position is not aligned to the player view so we manualy correct it with this values.
		vector cam_pos = GetGame().GetCurrentCameraPosition() - Vector(0,0.1,0) + Vector(0.05,0,0);
		// the camera direction, can be converted into angles for the rotation.
		// directions goes from -1 to 1
		// angles goes from -360 to 360
		vector cam_dir = GetGame().GetCurrentCameraDirection() - Vector(0,0.1,0) + Vector(0.05,0,0);
		// converted direction into angles
		vector cam_angles = cam_dir.VectorToAngles();
		// we take the position of the camera and add the camera direction multiplied to create this distance between the camera and the object
		// 0.25 is the value you should change if you want the compass to be further away or closer to the camera
		vector obj_pos = cam_pos + cam_dir * 0.25;
		// not required but can prevent some basic mistakes
		vector obj_rot = vector.Zero;

		// by default the compass will not look at you, it need to be rotated -90 degrees to look at you
		obj_rot[0] = cam_angles[0] - 90;
		// since cam_dir (and cam_angles) are 2d vector, this is how it should be to make the compass rotate up and down
		// we make the final value negative so when we look up, it will look down, toward us
		// the 45 is to angle the compass better toward us, for better readability
		obj_rot[2] = -(cam_angles[1] + 45);

		m_VirtualCompassItem.SetPosition( obj_pos );
		m_VirtualCompassItem.SetOrientation( obj_rot );
	}

	void ShowVirtualCompass(string type)
	{
		// we want it to run only on the client side
		if ( IsMissionClient() )
		{
			if ( type != "")
			{
				// we spawn the compass at the player feets and use flags to let the game know it has no lifetime and is local (client sided) once again just to be safe
				m_VirtualCompassItem = ItemBase.Cast( GetGame().CreateObjectEx( type, GetPosition(), ECE_NOLIFETIME|ECE_LOCAL ) );
				// if the compass can be closed, we make sure it will be opened so the player can use the compass properly
				m_VirtualCompassItem.Open();
				// we remove the ability to take the item
				m_VirtualCompassItem.SetTakeable(false);
				
				// and finaly we make a call later for this function. It will be used to update the position and orientation of the compass only
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.UpdateVirtualCompass, 1, true);
			}
		}
	}

	void HideVirtualCompass()
	{
		if ( IsMissionClient() )
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(this.UpdateVirtualCompass);

			if ( m_VirtualCompassItem )
				m_VirtualCompassItem.Delete();
		}
	}

	string HasCompass()
	{
		//Get first compass from player inventory
		for ( int att_i = 0; att_i < GetInventory().AttachmentCount(); ++att_i )
		{
			EntityAI attachment = GetInventory().GetAttachmentFromIndex( att_i );
			ref CargoBase attachment_cargo = attachment.GetInventory().GetCargo();
			
			if ( attachment_cargo )
			{
				for ( int cgo_i = 0; cgo_i < attachment_cargo.GetItemCount(); ++cgo_i )
				{
					EntityAI cargo_item = attachment_cargo.GetItem( cgo_i );

					//check if item is a compass
					if ( cargo_item.IsKindOf("ItemCompass") || cargo_item.GetType() == "Compass" || cargo_item.GetType() == "OrienteeringCompass" )
					{
						return cargo_item.GetType();
					}
				}
			}
		}
		return "0";
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