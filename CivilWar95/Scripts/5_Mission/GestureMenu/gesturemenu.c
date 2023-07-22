enum CV95GestureCategories : GestureCategories
{
	CATEGORY_6
};

modded class GesturesMenu
{
	override void OnMenuRelease() //here .... cuz dayz .... gives protected error if not here
	{
		//execute on release (mouse only)
		super.OnMenuRelease();
	}
	
	override protected void GetGestureItems(out ref array<ref GestureMenuItem> gesture_items, GestureCategories category)
	{
		super.GetGestureItems(gesture_items, category);
		if (category == GestureCategories.CATEGORIES)
		{
			gesture_items.Insert(new GestureMenuItem(GestureCategories.CATEGORY_5, "Bodyemotes", GestureCategories.CATEGORIES));
			gesture_items.Insert(new GestureMenuItem(CV95GestureCategories.CATEGORY_6, "Stance", GestureCategories.CATEGORIES));
		}
		else if (category == GestureCategories.CATEGORY_5)
		{
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_COUGH, "Cough", GestureCategories.CATEGORY_5));
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_SNEEZE, "Sneeze", GestureCategories.CATEGORY_5));
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_LAUGHFREAKY, "Laugh Crazily", GestureCategories.CATEGORY_5));
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_SHIVER, "Shiver", GestureCategories.CATEGORY_5));
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_WIPEFACE, "Wipe forehead", GestureCategories.CATEGORY_5));
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_GUNSHOULDER, "Gun on shoulder", 				GestureCategories.CATEGORY_5 ) );
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_BLOODYHANDS, "Bloody hands", GestureCategories.CATEGORY_5));

		}
		else if (category == CV95GestureCategories.CATEGORY_6)
		{
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_HEALTHY, "Healthy", CV95GestureCategories.CATEGORY_6));
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_WORN, "Painly", CV95GestureCategories.CATEGORY_6));
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_DAMAGED, "Hurt", CV95GestureCategories.CATEGORY_6));
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_BADLYDAMAGED, "Badly hurt", CV95GestureCategories.CATEGORY_6));
			gesture_items.Insert(new GestureMenuItem(EmoteConstants.ID_EMOTE_RUINED, "Almost dead", CV95GestureCategories.CATEGORY_6));

		}
	}
};
