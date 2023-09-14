/**
 * PluginRecipesManagerBase.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class PluginRecipesManagerBase
{	
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		
		RegisterRecipe(new CW95_CraftBigToSmallStones);
		RegisterRecipe(new CW95_CraftMetalPlate);

		UnregisterRecipe("CutOutZucchiniSeeds");
		UnregisterRecipe("CutOutPepperSeeds");
		UnregisterRecipe("CutOutPumpkinSeeds");
		UnregisterRecipe("CutOutTomatoSeeds");
	}
};