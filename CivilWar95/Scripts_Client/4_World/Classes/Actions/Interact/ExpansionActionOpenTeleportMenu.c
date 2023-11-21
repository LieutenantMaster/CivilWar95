modded class ExpansionActionOpenTeleportMenu
{
	void ExpansionActionOpenTeleportMenu()
	{
		m_Text = "#use";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Expansion_Teleporter_Base teleportObj = Expansion_Teleporter_Base.Cast(target.GetObject());
		if (!teleportObj)
			return false;

		return true;
	}

	override void OnExecuteServer(ActionData action_data)
	{
		PlayerBase player = action_data.m_Player;
		if (!player || !player.GetIdentity())
			return;

		if (!CF_Modules<ExpansionTeleporterModule>.Get(m_Expansion_TeleporterModule))
			return;

		Object targetObject;
		if (!Class.CastTo(targetObject, action_data.m_Target.GetParentOrObject()))
			return;
		
		Expansion_Teleporter_Base teleportObj = Expansion_Teleporter_Base.Cast(targetObject);
		if (!teleportObj || teleportObj && !teleportObj.IsActive())
			return;
		
		int teleporterID = teleportObj.GetTeleporterID();
		ExpansionTeleportData teleporterData = m_Expansion_TeleporterModule.GetTeleporterDataByID(teleporterID);
		if (!teleporterData)
			return;

	#ifdef EXPANSIONMODQUESTS
		if (GetExpansionSettings().GetQuest().EnableQuests)
		{
			int questID = teleporterData.GetQuestID();
			Print(ToString() + "::OnExecuteServer - Need to complete quest with ID: " + questID);
			if (questID > -1)
			{
				//! Check if player has completed required quest
				if (!ExpansionQuestModule.GetModuleInstance().HasCompletedQuest(questID, player.GetIdentity().GetId()))
				{
					ExpansionQuestConfig questConig = ExpansionQuestModule.GetModuleInstance().GetQuestConfigByID(questID);
					if (!questConig)
					{
						Error(ToString() + "::OnExecuteServer - Could not get quest config for quest ID: " + questID);
						return;
					}
		
					ExpansionNotification(new StringLocaliser("Teleporter is locked!"), new StringLocaliser("You have no access to this teleporter yet. You need to compelete the quest " + questConig.GetTitle() + " first to use this teleporter."), ExpansionIcons.GetPath("Exclamationmark"), COLOR_EXPANSION_NOTIFICATION_AMETHYST, 10, ExpansionNotificationType.TOAST).Create(player.GetIdentity());
					return;
				}
			}
		}
	#endif
		
	#ifdef EXPANSIONMODAI
		string factionName = teleporterData.GetFaction();
		bool isInFaction;
		bool isInInOtherFaction;
		Print(ToString() + "::OnExecuteServer - Need to be in faction: " + factionName);
		if (factionName != string.Empty)
		{
			eAIGroup group = player.GetGroup();
			if (!group)
				group = eAIGroup.GetGroupByLeader(player);
			
			Print(ToString() + "::OnExecuteServer - Player group: " + group.ToString());
			if (group)
			{
				eAIFaction playerFaction = group.GetFaction();
				Print(ToString() + "::OnExecuteServer - Player faction: " + playerFaction.ToString());
				if (playerFaction)
				{
					string playerFactionName = playerFaction.GetName();
					Print(ToString() + "::OnExecuteServer - Player faction name: " + playerFactionName);
					if (playerFactionName == factionName)
					{
						isInFaction = true;
					}
					else
					{
						if (playerFactionName != string.Empty)
							isInInOtherFaction = true;
					}
				}
			}
			
			if (!isInFaction)
			{
				string message;
				if (isInInOtherFaction)
					message = "You have no access to this teleporter. You need to be a member of the " + factionName + " faction. You are a member of the " + playerFactionName + " faction.";
				else
					message = "You have no access to this teleporter. You need to be a member of the " + factionName + " faction.";
				
				ExpansionNotification(new StringLocaliser("Teleporter is locked!"), new StringLocaliser(message), ExpansionIcons.GetPath("Exclamationmark"), COLOR_EXPANSION_NOTIFICATION_AMETHYST, 10, ExpansionNotificationType.TOAST).Create(player.GetIdentity());
				return;
			}
		}
	#endif

		array<ref ExpansionTeleportPosition> tpPosList = teleporterData.GetTeleportPositions();
		if ( !tpPosList )
			return;

		ExpansionTeleportPositionEntry tpPos = tpPosList[0].GetPositions()[0];
		if ( !tpPos )
			return;

		player.SetPosition(tpPos.GetPosition());
		player.SetOrientation(tpPos.GetOrientation());
	}
};
