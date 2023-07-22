class MP_RewindCB : ActionBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAInteract;
	}
}

class MP_RewindAction : AnimatedActionBase
{
	void MP_RewindAction()
	{
		m_CallbackClass	= MP_RewindCB;
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_ATTACHITEM;
		m_StanceMask	= DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody 		= false;
		
		m_Text 			= "Rewind";
	}

    override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}

    override bool HasProgress()
	{
		return false;
	}
	
	override void CreateConditionComponents()
	{
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
		m_ConditionItem = new CCINone;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		CV95_MusicPlayer ntarget;
		if ( Class.CastTo(ntarget, target.GetObject()) )
			return ntarget.CanRewind();

        return false;
	}
    override void OnEndServer(ActionData action_data)
	{
        CV95_MusicPlayer ntarget = CV95_MusicPlayer.Cast( action_data.m_Target.GetObject() );
		if( ntarget )
			ntarget.SetRewinding(true);

		Inventory_Base m_Cassette = ItemBase.Cast(ntarget.FindAttachmentBySlotName("CV95_Cassette"));
		m_Cassette.DecreaseHealth("", "", -0.1);
    }
	
	override void OnEndClient(ActionData action_data)
	{
		CV95_MusicPlayer ntarget = CV95_MusicPlayer.Cast( action_data.m_Target.GetObject() );
		if( ntarget )
			ntarget.SetRewinding(true);
	}
}
