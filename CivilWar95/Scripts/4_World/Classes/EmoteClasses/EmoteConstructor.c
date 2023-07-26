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