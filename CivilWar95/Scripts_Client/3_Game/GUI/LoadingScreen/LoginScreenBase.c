/**
 * LoginScreenBase.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class LoginScreenBase
{
	protected ImageWidget m_ExHintIcon;
	protected int m_ExBackgroundIndex = 0;

	protected const float LOADING_SCREEN_CHANGE_TIME = 3.0;
	protected float m_ExLoadingTime;

	protected ImageWidget m_ExBackground;

	protected ref CustomLoadingScreenData m_ExCustomLoadingScreenData;
	protected ref array<int> m_ShownBackgrounds;

	void LoginScreenBase()
	{
		m_ExCustomLoadingScreenData = new CustomLoadingScreenData();

		if (!m_ExCustomLoadingScreenData)
			return;

		m_ShownBackgrounds = new array<int>;
	}

	override void Update(float timeslice)
	{
		super.Update(timeslice);

		m_ExLoadingTime += timeslice;
		if (m_ExLoadingTime >= LOADING_SCREEN_CHANGE_TIME)
		{
			if (m_ShownBackgrounds.Count() < m_ExCustomLoadingScreenData.m_ExBackgrounds.Count())
			{
				m_ExBackgroundIndex = GetRandomBackroundIndex();
				SetBackgroundImage(m_ExBackgroundIndex);
				m_ShownBackgrounds.Insert(m_ExBackgroundIndex);
			}
			else
			{
				m_ShownBackgrounds.Clear();
			}

			m_ExLoadingTime = 0;
		}
	}

	protected int GetRandomBackroundIndex()
	{
		int index = Math.RandomIntInclusive(0, (m_ExCustomLoadingScreenData.m_ExBackgrounds.Count() - 1));
		int searchCount;
		while ((m_ShownBackgrounds.Find(index) > -1) && (searchCount < m_ShownBackgrounds.Count()))
		{
			index = Math.RandomIntInclusive(0, (m_ExCustomLoadingScreenData.m_ExBackgrounds.Count() - 1));
		}

		return index;
	}

	protected void SetBackgroundImage(int index)
	{
		CustomLoadingScreenBackground background = m_ExCustomLoadingScreenData.m_ExBackgrounds.Get(index);
		if (background && background.ImagePath != string.Empty)
		{
			m_ExBackground.LoadImageFile(0, background.ImagePath, true);
			m_ExBackground.SetImage(0);
		}
	}
};
