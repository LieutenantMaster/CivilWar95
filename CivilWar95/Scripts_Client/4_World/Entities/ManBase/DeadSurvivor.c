class DeadSurvivor: PlayerBase
{
    void DeadSurvivor()
    {
        ExpansionHumanLoadout.Apply(this, GetDeadLoadoutType(), false);
    }

    string GetDeadLoadoutType()
    {
        return "";
    }
};
