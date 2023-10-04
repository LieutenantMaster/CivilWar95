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
	float GetRocketPosOffset(int id)
	{
		if (id % 2 == 0)
			return -2.5;
		
		return 2.5;
	}

	int GetRocketAmount()
	{
		return -1;
	}
};

modded class EXT_AH1Z
{
	override int GetRocketAmount()
	{
		return 2;
	}
};

modded class EXT_AH64D
{
	override int GetRocketAmount()
	{
		return 2;
	}
};

modded class EXT_MI24
{
	override float GetRocketPosOffset(int id)
	{
		if (id % 4 == 0)
			return -2.5;
		else if (id % 3 == 0)
			return 5;
		else if (id % 2 == 0)
			return -5;
			
		return 2.5;
	}

	override int GetRocketAmount()
	{
		return 4;
	}
};

modded class EXT_KA52
{
	override int GetRocketAmount()
	{
		return 2;
	}
};

modded class EXT_KA60
{
	override int GetRocketAmount()
	{
		return 2;
	}
};

modded class EXT_Mi8_Attack
{
	override float GetRocketPosOffset(int id)
	{
		if (id % 4 == 0)
			return -2.5;
		else if (id % 3 == 0)
			return 5;
		else if (id % 2 == 0)
			return -5;
			
		return 2.5;
	}

	override int GetRocketAmount()
	{
		return 4;
	}
};

modded class EXT_Mi171
{
	override float GetRocketPosOffset(int id)
	{
		if (id % 6 == 0)
			return -2.5;
		else if (id % 5 == 0)
			return 7.5;
		else if (id % 4 == 0)
			return -7.5;
		else if (id % 3 == 0)
			return 5;
		else if (id % 2 == 0)
			return -5;
			
		return 2.5;
	}

	override int GetRocketAmount()
	{
		return 6;
	}
};
