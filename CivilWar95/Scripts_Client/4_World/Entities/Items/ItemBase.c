/**
 * ItemBase.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class ItemBase
{	
	static const float MAX_SOUND_RANGE = 5; // Mainly in place to stop bleed at long range
	static const float MIN_SOUND_VOLUME = 0.6;
	static const float MAX_SOUND_VOLUME = 1.0;
	static const int MAX_ITEM_AREA = 6;

	bool IsPlayBackDevice()
	{
		return false;
	}

	bool GetEmptyItemReplacement(out string typeName)
	{
		//! TODO: Add in config.cpp a entry about item replacement to then scan here and return
		GetGame().ConfigGetText("cfgVehicles" + " " + GetType() + " "+ "EmptyReplaceWith", typeName);
		return typeName != "";
	}

	bool ReplaceWithEmpty()
	{
		string typeName;
		if (GetEmptyItemReplacement(typeName))
		{
			PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
			if (player)
			{
				TurnItemIntoItemLambda lambda = new TurnItemIntoItemLambda(this, typeName, player);
				return player.ServerReplaceItemInHandsWithNew(lambda);
			}
		}

		return false;
	}
	
#ifndef SERVER
	override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		super.EEItemLocationChanged(oldLoc, newLoc);
		
		if (!oldLoc || !newLoc)
			return;

		if (oldLoc.GetType() == InventoryLocationType.UNKNOWN || newLoc.GetType() == InventoryLocationType.UNKNOWN)
			return;

		if (oldLoc.GetType() == InventoryLocationType.HANDS && newLoc.GetType() == InventoryLocationType.ATTACHMENT)
			return;

		if (oldLoc.GetType() == InventoryLocationType.ATTACHMENT && newLoc.GetType() == InventoryLocationType.HANDS)
			return;

		if (!GetGame().GetPlayer())
			return;

		float distance = vector.Distance(GetPosition(), GetGame().GetPlayer().GetPosition());
		
		if (distance > MAX_SOUND_RANGE)
			return;

		array<string> sounds = {};
		ConfigGetTextArray("ItemMoveSounds", sounds);

		float volumeMin = MIN_SOUND_VOLUME;
		float volumeMax = MAX_SOUND_VOLUME;

		if ( ConfigIsExisting("ItemMoveMinVolume") )
			volumeMin = ConfigGetFloat("ItemMoveMinVolume");

		if ( ConfigIsExisting("ItemMoveMaxVolume") )
			volumeMax = ConfigGetFloat("ItemMoveMaxVolume");

		array<string> pathNames = {"CfgVehicles","CfgWeapons","CfgMagazines","CfgAmmo"};
		array<string> soundSets = {"pickUpItem","pickUpItem_Light","pickup","drop"};
		
		for(int i=0; i < pathNames.Count(); i++)
		{
			if ( GetGame().ConfigIsExisting(pathNames[i] + " " + GetName()) )
				continue;

			string path = pathNames[i] + " " + GetName() + "AnimEvents SoundWeapon";

			for(int j=0; j < soundSets.Count(); j++)
			{
				if (GetGame().ConfigIsExisting(path +" "+ soundSets[j] +" soundSet"))
				{
					string soundName = "";
					GetGame().ConfigGetText(path +" "+ soundSets[j] +" soundSet", soundName);

					string debug_path = path +" "+ soundSets[j] +" soundSet";

					if ( soundName != "" )
						sounds.Insert(soundName);
				}
			}
		}
		distance = distance / MAX_SOUND_RANGE;
		if ( distance < 1 )
			distance = 1;
		
		float volume = Math.Clamp(GetItemArea() / MAX_ITEM_AREA, volumeMin, volumeMax);
		volume = volume / distance;
		EffectSound sound = SEffectManager.CreateSound(sounds.GetRandomElement(), GetPosition());
		if (sound)
		{
			sound.SetSoundAutodestroy(true);
			sound.SoundPlay();
			if (sound.CW95_GetWave())
				sound.CW95_GetWave().SetVolume(volume);
		}
	}
#endif
	
	int GetItemArea()
	{
		int area = 1;
		TIntArray item_size = {};
		ConfigGetIntArray("itemSize", item_size);
		foreach (int item_s: item_size)
		{
			area *= item_s;
		}
		
		return area;
	}
	
	override void UnlockAndOpen( string selection ) 
	{
		super.UnlockAndOpen(selection);

		ExpansionLock();
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if ( !m_Initialized )
			return true;

		if (ExpansionIsLocked() && m_Expansion_IsOpenable)
			return ExpansionIsOpened();

		return super.CanReceiveAttachment(attachment, slotId);
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		if ( !m_Initialized )
			return true;

		if (ExpansionIsLocked() && m_Expansion_IsOpenable)
			return ExpansionIsOpened();

		return super.CanReceiveItemIntoCargo(item);
	}

	override bool CanReleaseAttachment(EntityAI attachment)
	{
		if ( !m_Initialized )
			return true;

		if ( attachment.IsInherited(ExpansionCodeLock) )
			return !ExpansionIsLocked();

		if (ExpansionIsLocked() && m_Expansion_IsOpenable)
			return ExpansionIsOpened();

		return super.CanReleaseAttachment(attachment);
	}

    override bool CanReleaseCargo(EntityAI cargo)
	{
		if ( !m_Initialized )
			return true;

		if (ExpansionIsLocked() && m_Expansion_IsOpenable)
			return ExpansionIsOpened();

		return super.CanReleaseCargo(cargo);
	}
};

modded class ExpansionWallBase
{
	override void UnlockAndOpen( string selection ) 
	{
		super.UnlockAndOpen(selection);

		ExpansionLock();
	}
};