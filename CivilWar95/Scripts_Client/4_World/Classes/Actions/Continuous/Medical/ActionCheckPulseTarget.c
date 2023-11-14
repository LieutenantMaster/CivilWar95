modded class ActionCheckPulseTarget
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        if ( !super.ActionCondition(player, target, item) )
            return false;

		PlayerBase ntarget = PlayerBase.Cast(  target.GetObject() );
		if( ntarget && ntarget.IsUnconscious() )
			return true;

		return false;
	}
};
