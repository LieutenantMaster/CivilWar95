enum FrontLineTypes
{
	AI = 0,
	MINE,
	ARTI,
	SFX,

	COUNT
};

enum FrontLineArtilleryTypes
{
	HE = 0,
	SMOKE,
	TOXIC,

	COUNT
};


enum CW95RPC
{
	INVALID = 80850,
	FrontLineTrigger,
	SyncTimeCassette,
	COUNT
};

enum CW95SettingsRPC
{
	INVALID = 80000,
	CW95_FrontLineSettings,
	CW95_ConflictGMDSettings,
	COUNT  //! 32 INCREMENT THIS NUMBER AND FOLLOWING RPCs WHEN NEEDED FFS
};

enum CW95FormationsAI
{
	FOR_VEE = 0,
	FOR_INVVEE,
	FOR_FILE,
	FOR_INVFILE,
	FOR_WALL,
	FOR_COL,
	FOR_INVCOL,
	FOR_CIRCLE,
	FOR_CIRCLEDOT,
	FOR_STAR,
	FOR_STARDOT,
	COUNT
};