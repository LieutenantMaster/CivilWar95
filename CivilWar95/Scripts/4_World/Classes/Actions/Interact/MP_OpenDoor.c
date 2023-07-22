class MP_OpenDoorCB : ActionBaseCB
{
	override void CreateActionComponent()
	{
        
		m_ActionData.m_ActionComponent = new CASingleUse;
	}
};

class MP_OpenDoorAction: AnimatedActionBase
{	
	void MP_OpenDoorAction()
	{
		m_CallbackClass = MP_OpenDoorCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENLID;
		m_FullBody = false;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "Open Door";
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
			return ntarget.CanOpen();

		return false;
	}

    override protected void OnEndServer( ActionData action_data )
	{
		CV95_MusicPlayer ntarget = CV95_MusicPlayer.Cast( action_data.m_Target.GetObject() );
		if( ntarget )
			ntarget.SetDoor(true);
	}
	override protected void OnEndClient( ActionData action_data )
	{
		CV95_MusicPlayer ntarget = CV95_MusicPlayer.Cast( action_data.m_Target.GetObject() );
		if( ntarget )
			ntarget.SetDoor(true);
	}
};