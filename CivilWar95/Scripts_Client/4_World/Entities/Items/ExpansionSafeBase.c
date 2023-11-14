modded class ExpansionSafeBase
{
	override bool ExpansionIsLocked()
	{
		if (m_CodeLength > 0 && m_Locked)
			return !ExpansionIsOpened();

		return false;
	}

};

/*
modded class ExpansionActionCloseAndLockSafe
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		ExpansionSafeBase tgtSafe;
		if ( !Class.CastTo( tgtSafe, target.GetObject() ) )
			if ( !Class.CastTo( tgtSafe, target.GetParent() ) )
				return false;

		return !tgtSafe.ExpansionIsLocked() && tgtSafe.HasCode();
	}
};
*/