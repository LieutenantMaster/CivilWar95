class MP_PlayMusicActionCB : ActionBaseCB
{
	override void CreateActionComponent()
	{
        
		m_ActionData.m_ActionComponent = new CAInteract;
	}
};

class MP_PlayMusicAction: AnimatedActionBase
{	
	void MP_PlayMusicAction()
	{
		m_CallbackClass = MP_PlayMusicActionCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ATTACHITEM;
		m_FullBody = false;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "Play";
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
		m_ConditionItem = new CCINone;
	}
	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}

	override bool HasProgress()
	{
		return false;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        CV95_MusicPlayer ntarget;
		if ( Class.CastTo(ntarget, target.GetObject()) )
			return ntarget.CanPlay();

		return false;
	}

    override void OnStartServer( ActionData action_data )
	{
        CV95_MusicPlayer ntarget = CV95_MusicPlayer.Cast( action_data.m_Target.GetObject() );
		if( ntarget )
			ntarget.SetPlaying(true);
	}

	override void OnStartClient( ActionData action_data )
	{
        CV95_MusicPlayer ntarget = CV95_MusicPlayer.Cast( action_data.m_Target.GetObject() );
		if( ntarget )
			ntarget.SetPlaying(true);
	}
};