/**
 * EmoteConstructor.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class EmoteConstructor
{	
	override void RegisterEmotes(TTypenameArray emotes)
	{
		super.RegisterEmotes(emotes);
		
		emotes.Insert(EmoteCough);
		emotes.Insert(EmoteSneeze);
		emotes.Insert(EmoteLaughFreaky);
		emotes.Insert(EmoteShiver);
		emotes.Insert(EmoteWipeFace);
	}
}