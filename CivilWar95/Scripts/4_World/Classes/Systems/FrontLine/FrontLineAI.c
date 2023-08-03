/**
 * FrontLineAI.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class FrontLineAI: FrontLineEventBase
{
    private string m_FactionName = "FrontLine";
    private autoptr TStringArray m_LoadoutNames =
    {
        "FrontLine_Sniper", // Light Vest, Hat
        "FrontLine_Soldier",// Medium Vest, Helmet
        "FrontLine_Leader", // Medium Vest, Beret/Cap
        "FrontLine_Heavy",  // Heavy Vest, Heavy Helmet
        "FrontLine_Light"   // No Vest, No Helmet
    };

    override void Spawn()
    {        
        vector position;
        if ( vector.Distance(m_NewPosition, m_TargetPos) > m_MaxRadius )
        {
            m_NewPosition = m_TargetPos + Vector(Math.RandomFloatInclusive(-m_Radius, m_Radius), 0, Math.RandomFloatInclusive(-m_Radius, m_Radius));
        }
        else
        {
            m_NewPosition = m_NewPosition + Vector(Math.RandomFloatInclusive(-m_Radius, m_Radius), 0, Math.RandomFloatInclusive(-m_Radius, m_Radius));
        }
        
        m_Objects.Insert(GetGame().CreateObjectEx( GetItemToSpawn(), m_NewPosition, ECE_PLACE_ON_SURFACE ));

        if ( m_Quantity > 0 )
        {
            m_Quantity--;
            GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( Spawn, Math.RandomIntInclusive(2000, 10000), false );
        }
    }

	eAIBase SpawnAI_Helper(eAIBase owner, string loadout = "HumanLoadout.json")
	{
		auto group = eAIGroup.GetGroupByLeader(owner);
		auto form = group.GetFormation();
		vector pos = ExpansionAISpawnBase.GetPlacementPosition(form.ToWorld(form.GetPosition(group.Count())));
		eAIBase ai;
		if (Class.CastTo(ai, GetGame().CreateObject(GetRandomAI(), pos)))
			ExpansionHumanLoadout.Apply(ai, loadout, true);

		if (ai)
			ai.SetGroup(group);

		return ai;
	}

    /*
    eAIFormation GetRandomFormation()
    {
        int rndFormation = Math.RandomFloatInclusive(0, CV95FormationsAI.COUNT);
        switch (rndFormation)
        {
            case CV95FormationsAI.FOR_VEE:
                return new eAIFormationVee(g);
                break;
            case CV95FormationsAI.FOR_INVVEE:
                return new eAIFormationInvVee(g);
                break;
            case CV95FormationsAI.FOR_FILE:
                return new eAIFormationFile(g);
                break;
            case CV95FormationsAI.FOR_INVFILE:
                return new eAIFormationInvFile(g);
                break;
            case CV95FormationsAI.FOR_WALL:
                return new eAIFormationWall(g);
                break;
            case CV95FormationsAI.FOR_COL:
                return new eAIFormationColumn(g);
                break;
            case CV95FormationsAI.FOR_INVCOL:
                return new eAIFormationInvColumn(g);
                break;
            case CV95FormationsAI.FOR_CIRCLE:
                return new eAIFormationCircle(g);
                break;
            case CV95FormationsAI.FOR_CIRCLEDOT:
                return new eAIFormationCircleDot(g);
                break;
            case CV95FormationsAI.FOR_STAR:
                return new eAIFormationStar(g);
                break;
            case CV95FormationsAI.FOR_STARDOT:
                return new eAIFormationStarDot(g);
                break;
        }
        return new eAIFormationVee(g);
    }
    */
};
