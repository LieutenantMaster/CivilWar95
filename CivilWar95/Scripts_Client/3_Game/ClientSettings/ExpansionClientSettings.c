/**
 * ExpansionClientSettings.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class ExpansionClientSettings
{
	override void OnSettingsUpdated(typename type, ExpansionSettingSerializationBase setting)
	{
        EnableGPSBasedOnVehicleSpeed = true;
		ShowPINCode = false;

		super.OnSettingsUpdated(type, setting);
	}

	override private void OnSave( ParamsWriteContext ctx )
	{
        EnableGPSBasedOnVehicleSpeed = true;
		ShowPINCode = false;

		super.OnSave(ctx);
    }
};
