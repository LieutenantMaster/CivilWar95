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
	protected const float DEFAULT_SCALE = 1.0;

	protected bool CW95_IsAtZeleno;

	// Visual FX variables
	private static const float DEFAULT_SPAWNFX_DURATION = 500;
	private float m_IL_m_SpawnDarkeningCurrentTime;
	private ref PPERequester_CW95SpawnEffects m_IL_ppeEffect;

	autoptr TVectorArray m_InteractedPositions;
	autoptr TIntArray m_TimeStampPositions;

	void PlayerBase()
	{
		m_InteractedPositions = new TVectorArray;
		m_TimeStampPositions = new TIntArray;
		if ( !IsAI() )
		{
			RegisterNetSyncVariableBool("m_IsSurrender");
			RegisterNetSyncVariableFloat("m_PScale", 0.7, 1.2);
		}
	}

	override void OnPlayerLoaded()
	{
		super.OnPlayerLoaded();

#ifndef SERVER
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ZenLoginBegin);
#endif
	}


	override void EOnPostFrame(IEntity other, int extra)
	{
		super.EOnPostFrame(other, extra);

		if ( m_PScale > 0.7 && m_PScale < 1.2 )
			SetScale(m_PScale);
	}

	bool IsPlayerAtZeleno()
	{
		return CW95_IsAtZeleno;
	}

	void SetPlayerAtZeleno(bool state)
	{
		CW95_IsAtZeleno = state;
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

	protected void ZenLoginBegin()
	{
		if (!IsControlledPlayer())
			return;

		if (ZenImmersiveLoginCancelFX())
			return;

		// This is our player object and we're fine, close eyes & lie down
		ZenImmersiveLogin();
	}

	protected bool ZenImmersiveLoginCancelFX()
	{
		return IsRestrained() || IsUnconscious() || IsFalling() || !IsAlive() || IsSwimming();
	}

	protected void ZenImmersiveLogin()
	{
		if (!GetEmoteManager() || GetEmoteManager().IsEmotePlaying())
			return;

		// Lie down or sit if lie-down emote is unavailable (eg. player is in shallow water or a tight space)
		if (GetEmoteManager().CanPlayEmote(EmoteConstants.ID_EMOTE_LYINGDOWN))
		{
			GetEmoteManager().CreateEmoteCBFromMenu(EmoteConstants.ID_EMOTE_LYINGDOWN);
		} else {
			GetEmoteManager().CreateEmoteCBFromMenu(EmoteConstants.ID_EMOTE_SITA);
			GetEmoteManager().GetEmoteLauncher().SetForced(EmoteLauncher.FORCE_DIFFERENT);
		}

		if (m_Hud)
			m_Hud.ShowQuickbarPlayer(false);

		// Create blackout screen effect
		m_IL_m_SpawnDarkeningCurrentTime = DEFAULT_SPAWNFX_DURATION;
		m_IL_ppeEffect = PPERequester_CW95SpawnEffects.Cast(PPERequesterBank.GetRequester(PPERequester_CW95SpawnEffects));

		if (!m_IL_ppeEffect)
			return;

		m_IL_ppeEffect.SetEffectValues(200);
		GetGame().GetSoundScene().SetSoundVolume(0, 0);

		// Schedule "wake up" 6 seconds after player loads
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ZenLoginOpenEyesClient, 6000, false);
	}

	// Trigger eye-open fx and enable sound
	protected void ZenLoginOpenEyesClient()
	{
		// Start opening eyes fx, and slowly fade-in volume over 5 secs
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ZenLoginUpdateSpawnDarknessLevel, 1, false);
		GetGame().GetSoundScene().SetSoundVolume(g_Game.m_volume_sound, 5);
	}

	// Simulate Spawn visual effect
	protected void ZenLoginUpdateSpawnDarknessLevel()
	{
		// Check fx PPE
		if (!m_IL_ppeEffect)
			return;

		// Calculate vignette percentage
		float percentage = Math.Lerp(0, 2, 1 - ((DEFAULT_SPAWNFX_DURATION - m_IL_m_SpawnDarkeningCurrentTime) / DEFAULT_SPAWNFX_DURATION));

		// Decrease fx timer
		m_IL_m_SpawnDarkeningCurrentTime -= 1;
		m_IL_ppeEffect.SetEffectValues(percentage);

		// If animation of opening eyes is over, stop updating.
		if (percentage <= 0 || ZenImmersiveLoginCancelFX())
		{
			// If our eyes are no longer shut, remove the Spawn requester effect altogether
			if (m_IL_ppeEffect)
			{
				m_IL_ppeEffect.SetEffectValues(0);
				m_IL_ppeEffect.Stop();
				m_IL_ppeEffect = null;
			}

			// Stop update loop
			return;
		}

		// Re-schedule update loop
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ZenLoginUpdateSpawnDarknessLevel, 1, false);
	}
};
