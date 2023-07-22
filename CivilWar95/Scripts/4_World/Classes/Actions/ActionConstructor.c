modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

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
