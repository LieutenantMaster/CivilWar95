modded class ExpansionTraderStaticBase
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

class CW95_TraderMirrorStand: ExpansionTraderStaticBase{};
class CW95_TraderMachineACoudre: ExpansionTraderStaticBase
{
    override bool HasWhitlist()
    {
        return true;
    }
    
    override bool IsWhistelisted(string uid)
    {
        switch(uid)
        {
            case "diq2SOAMNu6AHBClAK5UKWeGBpcO_FAWeXPELaY6avs=":
            case "pZmEb-J3KuvGDsxzUWTlJVL7Ntg2T5LFezpKN33q8E=":
                return true;
            break;
        }

        return false;
    }
};