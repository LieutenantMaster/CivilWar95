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

#ifdef CW95_ENABLE_KNOCK
modded class BuildingBase
{
	bool m_ShouldKnock;
	int  m_Index;
	
	void BuildingBase()
	{
		RegisterNetSyncVariableBool( "m_ShouldKnock" );
		RegisterNetSyncVariableInt( "m_Index" );
	}

	protected string GetLoopKnockingSoundset()
	{
		return "CW95_Knocking_SoundSet";
	}

	void KnockAtDoor(int index) 		
	{
		m_ShouldKnock = true;
		m_Index = index;
		
		SetSynchDirty();
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

#ifndef SERVER
		PlayKnockingSound(m_Index);
#endif
	}

	void PlayKnockingSound(int index)
	{
		EffectSound knockSound = SEffectManager.PlaySound( GetLoopKnockingSoundset(), GetDoorSoundPos(index) );
		knockSound.SetSoundAutodestroy( true );
	}
};
#endif