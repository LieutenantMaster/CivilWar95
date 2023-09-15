/**
 * MainMenu.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class MainMenu
{
	override Widget Init()
	{
		layoutRoot = super.Init();

        ImageWidget dayZLogo = ImageWidget.Cast(layoutRoot.FindAnyWidget("dayz_logo"));
        dayZLogo.LoadImageFile(0, "CivilWar95\\CivilWar95\\GUI\\cw95vertwide.edds");
        dayZLogo.SetFlags(dayZLogo.GetFlags() | WidgetFlags.STRETCH);

		m_ModdedWarning.Show(false);

		return layoutRoot;
	}

	override void LoadMods()
	{
        super.LoadMods();

		m_ModdedWarning.Show(false);
	}
};
