modded class LoginQueueBase
{
	override Widget Init()
	{
		layoutRoot = super.Init();

		m_ExBackground = ImageWidget.Cast(layoutRoot.FindAnyWidget("Background"));

		SetBackgroundImage(m_ExBackgroundIndex);
		m_ExBackgroundIndex++;

		return layoutRoot;
	}
};