/**
 * CW95_MusicPlayer.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster and Niphoria
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_MusicPlayer: Inventory_Base
{
	private const string LIGHT_GLOW_ON	= "dz\\gear\\camping\\data\\battery_charger_light_r.rvmat";
	private const string LIGHT_GLOW_OFF	= "CivilWar95\CivilWar95\Objects\Gear\MusicPlayer\Rvmats\musicPlayer.rvmat";

	private float m_Volume 			= 0.5;		// Default volume will be set to 0.5 aka 50%
	private float m_VolumeSteps 	= 0.1;		// Each increments will increase the volume by 0.1 aka 10%
	private float m_VolumeMax 		= 2.0;		// Max volume in percentage, 2.0 being 200%

	private float m_Tracktimer 		= 0;		// At what tick of the music are we at ? This helps us to rewind, fastfoward and sync the timestamp of the audio
	private bool m_IsPlaying 		= false; 	// Indicate if we are playing a music
	private bool m_IsRewinding 		= false;
	private bool m_IsFastForwarding = false;
	private bool m_DoorState 		= false; 	// false => closed | true => open
	private int m_CassetteState		= 0;		// 0 = is at first tick of the cassette | 1 = is inbetween | 2 = reached last tick of the cassette

	private int CASSETTE_START 	= 0;
	private int CASSETTE_MID 	= 1;
	private int CASSETTE_END 	= 2;

	private bool m_IsPlayingSynch;
	private bool m_IsRewindingSynch;
	private bool m_IsFastForwardingSynch;
	private bool m_DoorStateSynch;

	CW95_Cassette_Base m_Cassette;				// The casstte hold the music data in it's rv config and store in scripts where we stopped in the music
	
	ref TStringArray musicsounds = {};
	
	static ref EffectSound Track;
	static ref EffectSound DamagedTrack;
	static ref EffectSound RewindTrack;
	static ref EffectSound FastForwardTrack;

	static ref Timer m_AnimateTimer;			// This timer is purely cosmetic and is for custom music players looking to make their prop more alive
	
	void CW95_MusicPlayer()
	{
		m_AnimateTimer 		= new Timer();

		RegisterNetSyncVariableFloat("m_Tracktimer");
		RegisterNetSyncVariableFloat("m_Volume");

		RegisterNetSyncVariableBool("m_IsPlaying");
		RegisterNetSyncVariableBool("m_IsRewinding");
		RegisterNetSyncVariableBool("m_IsFastForwarding");
		RegisterNetSyncVariableBool("m_DoorState");

		RegisterNetSyncVariableInt("m_CassetteState", 0, 2);
	}
	
	void ~CW95_MusicPlayer()
	{
		if(Track)
		{
			StopSoundSet(Track);
			delete Track;
		}

		if(RewindTrack)
		{
			StopSoundSet(RewindTrack);
			delete RewindTrack;
		}

		if(FastForwardTrack)
		{
			StopSoundSet(FastForwardTrack);
			delete FastForwardTrack;
		}

		if(DamagedTrack)
		{
			StopSoundSet(DamagedTrack);
			delete DamagedTrack;
		}

		if(m_AnimateTimer)
			delete m_AnimateTimer;
	}

	override void EEInit()
	{
		super.EEInit();

		UpdateVisual();
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if(Track && m_IsPlaying)
			Track.SetSoundVolume(m_Volume);

		if ( m_DoorState != m_DoorStateSynch )
		{
			m_DoorStateSynch = m_DoorState;
			PlayDoorSound(m_DoorState);
		}

		// ==================================== Play ====================================
		if ( m_IsPlaying != m_IsPlayingSynch )
		{
			m_IsPlayingSynch = m_IsPlaying;
			PlayButtonSound();
		}
		if( m_IsPlaying && !Track)
		{
			if( m_Initialized )
			{
				PlayMusic(false);
			}
			else
			{
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PlayMusic, 5000, false, true);
			}
		}
		else if( !m_IsPlaying && Track)
		{
			if( m_Initialized )
			{
				StopMusic();
			}
			else
			{
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(StopMusic, 5000, false);
			}
		}
		// =============================================================================


		// =================================== Rewind ===================================
		if ( m_IsRewindingSynch != m_IsRewinding )
		{
			m_IsRewindingSynch = m_IsRewinding;
			PlayButtonSound();
		}
		if( m_IsRewinding && !RewindTrack)
		{
			if( m_Initialized )
			{
				StartRewinding();
			}
			else
			{
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(StartRewinding, 5000, false);
			}
		}
		else if(!m_IsRewinding && RewindTrack)
		{
			if( m_Initialized )
			{
				StopRewinding();
			}
			else
			{
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(StopRewinding, 5000, false);
			}
		}
		// =============================================================================


		// ================================ Fast Forward ================================
		if ( m_IsFastForwarding != m_IsFastForwardingSynch )
		{
			m_IsFastForwardingSynch = m_IsFastForwarding;
			PlayButtonSound();
		}
		if( m_IsFastForwarding && !FastForwardTrack)
		{
			if( m_Initialized )
			{
				StartFastForwarding();
			}
			else
			{
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(StartFastForwarding, 5000, false);
			}
		}
		else if ( !m_IsFastForwarding && FastForwardTrack )
		{
			if( m_Initialized )
			{
				StopFastForwarding();
			}
			else
			{
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(StopFastForwarding, 5000, false);
			}
		}
		// =============================================================================

		UpdateVisual();
	}

	void UpdateVisual()
	{
		ItemBase cassette = GetCassette();
		ItemBase battery = GetBattery();

		if(m_DoorState)
		{
			if(cassette)
				cassette.UnlockFromParent();

			if(battery)
				battery.UnlockFromParent();
		} else {
			if(cassette)
				cassette.LockToParent();

			if(battery)
				battery.LockToParent();
		}
#ifndef SERVER
		SetAnimationPhase( "Slider_Volume", 		Math.Clamp(m_Volume, 0.0, m_VolumeMax) );
		
		SetAnimationPhase( "Button_Play", 			m_IsPlaying );
		SetAnimationPhase( "Button_Pause", 			!m_IsPlaying && !m_DoorState );
		SetAnimationPhase( "Button_Rewind", 		m_IsRewinding );
		SetAnimationPhase( "Button_FastForward", 	m_IsFastForwarding );
		SetAnimationPhase( "Button_Stop", 			m_DoorState );

		SetAnimationPhase( "Door", 					m_DoorState );

		if ( GetCompEM().IsWorking() )
		{
			SetObjectTexture( 2, "#(argb,8,8,3)color(1,0,0,1.0,co)" );
			SetObjectMaterial( 2, LIGHT_GLOW_ON );
		} else {
			SetObjectTexture( 2, "#(argb,8,8,3)color(0.15,0,0,1.0,co)" );
			SetObjectMaterial( 2, LIGHT_GLOW_OFF );
		}

		if ( m_AnimateTimer )
		{
			if ( IsBusy() )
			{
				if ( !m_AnimateTimer.IsRunning() )
					m_AnimateTimer.Run(0.1, this,"AnimateTapePlayer", NULL, true);
			}
			else if ( m_AnimateTimer.IsRunning() )
			{
				m_AnimateTimer.Stop();
			}
		}

		SetAnimationPhase( "CW95_Cassette", !HasCassette() );
#endif
	}

	void AnimateTapePlayer()
	{
		SetAnimationPhase( "Slider_MusicPlay1", m_Tracktimer );
		SetAnimationPhase( "Slider_MusicPlay2", m_Tracktimer );
	}

	void PlayButtonSound()
	{		
#ifndef SERVER
		EffectSound sound =	SEffectManager.PlaySound( "CW95_Cassette_Button", GetPosition() );
		sound.SetAutodestroy( true );
#endif
	}

	void PlayDamagedTapeSound()
	{
		int health = GetHealthLevel();
		if (health > 1)
		{
			PlaySoundSetLoop( DamagedTrack, "CW95_Ruined_Music", 0.1, 0.3 );
			DamagedTrack.SetSoundVolume(1.5 - (1.0 / health));
		}
	}

	void PlayDoorSound(bool state)
	{
#ifndef SERVER
		string musicSoundSet;
		if (state)
		{
			musicSoundSet = "CW95_MusicPlayer_DoorOpen";
		} else {
			musicSoundSet = "CW95_MusicPlayer_DoorClose";
		}

		EffectSound sound =	SEffectManager.PlaySound( musicSoundSet, GetPosition() );
		sound.SetAutodestroy( true );
#endif
	}
	
	void PlayMusic(bool delayfix)
	{
#ifndef SERVER
		m_Cassette.ConfigGetTextArray("Tracks", musicsounds);
		Track = SEffectManager.CW95_PlaySoundOnObjectWOPlay(musicsounds[0], this);
		PlayDamagedTapeSound();
#endif
		if(m_Tracktimer != -1 && delayfix)
			m_Tracktimer = m_Tracktimer + 5.0;

		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(TapeTimer, 50, false, true, m_Tracktimer);
	}

	void TapeTimer(bool offset, float trackTime)
	{
#ifndef SERVER
		Track.SoundPlay();

		if ( offset )
		{
			Track.CW95_GetWave().GetLength();	// needs to be here otherwise it will break
			Track.CW95_SkipTo(trackTime);
			Track.SetSoundVolume(m_Volume);		// this shit does not work
			Track.CW95_GetWave().Play();
		}
#endif
	}

	void StartRewinding()
	{
#ifndef SERVER
		RewindTrack = SEffectManager.CW95_PlaySoundOnObjectWOPlay("CW95_Cassette_Rewind", this, 0, 0, true);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DelayRewindStartSound, 50, false);
#endif
	}

	void DelayRewindStartSound()
	{
#ifndef SERVER
		if(RewindTrack)
		{
			RewindTrack.SoundPlay();
			RewindTrack.CW95_GetWave().GetLength();
			RewindTrack.CW95_GetWave().Play();
		}
#endif
	}
	
	void StartFastForwarding()
	{
#ifndef SERVER
		FastForwardTrack = SEffectManager.CW95_PlaySoundOnObjectWOPlay("CW95_Cassette_FastForward", this, 0, 0, true);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DelayFastForwardStartSound, 50, false);
#endif
	}

	void DelayFastForwardStartSound()
	{
#ifndef SERVER
		if(FastForwardTrack)
		{
			FastForwardTrack.SoundPlay();
			FastForwardTrack.CW95_GetWave().GetLength();
			FastForwardTrack.CW95_GetWave().Play();
		}
#endif
	}
	
	void StopMusic()
	{
		if(Track)
			StopSoundSet(Track);

		if(DamagedTrack)
			StopSoundSet(DamagedTrack);
	}

	void StopRewinding()
	{
		if(RewindTrack)
			StopSoundSet(RewindTrack);
	}

	void StopFastForwarding()
	{
		if(FastForwardTrack)
			StopSoundSet(FastForwardTrack);
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);

		CW95_Cassette_Base cassette = CW95_Cassette_Base.Cast(GetCassette());
		if ( cassette )
			m_Cassette = cassette;
	}
	
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);

		if ( DamagedTrack )
		{
			int health = GetHealthLevel();
			float modifier = Math.RandomIntInclusive(1, 4);
			if (Math.RandomIntInclusive(0, 4) > health)
				modifier = 0;

			DamagedTrack.SetSoundVolume(1.5- (1.0 / health) + (1.0 / modifier));
		}
	}
	
	override void SetActions()
	{
		AddAction(ActionAttachOnSelection);

		super.SetActions();

		AddAction(MP_PlayMusicAction);
		AddAction(MP_StopAction);

		AddAction(MP_OpenDoorAction);
		AddAction(MP_CloseDoorAction);

		AddAction(MP_FastForwardAction);
		AddAction(MP_RewindAction);

		AddAction(MPFP_VolumeUPAction);
		AddAction(MPFP_VolumeDOWNAction);

		AddAction(MPFP_Play);
		AddAction(MPFP_Stop);
	}

	override bool IsPlayBackDevice()
	{
		return true;
	}
	
	ItemBase GetCassette()
	{
		return ItemBase.Cast(FindAttachmentBySlotName("CW95_Cassette"));
	}
	
	ItemBase GetBattery()
	{
		return ItemBase.Cast(FindAttachmentBySlotName("BatteryD"));
	}
	
	bool HasCassette()
	{
		return GetCassette() != NULL;
	}
	
	bool HasBattery()
	{
		return GetBattery() != NULL;
	}

	bool IsFunctional()
	{
		return HasCassette() && HasBattery();
	}

	bool IsBusy()
	{
		return IsPlaying() || IsRewinding() || IsFastForwarding();
	}

	bool CanStartWorking()
	{
		return IsFunctional() && !IsBusy() && !m_DoorState && GetCompEM().CanSwitchOn();
	}

	bool CanPlay()
	{
		return CanStartWorking() && m_CassetteState < CASSETTE_END;
	}

	bool CanStop()
	{
		return IsFunctional() && IsBusy();
	}

	bool CanFastForward()
	{
		return CanStartWorking() && m_CassetteState != CASSETTE_END;
	}

	bool CanRewind()
	{
		return CanStartWorking() && m_CassetteState > CASSETTE_START;
	}

	bool CanStopRewind()
	{
		return IsRewinding();
	}

	bool CanStopFastForward()
	{
		return IsFastForwarding();
	}
	
	bool CanOpen()
	{
		return !m_DoorState && !IsBusy();
	}
	
	bool CanClose()
	{
		return m_DoorState && !IsBusy();
	}
	
	float GetVolume()
	{
		return m_Volume;
	}
	
	bool IsPlaying()
	{
		return m_IsPlaying;
	}

	bool IsRewinding()
	{
		return m_IsRewinding;
	}

	bool IsFastForwarding()
	{
		return m_IsFastForwarding;
	}

	override bool CanReceiveAttachment (EntityAI attachment, int slotId)
	{
		if( !super.CanReceiveAttachment(attachment, slotId) )
			return false;

		PlayerBase player = PlayerBase.Cast( GetHierarchyRootPlayer() );

		if ( player && !player.IsPlayerLoaded() )
			return true;

		return m_DoorState; // Only allow access if the door is opened
	}
};
