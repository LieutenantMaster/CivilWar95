class CW95_Teleporter: Expansion_Teleporter_Base{};

modded class ExpansionTeleportData
{
	override void SpawnTeleporter()
	{
		Object obj = GetGame().CreateObjectEx("CW95_Teleporter", m_ObjectPosition, ECE_NONE);
		Expansion_Teleporter_Base teleportObj = Expansion_Teleporter_Base.Cast(obj);

		teleportObj.SetPosition(m_ObjectPosition);
		teleportObj.SetOrientation(m_ObjectOrientation);
		teleportObj.SetTeleporterID(m_ID);
		teleportObj.SetActive(true);
	}
};