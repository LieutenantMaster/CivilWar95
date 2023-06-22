modded class PluginRecipesManagerBase
{	
	override void RegisterRecipies()
	{
		super.RegisterRecipies();

		UnregisterRecipe("CutOutZucchiniSeeds");
		UnregisterRecipe("CutOutPepperSeeds");
		UnregisterRecipe("CutOutPumpkinSeeds");
		UnregisterRecipe("CutOutTomatoSeeds");
	}
};