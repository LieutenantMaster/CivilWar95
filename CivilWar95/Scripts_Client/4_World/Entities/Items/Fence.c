/**
 * Fence.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class Fence
{
	protected bool m_ShouldKnock;

	protected string GetLoopKnockingSoundset()
	{
		return "CW95_Knocking_SoundSet";
	}
	
	void Fence()
	{
		RegisterNetSyncVariableBool( "m_ShouldKnock" );
	}

	void KnockAtDoor() 		
	{
		m_ShouldKnock = true;
		
#ifdef SERVER
		SetSynchDirty();
#endif
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if ( m_ShouldKnock )
		{
			m_ShouldKnock = false;
#ifndef SERVER
			PlayKnockingSound();
#endif
		}
	}

	private void PlayKnockingSound()
	{
		SEffectManager.PlaySound( GetLoopKnockingSoundset(), GetPosition() );
	}
};