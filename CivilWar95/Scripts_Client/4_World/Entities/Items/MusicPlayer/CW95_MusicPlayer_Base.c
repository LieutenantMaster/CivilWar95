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

/*
	TODO:
	- Cassette Damage
	- Player Glass Damage
	- Volume Setting on play weird
	- Proxy being hidden by script instead of by p3d/config.cpp (to allow reskins ?)
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
	private float m_CassetteLength 	= -1.0;		// How many ticks the music has

	CW95_Cassette_Base m_Cassette;				// The casstte hold the music data in it's rv config and store in scripts where we stopped in the music

	protected ref NoiseParams m_NoisePar;
	protected NoiseSystem m_NoiseSystem;
	
	ref TStringArray musicsounds = {};
	
	static ref EffectSound Track;
	static ref EffectSound DamagedTrack;
	static ref EffectSound RewindTrack;
	static ref EffectSound FastForwardTrack;

	static ref Timer m_Timer;					// Main Timer used for playing music, rewinding, fast forwarding
	static ref Timer m_SlowTimer;				// I forgor what this one was about but it's doing something
	static ref Timer m_AnimateTimer;			// This timer is purely cosmetic and is for custom music players looking to make their prop more alive
	
	void CW95_MusicPlayer()
	{
		m_Timer 			= new Timer();
		m_SlowTimer 		= new Timer();
		m_AnimateTimer 		= new Timer();

		RegisterNetSyncVariableFloat("m_Tracktimer");
		RegisterNetSyncVariableFloat("m_Volume");

		RegisterNetSyncVariableBool("m_IsPlaying");
		RegisterNetSyncVariableBool("m_IsRewinding");
		RegisterNetSyncVariableBool("m_IsFastForwarding");	
		RegisterNetSyncVariableBool("m_DoorState");
	}
	
	void ~CW95_MusicPlayer()
	{
		// we could probably sync correctly everything so it would keep playing
		// even after a server restart - we just havent bothered trying seriously yet
		m_IsPlaying = false;

		if(m_Timer)
			delete m_Timer;

		if(m_SlowTimer)
			delete m_SlowTimer;

		if(Track)
			delete Track;

		if(RewindTrack)
			delete RewindTrack;

		if(FastForwardTrack)
			delete FastForwardTrack;

		if(m_AnimateTimer)
			delete m_AnimateTimer;

		if(DamagedTrack)
			delete DamagedTrack;
	}

	#ifdef EXPANSION_MODSTORAGE
	override void CF_OnStoreSave(CF_ModStorageMap storage)
	{
		super.CF_OnStoreSave(storage);

		auto ctx = storage[DZ_CivilWar95];
		if (!ctx) return;

        ctx.Write( m_Volume );
		ctx.Write( m_Tracktimer );
		ctx.Write( m_IsPlaying );
		ctx.Write( m_IsRewinding );
		ctx.Write( m_IsFastForwarding );
		ctx.Write( m_DoorState );
	}

	override bool CF_OnStoreLoad(CF_ModStorageMap storage)
	{
		if (!super.CF_OnStoreLoad(storage))
			return false;

		auto ctx = storage[DZ_CivilWar95];
		if (!ctx) return true;
        
        if ( !ctx.Read( m_Volume ) )
            return false;

	    if ( !ctx.Read( m_Tracktimer ) )
            return false;

		if ( !ctx.Read( m_IsPlaying ) )
            return false;
		
		if ( !ctx.Read( m_IsRewinding ) )
			return false;

		if ( !ctx.Read( m_IsFastForwarding ) )
			return false;
		
		if( !ctx.Read( m_DoorState ) )
			return false;
		
		UpdateVisual();
        return true;
	}
	#else
	override void OnStoreSave( ParamsWriteContext ctx )
    {
        super.OnStoreSave( ctx );

        ctx.Write( m_Volume );
		ctx.Write( m_Tracktimer );
		ctx.Write( m_IsPlaying );
		ctx.Write( m_IsRewinding );
		ctx.Write( m_IsFastForwarding );
		ctx.Write( m_DoorState );
    }
    
    override bool OnStoreLoad( ParamsReadContext ctx, int version )
    {
        if ( !super.OnStoreLoad( ctx, version ) )
            return false;
        
        if ( !ctx.Read( m_Volume ) )
            return false;

	    if ( !ctx.Read( m_Tracktimer ) )
            return false;

		if ( !ctx.Read( m_IsPlaying ) )
            return false;
		
		if ( !ctx.Read( m_IsRewinding ) )
			return false;

		if ( !ctx.Read( m_IsFastForwarding ) )
			return false;
		
		if( !ctx.Read( m_DoorState ) )
			return false;
		
		UpdateVisual();
        return true;
    }
	#endif

	override void AfterStoreLoad()
	{	
		super.AfterStoreLoad();

		if(m_IsPlaying)
			PlayMusic(false);

		if(m_IsRewinding)
			RewindCassette();

		if(m_IsFastForwarding)
			FastForwardCassette();	
	}

	override void EEInit()
	{
		super.EEInit();
		UpdateVisual();

		if (GetGame().IsDedicatedServer()  || !GetGame().IsMultiplayer())
		{
			m_NoiseSystem = GetGame().GetNoiseSystem();
			if (m_NoiseSystem && !m_NoisePar)
			{
				m_NoisePar = new NoiseParams();
				m_NoisePar.LoadFromPath("cfgVehicles " + GetType() + " NoiseCassette");
			}
		}
	}

	void DebugReset()
	{
		OnWorkStop();
	}

	override void OnVariablesSynchronized()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		SetVolume(m_Volume);


		// ==================================== Play ====================================
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
			PlayButtonSound();
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
			PlayButtonSound();
		}
		// =============================================================================


		// =================================== Rewind ===================================
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
			PlayButtonSound();
		}
		else if( !m_IsRewinding && RewindTrack )
		{
			if( m_Initialized )
			{
				StopRewinding();
			}
			else
			{
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(StopRewinding, 5000, false);
			}
			PlayButtonSound();
		}
		// =============================================================================


		// ================================ Fast Forward ================================
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
			PlayButtonSound();
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
			PlayButtonSound();
		}
		// =============================================================================


		UpdateVisual();
		super.OnVariablesSynchronized();
	}

	override void OnSwitchOn()
	{
		if ( !GetCompEM().CanWork() )
			OnWorkStop();
		
		UpdateVisual();
	}

	override void OnWorkStop()
	{
		if( m_Initialized )
		{
			if(m_IsPlaying)
				SetPlaying(false);
			
			if(m_IsRewinding)
				SetRewinding(false);
			
			if(m_IsFastForwarding)
				SetFastForwarding(false);
		}
		else
		{
			if(m_IsPlaying)
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SetPlaying, 5000, false, false);
			
			if(m_IsRewinding)
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SetRewinding, 5000, false, false);
			
			if(m_IsFastForwarding)
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SetFastForwarding, 5000, false, false);
		}
		
		UpdateVisual();
		GetCompEM().SwitchOff();
	}

	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
		super.EEHealthLevelChanged(oldLevel, newLevel, zone);

		if (GetGame().IsServer())
		{
			if (newLevel == GameConstants.STATE_RUINED)
			{
				OnMusicPlayerRuined();
			}
		}
	}

	// Destroying cassette and battery on ruined
	void OnMusicPlayerRuined()
	{
		for (int attachmentIdx = 0; attachmentIdx < GetInventory().AttachmentCount(); attachmentIdx++)
		{
			ItemBase attachment = ItemBase.Cast(GetInventory().GetAttachmentFromIndex(attachmentIdx));
			if (attachment)
			{
				attachment.SetHealth("", "", 0.0);
			}
		}
	}

	void UpdateVisual()
	{
		SetAnimationPhase( "Slider_Volume", 		Math.Clamp(m_Volume, 0.0, m_VolumeMax) );
		
		SetAnimationPhase( "Button_Play", 			m_IsPlaying );
		SetAnimationPhase( "Button_Pause", 			!m_IsPlaying && !m_DoorState );
		SetAnimationPhase( "Button_Rewind", 		m_IsRewinding );
		SetAnimationPhase( "Button_FastForward", 	m_IsFastForwarding );
		SetAnimationPhase( "Button_Stop", 			m_DoorState );

		SetAnimationPhase( "Door", 					m_DoorState );

		ItemBase cassette = GetCassette();
		ItemBase battewy = GetBattery();

		if(m_DoorState)
		{
			if(cassette)
			{
				cassette.UnlockFromParent();
			}

			if(battewy)
			{
				battewy.UnlockFromParent();
			}
		}
		else
		{
			if(cassette)
			{
				cassette.LockToParent();
			}

			if(battewy)
			{
				battewy.LockToParent();
			}
		}

		if ( GetCompEM().IsWorking() )
		{
			SetObjectTexture( 2, "#(argb,8,8,3)color(1,0,0,1.0,co)" );
			SetObjectMaterial( 2, LIGHT_GLOW_ON );
		}
		else
		{
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
			else
			{
				if ( m_AnimateTimer.IsRunning() )
					m_AnimateTimer.Stop();
			}
		}

		if ( FindAttachmentBySlotName("CW95_Cassette"))
		{
			SetAnimationPhase( "CW95_Cassette", 0 );
		}
		else
		{
			SetAnimationPhase( "CW95_Cassette", 1 );
		}
	}

	void AnimateTapePlayer()
	{
		SetAnimationPhase( "Slider_MusicPlay1", m_Tracktimer );
		SetAnimationPhase( "Slider_MusicPlay2", m_Tracktimer );
	}

	void PlayButtonSound()
	{
		UpdateVisual();
		
		if (!GetGame().IsDedicatedServer())
		{
			EffectSound sound =	SEffectManager.PlaySound( "CW95_Cassette_Button", GetPosition() );
			sound.SetAutodestroy( true );
		}
	}

	void PlayDamagedTapeSound()
	{
		int health = GetHealthLevel();
		if (health > 1)
		{
			PlaySoundSetLoop( DamagedTrack, "CW95_Ruined_Music", 0.1, 0.3 );
			DamagedTrack.SetSoundVolume(1.5-(1.0/health));
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		UpdateVisual();
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		UpdateVisual();
	}

	void PlayDoorSound(bool state)
	{
		UpdateVisual();

		string musicSoundSet;
		if (state)
		{
			musicSoundSet = "CW95_MusicPlayer_DoorOpen";
		}
		else
		{
			musicSoundSet = "CW95_MusicPlayer_DoorClose";
		}

		if (!GetGame().IsDedicatedServer())
		{
			EffectSound sound =	SEffectManager.PlaySound( musicSoundSet, GetPosition() );
			sound.SetAutodestroy( true );
		}
	}	

	void GenerateAINoise()
	{
		float noiseMultiplier = GetVolume() * 50;
		if (m_NoiseSystem && m_NoisePar)
		{
			m_NoiseSystem.AddNoiseTarget(GetPosition(), 5, m_NoisePar, noiseMultiplier);
		}
	}

	void StopAllActions()
	{
		if(m_IsPlaying)
			SetPlaying(false);
			
		if(m_IsRewinding)
			SetRewinding(false);
		
		if(m_IsFastForwarding)
			SetFastForwarding(false);
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

	bool CanPlay()
	{
		return IsFunctional() && !IsBusy() && CanOpen() && GetCompEM().CanSwitchOn();
	}

	bool CanStop()
	{
		return IsFunctional() && IsBusy();
	}

	bool CanFastForward()
	{
		return CanPlay() && !IsRewinding();
	}

	bool CanRewind()
	{
		return CanPlay() && !IsFastForwarding();
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
	
	void PlayMusic(bool delayfix)
	{
		m_Cassette = CW95_Cassette_Base.Cast(FindAttachmentBySlotName("CW95_Cassette"));

		if ( GetCompEM().CanSwitchOn() )
			GetCompEM().SwitchOn();

		if(m_Cassette)
		{
			if(m_Timer && !m_Timer.IsRunning())
			{
				m_Tracktimer = m_Cassette.GetCurrPlaytime();
					
				m_Timer.Run(0.1, this, "TimerIncrease", NULL, true);
			}

			//if (!GetGame().IsDedicatedServer()) 
			{
				m_Cassette.ConfigGetTextArray("Tracks", musicsounds);

				if (!GetGame().IsDedicatedServer()) 
					Track = SEffectManager.CW95_PlaySoundOnObjectWOPlay(musicsounds[0], this);
				
				PlayDamagedTapeSound();

				if(m_Tracktimer != -1)
				{
					if(delayfix)
						m_Tracktimer = m_Tracktimer + 5.0;

					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(TapeTimer, 50, false, true, m_Tracktimer);
				}
				else
				{
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(TapeTimer, 50, false, false, -1);
				}
			}

			if(m_SlowTimer && !m_SlowTimer.IsRunning())
			{
				m_CassetteLength = m_Cassette.ConfigGetFloat("trackTime");
					
				m_SlowTimer.Run(5.0, this,"SlowTimer", NULL, true);
			}
		}
	}

	void AddCurrentPlayTime(float value)
	{
		m_Tracktimer = m_Tracktimer + value;
	}

	void SetCurrentPlayTime(float value)
	{
		m_Tracktimer = value;
	}

	void TimerIncrease()
	{
		m_Tracktimer = m_Tracktimer + 0.1;

		m_Cassette.SetCurrPlaytime(m_Tracktimer);
	}

	void SlowTimer()
	{
		if ( GetGame().IsDedicatedServer() || !GetGame().IsMultiplayer() )
			GenerateAINoise();

		if( m_Tracktimer > m_CassetteLength )
		{
			SetPlaying(false);
			m_Tracktimer = m_CassetteLength;
		}
	}

	void TapeTimer(bool offset, float trackTime)
	{
		if ( !GetGame().IsDedicatedServer() )
		{
			Track.SoundPlay();

			if ( offset )
			{
				Track.CW95_GetWave().GetLength();	// needs to be here otherwise it will break
				Track.CW95_SkipTo(trackTime);
				Track.SetSoundVolume(m_Volume);		// this shit does not work
				Track.CW95_GetWave().Play();
			}
		}

		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SetVolume, 50, false, m_Volume); // dörty fix for volume being funky
	}

	void StartRewinding()
	{
		if ( GetCompEM().CanSwitchOn() )
			GetCompEM().SwitchOn();

		if ( !GetGame().IsDedicatedServer())
			RewindTrack = SEffectManager.CW95_PlaySoundOnObjectWOPlay("CW95_Cassette_Rewind", this, 0, 0, true);

		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DelayRewindStartSound, 50, false);
		
		if(!m_Cassette)
			m_Cassette = CW95_Cassette_Base.Cast( GetCassette() );

		// fix for null pointer for ticking the timer less than an ingame tick
		if(m_Cassette.GetCurrPlaytime() <= 0)
		{
			m_Tracktimer = 0;
			SetRewinding(false);
		}
		else
		{
			if( m_Timer && !m_Timer.IsRunning() )
				m_Timer.Run(0.3, this,"RewindCassette", NULL, true);
		}
	}

	void DelayRewindStartSound()
	{
		if ( GetGame().IsDedicatedServer() )
			return;

		if(RewindTrack)
		{
			RewindTrack.SoundPlay();
			RewindTrack.CW95_GetWave().GetLength();
			RewindTrack.CW95_GetWave().Play();
		}
	}

	void RewindCassette()
	{
		if(m_Cassette.GetCurrPlaytime() <= 0)
		{
			m_Tracktimer = 0;
			SetRewinding(false);
		}
		else
		{
			m_Tracktimer = m_Tracktimer - 3;
			m_Cassette.RewindCurrPlaytime(-3);
		}
	}
	
	void StartFastForwarding()
	{
		if ( GetCompEM().CanSwitchOn() )
			GetCompEM().SwitchOn();

		if ( !GetGame().IsDedicatedServer())
			FastForwardTrack = SEffectManager.CW95_PlaySoundOnObjectWOPlay("CW95_Cassette_FastForward", this, 0, 0, true);
			
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DelayFastForwardStartSound, 50, false);
		
		if(!m_Cassette)
			m_Cassette = CW95_Cassette_Base.Cast( GetCassette() );


		// fix for null pointer for ticking the timer less than an ingame tick
		if(m_Cassette.GetCurrPlaytime() >= m_Cassette.ConfigGetFloat("trackTime"))
		{
			m_Tracktimer = 0;
			SetFastForwarding(false);
		}
		else
		{
			if( m_Timer && !m_Timer.IsRunning() )
				m_Timer.Run(0.3, this,"FastForwardCassette", NULL, true);
		}
		
	}

	void DelayFastForwardStartSound()
	{
		if ( GetGame().IsDedicatedServer() )
			return;

		if(FastForwardTrack)
		{
			FastForwardTrack.SoundPlay();
			FastForwardTrack.CW95_GetWave().GetLength();
			FastForwardTrack.CW95_GetWave().Play();
		}
	}

	void FastForwardCassette()
	{
		if(m_Cassette.GetCurrPlaytime() >= m_Cassette.ConfigGetFloat("trackTime"))
		{
			m_Tracktimer = 0;
			SetFastForwarding(false);
		}
		else
		{
			m_Tracktimer = m_Tracktimer + 3;
			m_Cassette.FastForwardCurrPlaytime(3);
		}
	}
	
	void StopMusic()
	{
		if(m_Timer)
			m_Timer.Stop();

		if(m_Cassette)
			m_Cassette.SetCurrPlaytime(m_Tracktimer);

		if(m_SlowTimer)
			m_SlowTimer.Stop();

		if(Track)
			StopSoundSet(Track);

		if(DamagedTrack)
			StopSoundSet(DamagedTrack);
	}

	void StopRewinding()
	{
		if(m_Timer)
			m_Timer.Stop();
		
		if(RewindTrack)
			StopSoundSet(RewindTrack);
	}

	void StopFastForwarding()
	{
		if(m_Timer)
			m_Timer.Stop();

		if(FastForwardTrack)
			StopSoundSet(FastForwardTrack);
	}
	
	void IncrementVolume()
	{
		float vol = m_Volume + m_VolumeSteps;

		if ( vol >= m_VolumeMax )
			vol = m_VolumeMax;

		SetVolume(vol);
	}

	void DecrementVolume()
	{
		float vol = m_Volume - m_VolumeSteps;

		// Minimum 10% volume
		if ( vol < 0.1 )
			vol = 0.1;

		SetVolume(vol);
	}
	
	float GetVolume()
	{
		return m_Volume;
	}
	
	void SetVolume(float value)
	{
		m_Volume = value;
		SetSynchDirty();
		
		if(Track)
			Track.SetSoundVolume(m_Volume);
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
	
	void SetPlaying(bool value)
	{
		if (!value)
		{
			m_IsPlaying = value;
			GetCompEM().SwitchOff();
			StopMusic();
		}
		else if(GetCompEM().CanSwitchOn() && GetCompEM().CanWork())
		{
			m_IsPlaying = value;
			GetCompEM().SwitchOn();
			PlayMusic(false);
		}

		PlayButtonSound();
		SetSynchDirty();
	}

	void SetRewinding(bool value)
	{
		if (!value)
		{
			m_IsRewinding = value;
			GetCompEM().SwitchOff();
			StopRewinding();
		}
		else if(GetCompEM().CanSwitchOn() && GetCompEM().CanWork())
		{
			m_IsRewinding = value;
			GetCompEM().SwitchOn();
			StartRewinding();
		}

		PlayButtonSound();
		SetSynchDirty();
	}

	void SetFastForwarding(bool value)
	{
		if (!value)
		{
			m_IsFastForwarding = value;
			GetCompEM().SwitchOff();
			StopFastForwarding();
		}
		else if(GetCompEM().CanSwitchOn() && GetCompEM().CanWork())
		{
			m_IsFastForwarding = value;
			GetCompEM().SwitchOn();
			StartFastForwarding();
		}

		PlayButtonSound();
		SetSynchDirty();
	}

	void SetDoor(bool state)
	{
		m_DoorState = state;
		SetSynchDirty();

		PlayDoorSound(state);
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

	override bool CanDisplayAttachmentSlot(string slot_name)
	{
		if( !super.CanDisplayAttachmentSlot(slot_name) )
			return false;
		
        if ( slot_name == "CW95_Cassette" )
			return m_DoorState; // Only allow access if the door is opened

		return true;
	}
	
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);

		int health = GetHealthLevel();
		
		if ( IsPlaying() )
		{
			if (Math.RandomIntInclusive(0, 4) < health)
				SetPlaying(false);
		}

		if ( DamagedTrack )
		{
			float modifier = Math.RandomIntInclusive(1, 4);
			if (Math.RandomIntInclusive(0, 4) > health)
				modifier = 0;

			DamagedTrack.SetSoundVolume(1.5-(1.0/health)+(1.0/modifier));
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
};
