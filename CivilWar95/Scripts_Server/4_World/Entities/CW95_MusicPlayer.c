modded class CW95_MusicPlayer
{
	private float m_CassetteLength 	= -1.0;		// How many ticks the music has

	static ref Timer m_Timer;					// Main Timer used for playing music, rewinding, fast forwarding
	static ref Timer m_SlowTimer;				// I forgor what this one was about but it's doing something

	protected ref NoiseParams m_NoisePar;
	protected NoiseSystem m_NoiseSystem;
    
	void CW95_MusicPlayer()
	{
		m_Timer 			= new Timer(CALL_CATEGORY_SYSTEM);
		m_SlowTimer 		= new Timer(CALL_CATEGORY_SYSTEM);
    }
	
	void ~CW95_MusicPlayer()
	{
		if(m_Timer)
			delete m_Timer;

		if(m_SlowTimer)
			delete m_SlowTimer;
	}

	#ifdef EXPANSION_MODSTORAGE
	override void CF_OnStoreSave(CF_ModStorageMap storage)
	{
		super.CF_OnStoreSave(storage);

		auto ctx = storage[DZ_CivilWar95];
		if (!ctx)
			return;

        ctx.Write( m_Volume );
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
		if (!ctx)
			return true;
        
        if ( !ctx.Read( m_Volume ) )
            return false;

		if ( !ctx.Read( m_IsPlaying ) )
            return false;
		
		if ( !ctx.Read( m_IsRewinding ) )
			return false;

		if ( !ctx.Read( m_IsFastForwarding ) )
			return false;
		
		if( !ctx.Read( m_DoorState ) )
			return false;
		
        return true;
	}
	#else
	override void OnStoreSave( ParamsWriteContext ctx )
    {
        super.OnStoreSave( ctx );

        ctx.Write( m_Volume );
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

		if ( !ctx.Read( m_IsPlaying ) )
            return false;
		
		if ( !ctx.Read( m_IsRewinding ) )
			return false;

		if ( !ctx.Read( m_IsFastForwarding ) )
			return false;
		
		if( !ctx.Read( m_DoorState ) )
			return false;

        return true;
    }
	#endif
	override void AfterStoreLoad()
	{	
		super.AfterStoreLoad();

		if(m_IsPlaying)
			SetPlaying(true);
		else if(m_IsRewinding)
			SetRewinding(true);
		else if(m_IsFastForwarding)
			SetFastForwarding(true);
		else
		{
			UpdateVisual();
			CW95_Cassette_Base cassette = CW95_Cassette_Base.Cast(GetCassette());
			if ( cassette )
			{
				m_Cassette          = cassette;
				m_Tracktimer        = cassette.GetCurrPlaytime();
				m_CassetteLength    = cassette.ConfigGetFloat("trackTime");
				UpdateCassetteState();
			}
		}
	}

	override void EEInit()
	{
		super.EEInit();

		CW95_Cassette_Base cassette = CW95_Cassette_Base.Cast(GetCassette());
		if ( cassette )
		{
			m_Cassette          = cassette;
			m_Tracktimer        = cassette.GetCurrPlaytime();
			m_CassetteLength    = cassette.ConfigGetFloat("trackTime");
			UpdateCassetteState();
		}

		m_NoiseSystem = GetGame().GetNoiseSystem();
		if (m_NoiseSystem && !m_NoisePar)
		{
			m_NoisePar = new NoiseParams();
			m_NoisePar.LoadFromPath("cfgVehicles " + GetType() + " NoiseCassette");
		}
	}
	
	override void StopMusic()
	{
        super.StopMusic();
        
		if(m_Timer)
			m_Timer.Stop();

		if(m_Cassette)
			m_Cassette.SetCurrPlaytime(m_Tracktimer);
	}

	override void StopRewinding()
	{
        super.StopRewinding();
        
		if(m_Timer)
			m_Timer.Stop();

		if(m_Cassette)
			m_Cassette.SetCurrPlaytime(m_Tracktimer);
	}

	override void StopFastForwarding()
	{
        super.StopFastForwarding();
        
		if(m_Timer)
			m_Timer.Stop();

		if(m_Cassette)
			m_Cassette.SetCurrPlaytime(m_Tracktimer);
	}

	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
		super.EEHealthLevelChanged(oldLevel, newLevel, zone);

		if (newLevel == GameConstants.STATE_RUINED)
			OnMusicPlayerRuined();
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);

		UpdateVisual();

		CW95_Cassette_Base cassette = CW95_Cassette_Base.Cast(GetCassette());
		if ( cassette )
		{
			m_Tracktimer        = cassette.GetCurrPlaytime();
			m_CassetteLength    = cassette.ConfigGetFloat("trackTime");
			UpdateCassetteState();
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);

		UpdateVisual();
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

	void UpdateCassetteState()
	{
		if ( m_Tracktimer <= 0 )
			m_CassetteState = CASSETTE_START;
		else if ( m_Tracktimer >= m_CassetteLength )
			m_CassetteState = CASSETTE_END;
		else
			m_CassetteState = CASSETTE_MID;
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
	
	override void PlayMusic(bool delayfix)
	{
        super.PlayMusic(delayfix);

        if(m_Timer && !m_Timer.IsRunning())
        {
            m_Tracktimer = m_Cassette.GetCurrPlaytime();				
            m_Timer.Run(0.1, this, "TimerIncrease", NULL, true);
        }

        if(m_SlowTimer && !m_SlowTimer.IsRunning())
        {
            m_CassetteLength = m_Cassette.ConfigGetFloat("trackTime");
            m_SlowTimer.Run(5.0, this, "SlowTimer", NULL, true);
        }
	}

	void AddCurrentPlayTime(float value)
	{
		m_Tracktimer = m_Tracktimer + value;
		SetSynchDirty();
	}

	void SetCurrentPlayTime(float value)
	{
		m_Tracktimer = value;
		SetSynchDirty();
	}

	void TimerIncrease()
	{
		m_Tracktimer = m_Tracktimer + 0.1;
		SetSynchDirty();
	}

	void SlowTimer()
	{
		GenerateAINoise();

		if( m_Tracktimer > m_CassetteLength )
		{
			m_Tracktimer = m_CassetteLength;
			SetPlaying(false);
		}
	}

	override void TapeTimer(bool offset, float trackTime)
	{
        super.TapeTimer(offset, trackTime);

		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SetVolume, 50, false, m_Volume); // dörty fix for volume being funky
	}
	
	void SetPlaying(bool value)
	{
		if (!value)
		{			
			StopMusic();
			UpdateCassetteState();

			GetCompEM().SwitchOff();
		} else {
			PlayMusic(false);

			GetCompEM().SwitchOn();
		}

		m_Cassette 			= CW95_Cassette_Base.Cast( GetCassette() );
		m_Tracktimer 		= m_Cassette.GetCurrPlaytime();
		m_CassetteLength 	= m_Cassette.ConfigGetFloat("trackTime");
		m_IsPlaying 		= value;
		UpdateVisual();
		SetSynchDirty();
	}

	void SetRewinding(bool value)
	{
		if (!value)
		{
			StopRewinding();
			UpdateCassetteState();

			GetCompEM().SwitchOff();
		} else {
            StartRewinding();
            
			GetCompEM().SwitchOn();
		}

		m_Cassette 			= CW95_Cassette_Base.Cast( GetCassette() );
		m_Tracktimer 		= m_Cassette.GetCurrPlaytime();
		m_CassetteLength 	= m_Cassette.ConfigGetFloat("trackTime");
		m_IsRewinding 		= value;
		UpdateVisual();
		SetSynchDirty();
	}

	void SetFastForwarding(bool value)
	{
		if (!value)
		{
			StopFastForwarding();
			UpdateCassetteState();
            
			GetCompEM().SwitchOff();
		} else {
            StartFastForwarding();

			GetCompEM().SwitchOn();
		}

		m_Cassette 			= CW95_Cassette_Base.Cast( GetCassette() );
		m_Tracktimer 		= m_Cassette.GetCurrPlaytime();
		m_CassetteLength 	= m_Cassette.ConfigGetFloat("trackTime");
		m_IsFastForwarding 	= value;
		UpdateVisual();
		SetSynchDirty();
	}

	override void StartRewinding()
	{
        super.StartRewinding();

		if( m_Timer && !m_Timer.IsRunning() )
			m_Timer.Run(0.3, this,"RewindCassette", NULL, true);
	}

	void RewindCassette()
	{
        m_Tracktimer = m_Tracktimer - 10;

		if(m_Tracktimer < 0)
		{
			m_Tracktimer = 0;
			SetRewinding(false);
		}
	}
	
	override void StartFastForwarding()
	{
        super.StartFastForwarding();

		if( m_Timer && !m_Timer.IsRunning() )
			m_Timer.Run(0.3, this,"FastForwardCassette", NULL, true);
	}

	void FastForwardCassette()
	{
        m_Tracktimer = m_Tracktimer + 10;

		if(m_Tracktimer > m_CassetteLength)
		{
			m_Tracktimer = m_CassetteLength;
			SetFastForwarding(false);
		}
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
	
	void SetVolume(float value)
	{
		m_Volume = value;

		SetSynchDirty();
	}

	void SetDoor(bool state)
	{
		m_DoorState = state;
		
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

		UpdateVisual();
		SetSynchDirty();
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
	}
};
