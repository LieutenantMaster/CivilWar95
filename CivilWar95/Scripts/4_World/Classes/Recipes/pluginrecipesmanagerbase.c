modded class PluginRecipesManagerBase
{	
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		
		RegisterRecipe(new CV95_CraftBigToSmallStones);
		RegisterRecipe(new CV95_CraftMetalPlate);

		UnregisterRecipe("CutOutZucchiniSeeds");
		UnregisterRecipe("CutOutPepperSeeds");
		UnregisterRecipe("CutOutPumpkinSeeds");
		UnregisterRecipe("CutOutTomatoSeeds");
	}
};