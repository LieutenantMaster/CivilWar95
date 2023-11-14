/**
 * CW95_SearchGroundBase.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_SearchGroundBaseCB: ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(1.0);
	}
};

class CW95_SearchGroundBase: ActionContinuousBase
{
    autoptr TStringArray SEARCH_OBJECTS = new TStringArray;
    autoptr TStringArray SEARCH_LOOT = new TStringArray;

    static vector m_Search_Pos;
    static vector m_Search_Rot;

    static int m_EffectId;
    static int m_LootChance;
    static int m_BlacklistChance;

	void CW95_SearchGroundBase()
	{
		m_CallbackClass 	= CW95_SearchGroundBaseCB;
		m_CommandUID		= DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
		m_FullBody			= true;
		m_StanceMask		= DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight	= UASoftSkillsWeight.ROUGH_LOW;
		m_Text 				= "#STR_CW95_ACTIONS_DIGUPGRAVE";
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem		= new CCINonRuined();
		m_ConditionTarget	= new CCTDummy();
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (player.IsPlacingLocal())
			return false;
        
		Object obj;
		if ( !Class.CastTo(obj, target.GetObject()) )
		    return false;

        #ifndef SERVER
        string debug_name = obj.GetDebugNameNative();
        if (debug_name == string.Empty)
            return false;
        
        array<string> split_string = {};
        debug_name.Split(":", split_string);
        
        if (split_string.Count() == 1)
            return false;

        if ( SEARCH_OBJECTS.Find(split_string[1].Trim()) == -1 )
            return false;
        
        TIntArray idToDel;
        bool alreadySearched;
        vector pos = obj.GetPosition();
        int time = GetGame().GetTime();
        for(int i=0; i < player.m_TimeStampPositions.Count(); i++)
        {
            if ( time - player.m_TimeStampPositions[i] > 600000 )
                idToDel.Insert(i);

            if ( alreadySearched )
                continue;

            if ( vector.Distance(pos, player.m_InteractedPositions[i]) < 1 )
                alreadySearched = true;
        }

        foreach(int id: idToDel)
        {
            player.m_TimeStampPositions.Remove(id);
            player.m_InteractedPositions.Remove(id);
        }

        if ( alreadySearched )
            return false;
        #endif

        return true;
	}
	
	override bool Can(PlayerBase player, ActionTarget target, ItemBase item, int condition_mask)
	{
		if (!super.Can(player, target, item, condition_mask))
			return false;
		
		return player.CheckFreeSpace(vector.Forward, 1.0, false);
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, 8);
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);

        if ( Math.RandomIntInclusive(0, 10) <= m_LootChance )
        {
            int id = Math.RandomIntInclusive(0, SEARCH_LOOT.Count() - 1);

		    GetGame().CreateObjectEx(SEARCH_LOOT[id], action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE);
        }
	}
	
	protected override void OnStartAnimationLoopClient( ActionData action_data )
	{
        super.OnStartAnimationLoopClient(action_data);

        m_Search_Pos = action_data.m_Target.GetObject().GetPosition();
        m_Search_Rot = m_Search_Pos.VectorToAngles();

        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlayEffect, 1500, true);
	}

	protected override void OnEndAnimationLoopClient( ActionData action_data )
	{
        super.OnEndAnimationLoopClient(action_data);

        GetGame().GetUpdateQueue(CALL_CATEGORY_GAMEPLAY).Remove(PlayEffect);
    }

	override void OnFinishProgressClient( ActionData action_data )
	{
        if ( Math.RandomIntInclusive(0, 10) <= m_BlacklistChance )
        {
            int time = GetGame().GetTime();
            action_data.m_Player.m_TimeStampPositions.Insert(time);
            action_data.m_Player.m_InteractedPositions.Insert(m_Search_Pos);
        }

        GetGame().GetUpdateQueue(CALL_CATEGORY_GAMEPLAY).Remove(PlayEffect);
	}

    void PlayEffect()
    {
        Particle p1 = Particle.Play(m_EffectId, m_Search_Pos + Vector(Math.RandomFloatInclusive(-0.25,0.25), Math.RandomFloatInclusive(-0.25,0.25), Math.RandomFloatInclusive(-0.25,0.25)) );
        p1.SetOrientation(m_Search_Rot + Vector(Math.RandomFloatInclusive(-5,5), Math.RandomFloatInclusive(-5,5), Math.RandomFloatInclusive(-5,5)));
    }
};
