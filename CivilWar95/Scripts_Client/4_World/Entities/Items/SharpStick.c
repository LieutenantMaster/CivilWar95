/**
 * SharpWoodenStick.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class SharpWoodenStick
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(MP_ResetPlayerAction);
	}
};
