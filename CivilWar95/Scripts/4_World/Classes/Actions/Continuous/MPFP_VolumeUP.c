class MPFP_VolumeUPActionCB : ActionContinuousBaseCB
{
	private const float REPEAT_AFTER_SEC = 0.3;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(REPEAT_AFTER_SEC);
	}
}

class MPFP_VolumeUPAction: ActionContinuousBase
{
	void MPFP_VolumeUPAction()
	{
		m_CallbackClass = MPFP_VolumeUPActionCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ITEM_TUNE;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_ITEM_TUNE;		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
		
		m_Text = "Volume UP";
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNone;
		m_ConditionItem = new CCINonRuined;
	}
	
	override bool HasProneException()
	{
		return true;
	}

	override bool HasTarget()
	{
		return false;
	}

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		CV95_MusicPlayer mPlayer;
		if ( Class.CastTo(mPlayer, CV95_MusicPlayer.Cast( item ) ) )
		{
			float volume = mPlayer.GetVolume() * 100;
			m_Text = "Volume UP (" + volume + "%)";
		}
	}

	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		CV95_MusicPlayer mPlayer;
		if ( Class.CastTo(mPlayer, CV95_MusicPlayer.Cast( item ) ) )
			return true;
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		CV95_MusicPlayer mPlayer = CV95_MusicPlayer.Cast( action_data.m_MainItem );
		if( mPlayer )
			mPlayer.IncrementVolume();
	}

	override void OnFinishProgressClient( ActionData action_data )
	{	
		CV95_MusicPlayer mPlayer = CV95_MusicPlayer.Cast( action_data.m_MainItem );
		if( mPlayer )
			mPlayer.IncrementVolume();
	}
}