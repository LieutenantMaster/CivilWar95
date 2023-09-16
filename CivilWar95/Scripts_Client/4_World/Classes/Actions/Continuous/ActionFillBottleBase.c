/**
 * ActionSmokeCigSelf.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class ActionFillBottleBase
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		CarScript car = CarScript.Cast(target.GetObject());
		if (car)
			return car.IsFuelStation();

		Object targetObject = target.GetObject();
		if (targetObject)
            return targetObject.IsFuelStation();
        
		return super.ActionCondition(player, target, item);
	}
};
