/**
 * MP_FastForwardAction.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class MP_FastForwardActionCB: ActionBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAInteract;
	}
};

class MP_FastForwardAction: AnimatedActionBase
{
	void MP_FastForwardAction()
	{
		m_CallbackClass	= MP_FastForwardActionCB;
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_ATTACHITEM;
		m_StanceMask	= DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody 		= false;
		
		m_Text 			= "Fast Forward";
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
			return ntarget.CanFastForward();

        return false;
	}
    override void OnEndServer(ActionData action_data)
	{
        CV95_MusicPlayer ntarget = CV95_MusicPlayer.Cast( action_data.m_Target.GetObject() );
		if( ntarget )
			ntarget.SetFastForwarding(true);
        
        Inventory_Base m_Cassette = ItemBase.Cast(ntarget.FindAttachmentBySlotName("CV95_Cassette"));
		m_Cassette.DecreaseHealth("", "", -0.1);
    }
	
	override void OnEndClient(ActionData action_data)
	{
		CV95_MusicPlayer ntarget = CV95_MusicPlayer.Cast( action_data.m_Target.GetObject() );
		if( ntarget )
			ntarget.SetFastForwarding(true);
	}
}
