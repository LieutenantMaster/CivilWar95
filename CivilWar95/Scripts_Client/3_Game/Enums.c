/**
 * Enums.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

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
	FrontLineTrigger = 80851,
	SyncTimeCassette = 80852,
	PlayerHeight = 80853,
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