/**
 * EmoteCough.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class EmoteCough: EmoteBase
{
	void EmoteCough()
	{
		m_ID = EmoteConstants.ID_EMOTE_COUGH;
		m_InputActionName = "EmoteCough";
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = SymptomIDs.SYMPTOM_COUGH;
		m_FullbodyCallbackUID = SymptomIDs.SYMPTOM_COUGH;
		m_HideItemInHands = false;
	}
};
/**
 * EmoteSneeze.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class EmoteSneeze: EmoteBase
{
	void EmoteSneeze()
	{
		m_ID = EmoteConstants.ID_EMOTE_SNEEZE;
		m_InputActionName = "EmoteSneeze";
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = SymptomIDs.SYMPTOM_SNEEZE;
		m_FullbodyCallbackUID = SymptomIDs.SYMPTOM_SNEEZE;
		m_HideItemInHands = false;
	}
};
/**
 * EmoteLaughFreaky.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class EmoteLaughFreaky: EmoteBase
{
	void EmoteLaughFreaky()
	{
		m_ID = EmoteConstants.ID_EMOTE_LAUGHFREAKY;
		m_InputActionName = "EmoteLaughFreaky";
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = SymptomIDs.SYMPTOM_LAUGHTER;
		m_FullbodyCallbackUID = SymptomIDs.SYMPTOM_LAUGHTER;
		m_HideItemInHands = false;
	}
};
/**
 * EmoteShiver.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class EmoteShiver: EmoteBase
{
	void EmoteShiver()
	{
		m_ID = EmoteConstants.ID_EMOTE_SHIVER;
		m_InputActionName = "EmoteShiver";
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = SymptomIDs.SYMPTOM_HAND_SHIVER;
		m_FullbodyCallbackUID = SymptomIDs.SYMPTOM_HAND_SHIVER;
		m_HideItemInHands = false;
	}
};
/**
 * EmoteWipeFace.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class EmoteWipeFace: EmoteBase
{
	void EmoteWipeFace()
	{
		m_ID = EmoteConstants.ID_EMOTE_WIPEFACE;
		m_InputActionName = "EmoteWipeFace";
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = SymptomIDs.SYMPTOM_FEVERBLUR;
		m_FullbodyCallbackUID = SymptomIDs.SYMPTOM_FEVERBLUR;
		m_HideItemInHands = false;
	}
};