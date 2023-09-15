/**
 * BuildingBase.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class BuildingBase
{
	protected bool m_IsKnocking;
	protected bool m_ShouldKnock;

	protected int  m_Index;
	
	void BuildingBase()
	{
		m_Index = -1;

		RegisterNetSyncVariableBool( "m_ShouldKnock" );
		RegisterNetSyncVariableInt( "m_Index" );
	}

	protected string GetLoopKnockingSoundset()
	{
		return "CW95_Knocking_SoundSet";
	}

	void KnockAtDoor(int index) 		
	{
		m_IsKnocking = false;
		m_ShouldKnock = true;
		m_Index = index;
		
		SetSynchDirty();
	}

	void StopKnockAtDoor()
	{
		m_ShouldKnock = false;
		m_IsKnocking = true;
		
		SetSynchDirty();
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if ( m_ShouldKnock && !m_IsKnocking )
		{
			StopKnockAtDoor();
#ifndef SERVER
			PlayKnockingSound(m_Index);
#endif
		}
	}

	private void PlayKnockingSound(int index)
	{
		SEffectManager.PlaySound( GetLoopKnockingSoundset(), GetDoorSoundPos(index) );
	}
};
