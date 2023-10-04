/**
 * CarScript.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class ExpansionHelicopterScript
{
	override void SetActions()
	{
		super.SetActions();

		AddAction( CW95_ActionVehicleFlare );
		AddAction( CW95_ActionVehicleRocket );
	}

	override bool CanFireFromSeatIndex(PlayerBase player)
	{
		switch(CrewMemberIndex( player ))
		{
			case DayZPlayerConstants.VEHICLESEAT_DRIVER:
				return CrewMember(DayZPlayerConstants.VEHICLESEAT_CODRIVER) == NULL;
			break;
			case DayZPlayerConstants.VEHICLESEAT_CODRIVER:
				return true;
			break;
		}

		return false;
	}

	override bool CanDecoyFromSeatIndex(PlayerBase player)
	{
		switch(CrewMemberIndex( player ))
		{
			case DayZPlayerConstants.VEHICLESEAT_DRIVER:
				return CrewMember(DayZPlayerConstants.VEHICLESEAT_CODRIVER) == NULL;
			break;
			case DayZPlayerConstants.VEHICLESEAT_CODRIVER:
				return true;
			break;
		}

		return false;
	}

	override bool HasDecoys()
	{
		return true;
	}
};

modded class ExpansionGyrocopter
{
	override bool HasDecoys()
	{
		return false;
	}
};

modded class ExpansionMh6
{
	override bool HasDecoys()
	{
		return false;
	}
};

modded class EXT_AH1Z
{
	override bool HasArmement()
	{
		return true;
	}
};

modded class EXT_AH64D
{
	override bool HasArmement()
	{
		return true;
	}
};

modded class EXT_MI24
{
	override bool HasArmement()
	{
		return true;
	}
};

modded class EXT_KA52
{
	override bool HasArmement()
	{
		return true;
	}
};

modded class EXT_KA60
{
	override bool HasArmement()
	{
		return true;
	}
};

modded class EXT_Mi8_Attack
{
	override bool HasArmement()
	{
		return true;
	}
};

modded class EXT_Mi171
{
	override bool HasArmement()
	{
		return true;
	}
};
