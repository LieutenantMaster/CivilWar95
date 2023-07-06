#ifdef EXPANSION_MODSTORAGE
class DZ_CivilWar95 : ModStructure
{
	override void LoadData()
	{
		super.LoadData();

		SetStorageVersion(40);
	}
};
#endif
