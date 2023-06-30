class ArmedLandMineTrap: LandMineTrap
{
    void ArmedLandMineTrap()
    {
        StartActivate(null);
    }
};

class ArmedBearTrap: BearTrap
{
    void ArmedBearTrap()
    {
		SetState(DEPLOYED);
        StartActivate(null);
    }
};