modded class Torch
{
	override bool IsTwoHandedBehaviour()
	{
		return true;
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
	}

	override bool IsDeployable()
	{
		return true;
	}
}