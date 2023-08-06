/**
 * DZ_CivilWar95.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

#ifdef EXPANSION_MODSTORAGE
class DZ_CivilWar95: ModStructure
{
	override void LoadData()
	{
		super.LoadData();

		SetStorageVersion(40);
	}
};
#endif
