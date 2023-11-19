modded class ExpansionTraderNPCBase
{
    bool HasWhitlist()
    {
        return false;
    }

    bool IsWhistelisted(string uid)
    {
        return true;
    }
};

class CW95_TraderMirrorStand: ExpansionTraderNPCBase{};
class CW95_TraderMachineACoudre: ExpansionTraderNPCBase
{
    override bool HasWhitlist()
    {
        return true;
    }
    
    override bool IsWhistelisted(string uid)
    {
        switch(uid)
        {
            case "pZmEb-J3KuvGDsxzUWTlJVL7Ntg2T5LFezpKN33q8E=":
                return true;
            break;
        }
        
        return false;
    }
};