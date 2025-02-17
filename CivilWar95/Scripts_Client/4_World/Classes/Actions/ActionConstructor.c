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

		//! ARMED VEHICLES
		actions.Insert(CW95_ActionVehicleFlare);
		actions.Insert(CW95_ActionVehicleRocket);

		//! FIREFIGHTING
		actions.Insert(CW95_ActionExtinguishByExtinguisher);
		actions.Insert(CW95_ActionExtinguishByLiquid);
		
		//! MISC
		actions.Insert(CW95_ActionRaiseWhistleSelf);
		
#ifdef CW95_ENABLE_KNOCK
		actions.Insert(CW95_ActionKnockAtDoor);
#endif
		actions.Insert(CW95_DigUpGrave);

		//! MUSIC PLAYER
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
	}
};
