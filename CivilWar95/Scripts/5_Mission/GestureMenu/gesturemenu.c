enum CV95GestureCategories : GestureCategories
{
	CATEGORY_6
};

/**
 * GesturesMenu.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class GesturesMenu
{	
	override protected void GetGestureItems(out ref array<ref GestureMenuItem> gesture_items, GestureCategories category)
	{
		super.GetGestureItems(gesture_items, category);

		#ifndef DIAG
		return; // Dont show until it's ready
		#endif
		
		if (category == GestureCategories.CATEGORIES)
		{
			gesture_items.Insert(new GestureMenuItem(GestureCategories.CATEGORY_5, "Bodyemotes", category));
			gesture_items.Insert(new GestureMenuItem(CV95GestureCategories.CATEGORY_6, "Stance", category));
		}
		else if (category == GestureCategories.CATEGORY_5)
		{
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_COUGH, "Cough", category));
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_SNEEZE, "Sneeze", category));
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_LAUGHFREAKY, "Laugh Crazily", category));
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_SHIVER, "Shiver", category));
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_WIPEFACE, "Wipe forehead", category));
			//gesture_items.Insert( new GestureMenuItem(EmoteConstants.ID_EMOTE_GUNSHOULDER, "Gun on shoulder", category));
			//gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_BLOODYHANDS, "Bloody hands", category));
		}
		else if (category == CV95GestureCategories.CATEGORY_6)
		{
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_HEALTHY, "Healthy", category));
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_WORN, "Painly", category));
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_DAMAGED, "Hurt", category));
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_BADLYDAMAGED, "Badly hurt", category));
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_RUINED, "Almost dead", category));
		}
	}
};
