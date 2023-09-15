/**
 * ActionConstructor.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
		
		actions.Insert( CW95_ActionRaiseWhistleSelf );
		//actions.Insert( CW95_ActionKnockAtDoor );

		actions.Insert(MP_PlayMusicAction);
		actions.Insert(MP_StopAction);

		actions.Insert(MP_OpenDoorAction);
		actions.Insert(MP_CloseDoorAction);

		actions.Insert(MP_FastForwardAction);
		actions.Insert(MP_RewindAction);

		actions.Insert(MPFP_VolumeUPAction);
		actions.Insert(MPFP_VolumeDOWNAction);

		actions.Insert(MPFP_Play);
		actions.Insert(MPFP_Stop);

		actions.Insert(MP_ResetPlayerAction);
	}
};
