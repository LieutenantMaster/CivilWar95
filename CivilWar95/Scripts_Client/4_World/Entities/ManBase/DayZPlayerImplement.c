/**
 * DayZPlayerImplement.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class DayZPlayerImplement
{
	// Used to delay unlocking 3PP mode after using a restricted item or entering a restricted area
	protected ref Timer m_UnlockViewTimer;

	// Tracks if the player's camera has been restricted or not
	bool m_RestrictedView = false;

	protected bool m_AS_IsSoundSynchServer;
	protected bool m_AS_IsSoundSynchClient;

	protected bool m_ZS_IsSoundSynchServer;
	protected bool m_ZS_IsSoundSynchClient;
	protected bool m_ZS_IsZooming;

	static const float MIN_SOUND_VOLUME = 0.5;
	static const float MAX_SOUND_VOLUME = 1.1;
	static const int MAX_ITEM_AREA = 6;

	void DayZPlayerImplement()
	{
		RegisterNetSyncVariableBool("m_AS_IsSoundSynchServer");
		RegisterNetSyncVariableBool("m_ZS_IsSoundSynchServer");
		RegisterNetSyncVariableBool("m_ZS_IsZooming");
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if ( !m_Initialized )
			return;
		
		if ( m_AS_IsSoundSynchClient != m_AS_IsSoundSynchServer )
		{
			m_AS_IsSoundSynchClient = m_AS_IsSoundSynchServer;
#ifndef SERVER
			bool exit = !m_IsFireWeaponRaised;

			Weapon_Base weapon;
			if (!Class.CastTo(weapon, GetHumanInventory().GetEntityInHands()))
				return;

			PlayAimSound(weapon, exit);
#endif
		}
		
		if ( m_ZS_IsSoundSynchClient != m_ZS_IsSoundSynchServer )
		{
			m_ZS_IsSoundSynchClient = m_ZS_IsSoundSynchServer;
#ifndef SERVER
			PlayZoomSound();
#endif
		}
	}

	override void HandleWeapons(float pDt, Entity pInHands, HumanInputController pInputs, out bool pExitIronSights)
	{
		super.HandleWeapons(pDt, pInHands, pInputs, pExitIronSights);

		Weapon_Base weapon;
		if (!Class.CastTo(weapon, pInHands))
			return;

		if (m_IsFireWeaponRaised != m_RaiseStarted)
			SendAimSound();
	}

	override void HandleOptic(notnull ItemOptics optic, bool inHands, HumanInputController pInputs, out bool pExitOptics)
	{
		float FOVStep = optic.GetCurrentStepFOV();

		super.HandleOptic(optic, inHands, pInputs, pExitOptics);

		if ( FOVStep != optic.GetCurrentStepFOV() )
		{
			float fovdiff = FOVStep - optic.GetCurrentStepFOV();
			SendZoomSound(fovdiff > 0);
		}
	}

	void SendZoomSound(bool isZoomIn)
	{
		m_ZS_IsZooming = isZoomIn;
		m_ZS_IsSoundSynchServer = !m_ZS_IsSoundSynchServer;
		SetSynchDirty();
	}
	
	void SendAimSound()
	{
		m_AS_IsSoundSynchServer = !m_AS_IsSoundSynchServer;
		SetSynchDirty();
	}

	protected void PlayAimSound(Weapon_Base weapon, bool exit)
	{
		float distance = vector.Distance(GetPosition(), GetGame().GetPlayer().GetPosition());
		if ( distance < 10 )
		{			
			string sound_set = GetAimSoundSet(weapon, exit);

			EffectSound sound;
			PlaySoundSet(sound, sound_set, 0, 0);
			sound.SetSoundAutodestroy(true);

			distance = 1 - (0.1 * distance);
		
			float volume = Math.Clamp(weapon.GetWeightEx() / MAX_ITEM_AREA, MIN_SOUND_VOLUME, MAX_SOUND_VOLUME);
			volume = volume / distance;

			sound.SetSoundVolume(volume);
		}
	}

	protected void PlayZoomSound()
	{
		float distance = vector.Distance(GetPosition(), GetGame().GetPlayer().GetPosition());
		if ( distance < 10 )
		{
			string sound_set;
			if ( m_ZS_IsZooming )
				sound_set = "zoom_in_Base_SoundSet";
			else
				sound_set = "zoom_out_Base_SoundSet";

			EffectSound sound;
			PlaySoundSet(sound, sound_set, 0, 0);
			sound.SetSoundAutodestroy(true);

			distance = 1 - (0.1 * distance);
			sound.SetSoundVolume(distance);
		}
	}

	protected string GetAimSoundSet(Weapon_Base weapon, bool exit)
	{
		string sound_set;

		if (!weapon)
		{
			if (exit)
				return CW95_AS_DEFAULT_SOUNDSET + CW95_AS_SOUNDSET_OUT;
			else
				return CW95_AS_DEFAULT_SOUNDSET + CW95_AS_SOUNDSET_IN;
		}

		sound_set = weapon.ConfigGetString(CW95_AS_CONFIG_ENTRY);

		// Fallback - predict sound set
		if (!sound_set || sound_set.Length() == 0)
			sound_set = PredictAimSoundSet(weapon);

		if (exit)
			return sound_set + CW95_AS_SOUNDSET_OUT;
		else
			return sound_set + CW95_AS_SOUNDSET_IN;
	}

	protected string PredictAimSoundSet(Weapon_Base weapon)
	{
		if (!weapon)
			return CW95_AS_DEFAULT_SOUNDSET;

		if (weapon.IsInherited(Pistol_Base) || weapon.IsInherited(Magnum_Base))
			return "FNX45";

		if (weapon.IsInherited(BoltActionRifle_InnerMagazine_Base))
			return "Mosin";
		
		if (weapon.IsInherited(BoltActionRifle_Base) || weapon.IsInherited(DoubleBarrel_Base))
			return "CR527";

		string cartridge_type = weapon.GetChamberAmmoTypeName(weapon.GetCurrentMuzzle());

		if (cartridge_type.Contains("12ga"))
			return "Saiga";

		if (cartridge_type.Contains("762x54") || cartridge_type.Contains("308Win"))
			return "SVD";
		
		if (cartridge_type.Contains("Ammo_380"))
			return "CZ61";
		
		if (cartridge_type.Contains("9x39"))
			return "VSS";

		return CW95_AS_DEFAULT_SOUNDSET;
	}

	// Check for weapon in hands
	override void HandleView()
	{
		// If running on the server or on a 1PP server, just pass to super
		#ifndef SERVER
		if (GetGame().GetWorld().Is3rdPersonDisabled())
		#endif
		{
			super.HandleView();
			return;
		}

		// This is necessary because if the player types in chat (for example) it will unlock view key again. Wait til timer ends to unlock key.
		if (m_RestrictedView && m_UnlockViewTimer && m_UnlockViewTimer.IsRunning())
		{
			// Ensure camera is locked and view key is disabled
			GetUApi().GetInputByName("UAPersonView").Lock();
			m_Camera3rdPerson = false;

			// Pass to super
			super.HandleView();
			return;
		}

		// Check if player is within a restricted zone
		if (IsInRestrictedArea())
			RestrictView();

		// No item in hands
		if (!GetHumanInventory().GetEntityInHands())
		{
			// Unlock view key input immediately if timer is not set
			if (GetSharedSettings().RestrictionTime <= 0 || !m_UnlockViewTimer || !m_UnlockViewTimer.IsRunning())
			{
				GetUApi().GetInputByName("UAPersonView").Unlock();
				m_RestrictedView = false;
			}

			// Pass to super
			super.HandleView();
			return;
		}

		// No weapon item found in hands and player is not in restricted area - Unlock view key input immediately if timer is not set.
		if (GetSharedSettings().RestrictionTime <= 0 || !m_UnlockViewTimer || !m_UnlockViewTimer.IsRunning())
		{
			GetUApi().GetInputByName("UAPersonView").Unlock();
			m_RestrictedView = false;
		}

		// Finished checking for view lock - pass to super.
		super.HandleView();
	}

	// Restrict the player's view mode
	private void RestrictView()
	{
		// Lock to 1PP view and block view key input
		GetUApi().GetInputByName("UAPersonView").Lock();
		m_Camera3rdPerson = false;
		m_RestrictedView = true;

		// Only called if there is a delay on 3PP view restrictions, otherwise view is instantly unlocked
		if (GetSharedSettings().RestrictionTime > 0)
			ResetViewLockTimer();
	}

	// Reset the view unlock timer
	private void ResetViewLockTimer()
	{
		if (!m_UnlockViewTimer)
			m_UnlockViewTimer = new Timer();

		if (m_UnlockViewTimer.IsRunning())
			m_UnlockViewTimer.Stop();

		m_UnlockViewTimer.Run(GetSharedSettings().RestrictionTime, this, "ZenUnlockViewKey");
	}

	// Unlock 3pp view key
	private void ZenUnlockViewKey()
	{
		// If player still has a restricted item or is in a restricted area, stop here and reset timer.
		if (IsInRestrictedArea())
		{
			ResetViewLockTimer();
			return;
		}

		GetUApi().GetInputByName("UAPersonView").Unlock();
		m_RestrictedView = false;
	}

	// Check for restricted areas
	private bool IsInRestrictedArea()
	{
		// If there are no zones just stop here to save time
		if (GetSharedSettings().ConflictZones.Count() == 0)
			return false;

		// Get our position and check it against all zones
		vector myPos = GetPosition();

		for (int i = 0; i < GetSharedSettings().ConflictZones.Count(); i++)
		{
			CW95ConflictZone area = GetSharedSettings().ConflictZones.Get(i);

			if (area.CheckZone(myPos))
				return true;
		}

		// No zone found - we're good.
		return false;
	}
};
