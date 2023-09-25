/**
 * CustomLoadingScreenData.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CustomLoadingScreenData
{
	string LogoPath = CW95_PATH_GUI + "cw95vert.edds";
	int LoadingBarColor = ARGB(255, 199, 38, 81);
	string HintIconPath = CW95_PATH_GUI + "icons\\circle_info.edds";

	ref array<ref CustomLoadingScreenBackground> m_ExBackgrounds;

	void CustomLoadingScreenData()
	{
		m_ExBackgrounds = new array<ref CustomLoadingScreenBackground>;
		JsonFileLoader<array<ref CustomLoadingScreenBackground>>.JsonLoadFile(CW95_PATH_SCRIPTS + "Data\\LoadingImages.json", m_ExBackgrounds);
	}
};
