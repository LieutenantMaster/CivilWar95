/**
 * PlayerBase.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class PlayerBase
{
	//protected bool m_IsWounded;
	//protected autoprt TIntArray m_Injuries;

	protected bool m_IsSurrender;

	protected float m_PScale = -1;
	protected const float DEFAULT_SCALE = 1.0;

	protected bool CW95_IsAtZeleno;

	void PlayerBase()
	{
		if ( !IsAI() )
		{
			RegisterNetSyncVariableBool("m_IsSurrender");
			RegisterNetSyncVariableFloat("m_PScale", 0.7, 1.2);
		}
	}

	override void EOnPostFrame(IEntity other, int extra)
	{
		super.EOnPostFrame(other, extra);

		if ( m_PScale > 0.7 && m_PScale < 1.2 )
			SetScale(m_PScale);
	}

	bool IsPlayerAtZeleno()
	{
		return CW95_IsAtZeleno;
	}

	void SetPlayerAtZeleno(bool state)
	{
		CW95_IsAtZeleno = state;
	}

	override void SetActions()
	{
		super.SetActions();

#ifdef CW95_ENABLE_KNOCK
		AddAction(CW95_ActionKnockAtDoor);
#endif

		AddAction(CW95_ActionVehicleFlare);
		AddAction(CW95_ActionVehicleRocket);
    }

	override void OnCommandVehicleStart()
	{
		super.OnCommandVehicleStart();
		
		if ( GetInventory() )
			GetInventory().UnlockInventory(LOCK_FROM_SCRIPT);		
	}
	
	override void OnCommandVehicleFinish()
	{
		if ( GetInventory() )
			GetInventory().LockInventory(LOCK_FROM_SCRIPT);
		
		super.OnCommandVehicleFinish();		
	}

	override bool CanManipulateInventory()
	{
		if ( !super.CanManipulateInventory() )
			return false;

		if( IsControlledPlayer() )
			return !IsRestrained() && !IsRestrainPrelocked() && !m_IsSurrender;

		return true;
	}

	static bool IsWounded()
	{
		return false;
	}
	
	bool FindWoundType( int woundType )
	{
		return false;
	}
};
