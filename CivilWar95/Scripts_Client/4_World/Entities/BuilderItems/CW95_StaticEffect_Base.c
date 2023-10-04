/**
 * CW95_Effect_Base.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_Base: House
{
	Particle m_ParticleEfx;
	EffectSound m_SoundSetLoop;

	#ifndef SERVER
	void CW95_Effect_Base()
	{
		DoEffect();
    }

	override void EEDelete(EntityAI parent)
	{
		if ( m_ParticleEfx )
			m_ParticleEfx.Stop();

		if ( m_SoundSetLoop )
			StopSoundSet( m_SoundSetLoop );
	}
	#endif

    void DoEffect() {}
};

/**
 * CW95_Effect_CAMP_FIRE_START.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_CAMP_FIRE_START: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.CAMP_FIRE_START, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_CAMP_SMALL_FIRE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_CAMP_SMALL_FIRE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.CAMP_SMALL_FIRE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_CAMP_NORMAL_FIRE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_CAMP_NORMAL_FIRE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.CAMP_NORMAL_FIRE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_CAMP_SMALL_SMOKE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_CAMP_SMALL_SMOKE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.CAMP_SMALL_SMOKE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_CAMP_NORMAL_SMOKE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_CAMP_NORMAL_SMOKE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.CAMP_NORMAL_SMOKE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_CAMP_FIRE_END.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_CAMP_FIRE_END: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.CAMP_FIRE_END, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_CAMP_STEAM_2END.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_CAMP_STEAM_2END: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.CAMP_STEAM_2END, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_CAMP_STEAM_EXTINGUISH_START.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_CAMP_STEAM_EXTINGUISH_START: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.CAMP_STEAM_EXTINGUISH_START, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_CAMP_STOVE_FIRE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_CAMP_STOVE_FIRE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.CAMP_STOVE_FIRE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_CAMP_STOVE_FIRE_START.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_CAMP_STOVE_FIRE_START: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.CAMP_STOVE_FIRE_START, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_CAMP_STOVE_FIRE_END.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_CAMP_STOVE_FIRE_END: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.CAMP_STOVE_FIRE_END, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_CAMP_NO_IGNITE_WIND.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_CAMP_NO_IGNITE_WIND: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.CAMP_NO_IGNITE_WIND, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_HOUSE_FIRE_START.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_HOUSE_FIRE_START: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.HOUSE_FIRE_START, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_HOUSE_SMALL_FIRE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_HOUSE_SMALL_FIRE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.HOUSE_SMALL_FIRE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_HOUSE_SMALL_SMOKE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_HOUSE_SMALL_SMOKE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.HOUSE_SMALL_SMOKE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_HOUSE_NORMAL_FIRE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_HOUSE_NORMAL_FIRE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.HOUSE_NORMAL_FIRE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_HOUSE_NORMAL_SMOKE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_HOUSE_NORMAL_SMOKE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.HOUSE_NORMAL_SMOKE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_HOUSE_FIRE_END.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_HOUSE_FIRE_END: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.HOUSE_FIRE_END, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_HOUSE_FIRE_STEAM_2END.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_HOUSE_FIRE_STEAM_2END: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.HOUSE_FIRE_STEAM_2END, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BARREL_FIRE_START.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BARREL_FIRE_START: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BARREL_FIRE_START, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BARREL_SMALL_FIRE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BARREL_SMALL_FIRE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BARREL_SMALL_FIRE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BARREL_SMALL_SMOKE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BARREL_SMALL_SMOKE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BARREL_SMALL_SMOKE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BARREL_NORMAL_FIRE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BARREL_NORMAL_FIRE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BARREL_NORMAL_FIRE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BARREL_NORMAL_SMOKE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BARREL_NORMAL_SMOKE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BARREL_NORMAL_SMOKE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BARREL_FIRE_END.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BARREL_FIRE_END: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BARREL_FIRE_END, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BARREL_FIRE_STEAM_2END.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BARREL_FIRE_STEAM_2END: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BARREL_FIRE_STEAM_2END, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_OVEN_FIRE_START.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_OVEN_FIRE_START: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.OVEN_FIRE_START, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_OVEN_SMALL_FIRE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_OVEN_SMALL_FIRE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.OVEN_SMALL_FIRE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_OVEN_NORMAL_FIRE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_OVEN_NORMAL_FIRE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.OVEN_NORMAL_FIRE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_OVEN_FIRE_END.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_OVEN_FIRE_END: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.OVEN_FIRE_END, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_COOKING_BOILING_EMPTY.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_COOKING_BOILING_EMPTY: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.COOKING_BOILING_EMPTY, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_COOKING_BOILING_START.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_COOKING_BOILING_START: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.COOKING_BOILING_START, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_COOKING_BOILING_DONE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_COOKING_BOILING_DONE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.COOKING_BOILING_DONE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_COOKING_BAKING_START.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_COOKING_BAKING_START: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.COOKING_BAKING_START, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_COOKING_BAKING_DONE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_COOKING_BAKING_DONE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.COOKING_BAKING_DONE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_COOKING_DRYING_START.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_COOKING_DRYING_START: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.COOKING_DRYING_START, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_COOKING_DRYING_DONE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_COOKING_DRYING_DONE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.COOKING_DRYING_DONE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_COOKING_BURNING_DONE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_COOKING_BURNING_DONE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.COOKING_BURNING_DONE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_TORCH_T3.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_TORCH_T3: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.TORCH_T3, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_TORCH_T1.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_TORCH_T1: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.TORCH_T1, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_TORCH_T2.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_TORCH_T2: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.TORCH_T2, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BROOM_TORCH_T1.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BROOM_TORCH_T1: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BROOM_TORCH_T1, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BROOM_TORCH_T2.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BROOM_TORCH_T2: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BROOM_TORCH_T2, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BROOM_TORCH_T3.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BROOM_TORCH_T3: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BROOM_TORCH_T3, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_ROADFLARE_BURNING_INIT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_ROADFLARE_BURNING_INIT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.ROADFLARE_BURNING_INIT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_ROADFLARE_BURNING_MAIN.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_ROADFLARE_BURNING_MAIN: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.ROADFLARE_BURNING_MAIN, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_ROADFLARE_BURNING_ENDING.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_ROADFLARE_BURNING_ENDING: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.ROADFLARE_BURNING_ENDING, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_ROADFLARE_BURNING_SMOKE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_ROADFLARE_BURNING_SMOKE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.ROADFLARE_BURNING_SMOKE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_FLAREPROJ_FIRE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_FLAREPROJ_FIRE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.FLAREPROJ_FIRE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_FLAREPROJ_ACTIVATE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_FLAREPROJ_ACTIVATE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.FLAREPROJ_ACTIVATE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_FLAREPROJ_ACTIVATE_RED.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_FLAREPROJ_ACTIVATE_RED: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.FLAREPROJ_ACTIVATE_RED, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_FLAREPROJ_ACTIVATE_GREEN.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_FLAREPROJ_ACTIVATE_GREEN: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.FLAREPROJ_ACTIVATE_GREEN, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_FLAREPROJ_ACTIVATE_BLUE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_FLAREPROJ_ACTIVATE_BLUE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.FLAREPROJ_ACTIVATE_BLUE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_DIGGING_STASH.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_DIGGING_STASH: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.DIGGING_STASH, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_RDG2_BLACK_START.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_RDG2_BLACK_START: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_RDG2_BLACK_START, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_RDG2_BLACK_LOOP.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_RDG2_BLACK_LOOP: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_RDG2_BLACK_LOOP, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_RDG2_BLACK_END.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_RDG2_BLACK_END: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_RDG2_BLACK_END, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_RDG2_WHITE_START.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_RDG2_WHITE_START: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_RDG2_WHITE_START, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_RDG2_WHITE_LOOP.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_RDG2_WHITE_LOOP: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_RDG2_WHITE_LOOP, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_RDG2_WHITE_END.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_RDG2_WHITE_END: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_RDG2_WHITE_END, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M18_GREEN_START.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M18_GREEN_START: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_GREEN_START, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M18_GREEN_LOOP.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M18_GREEN_LOOP: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_GREEN_LOOP, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M18_GREEN_END.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M18_GREEN_END: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_GREEN_END, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M18_PURPLE_START.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M18_PURPLE_START: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_PURPLE_START, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M18_PURPLE_LOOP.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M18_PURPLE_LOOP: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_PURPLE_LOOP, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M18_PURPLE_END.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M18_PURPLE_END: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_PURPLE_END, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M18_RED_START.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M18_RED_START: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_RED_START, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M18_RED_LOOP.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M18_RED_LOOP: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_RED_LOOP, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M18_RED_END.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M18_RED_END: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_RED_END, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M18_WHITE_START.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M18_WHITE_START: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_WHITE_START, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M18_WHITE_LOOP.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M18_WHITE_LOOP: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_WHITE_LOOP, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M18_WHITE_END.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M18_WHITE_END: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_WHITE_END, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M18_YELLOW_START.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M18_YELLOW_START: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_YELLOW_START, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M18_YELLOW_LOOP.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M18_YELLOW_LOOP: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_YELLOW_LOOP, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M18_YELLOW_END.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M18_YELLOW_END: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_YELLOW_END, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M18_BLACK_START.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M18_BLACK_START: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_BLACK_START, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M18_BLACK_LOOP.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M18_BLACK_LOOP: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_BLACK_LOOP, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M18_BLACK_END.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M18_BLACK_END: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_BLACK_END, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_M84.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_M84: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M84, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_RGD5.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_RGD5: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.RGD5, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_M67.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_M67: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.M67, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_POWER_GENERATOR_SMOKE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_POWER_GENERATOR_SMOKE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.POWER_GENERATOR_SMOKE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BARBED_WIRE_SPARKS.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BARBED_WIRE_SPARKS: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BARBED_WIRE_SPARKS, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_EASTER_EGG_ACTIVATE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_EASTER_EGG_ACTIVATE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.EASTER_EGG_ACTIVATE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BLEEDING_SOURCE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BLEEDING_SOURCE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BLEEDING_SOURCE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BLEEDING_SOURCE_LIGHT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BLEEDING_SOURCE_LIGHT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BLEEDING_SOURCE_LIGHT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BLOOD_SURFACE_DROPS.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BLOOD_SURFACE_DROPS: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BLOOD_SURFACE_DROPS, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BLOOD_SURFACE_CHUNKS.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BLOOD_SURFACE_CHUNKS: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BLOOD_SURFACE_CHUNKS, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_VOMIT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_VOMIT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.VOMIT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BREATH_VAPOUR_LIGHT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BREATH_VAPOUR_LIGHT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BREATH_VAPOUR_LIGHT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BREATH_VAPOUR_MEDIUM.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BREATH_VAPOUR_MEDIUM: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BREATH_VAPOUR_MEDIUM, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BREATH_VAPOUR_HEAVY.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BREATH_VAPOUR_HEAVY: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BREATH_VAPOUR_HEAVY, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_VOMIT_CHUNKS.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_VOMIT_CHUNKS: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.VOMIT_CHUNKS, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_MUZZLE_FLASH_SVD_STAR.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_MUZZLE_FLASH_SVD_STAR: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_MUZZLE_FLASH_SVD_STAR, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_SOLO_MUZZLE_FLASH.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_SOLO_MUZZLE_FLASH: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_SOLO_MUZZLE_FLASH, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_FNX.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_FNX: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_FNX, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_FNX_SUPPRESSED.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_FNX_SUPPRESSED: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_FNX_SUPPRESSED, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_PARTICLE_TEST.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_PARTICLE_TEST: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_PARTICLE_TEST, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_PARTICLE_CASING.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_PARTICLE_CASING: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_PARTICLE_CASING, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_PARTICLE_CASING_RAISE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_PARTICLE_CASING_RAISE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_PARTICLE_CASING_RAISE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_CZ75.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_CZ75: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_CZ75, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_AKM.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_AKM: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_AKM, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_AKM_SUPPRESSED.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_AKM_SUPPRESSED: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_AKM_SUPPRESSED, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_IZH18.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_IZH18: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_IZH18, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_IZH18_SUPPRESSED.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_IZH18_SUPPRESSED: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_IZH18_SUPPRESSED, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_MP5K.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_MP5K: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_MP5K, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_MP5K_2.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_MP5K_2: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_MP5K_2, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_MP5K_SUPPRESSED.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_MP5K_SUPPRESSED: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_MP5K_SUPPRESSED, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_MP5K_COMPENSATOR.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_MP5K_COMPENSATOR: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_MP5K_COMPENSATOR, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_UMP45.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_UMP45: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_UMP45, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_M4A1.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_M4A1: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_M4A1, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_MP133.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_MP133: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_MP133, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_PELLETS.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_PELLETS: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_PELLETS, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_MOSIN9130.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_MOSIN9130: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_MOSIN9130, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_MOSIN_COMPENSATOR.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_MOSIN_COMPENSATOR: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_MOSIN_COMPENSATOR, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_CZ527.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_CZ527: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_CZ527, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_SKS.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_SKS: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_SKS, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_WINCHESTER70.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_WINCHESTER70: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_WINCHESTER70, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_VSS.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_VSS: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_VSS, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_AK74.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_AK74: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_AK74, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_AK101.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_AK101: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_AK101, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_MAGNUM.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_MAGNUM: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_MAGNUM, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_CZ61.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_CZ61: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_CZ61, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_LONG_WINDED_SMOKE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_LONG_WINDED_SMOKE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_LONG_WINDED_SMOKE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GUN_LONG_WINDED_SMOKE_SMALL.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GUN_LONG_WINDED_SMOKE_SMALL: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GUN_LONG_WINDED_SMOKE_SMALL, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_SMOKING_BARREL.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_SMOKING_BARREL: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.SMOKING_BARREL, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_SMOKING_BARREL_SMALL.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_SMOKING_BARREL_SMALL: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.SMOKING_BARREL_SMALL, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_SMOKING_BARREL_HEAVY.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_SMOKING_BARREL_HEAVY: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.SMOKING_BARREL_HEAVY, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_SMOKING_BARREL_STEAM.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_SMOKING_BARREL_STEAM: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.SMOKING_BARREL_STEAM, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_SMOKING_BARREL_STEAM_SMALL.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_SMOKING_BARREL_STEAM_SMALL: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.SMOKING_BARREL_STEAM_SMALL, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_SMARKS_CHAMBER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_SMARKS_CHAMBER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.SMARKS_CHAMBER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_TEST.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_TEST: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_TEST, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_DISTANT_DUST.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_DISTANT_DUST: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_DISTANT_DUST, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_TEST_RICOCHET.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_TEST_RICOCHET: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_TEST_RICOCHET, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_TEST2.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_TEST2: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_TEST2, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_TEST_ENTER_DEBUG.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_TEST_ENTER_DEBUG: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_TEST_ENTER_DEBUG, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_TEST_RICOCHET_DEBUG.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_TEST_RICOCHET_DEBUG: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_TEST_RICOCHET_DEBUG, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_TEST_EXIT_DEBUG.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_TEST_EXIT_DEBUG: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_TEST_EXIT_DEBUG, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_TEST_NO_MATERIAL_ERROR.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_TEST_NO_MATERIAL_ERROR: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_TEST_NO_MATERIAL_ERROR, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_WOOD_ENTER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_WOOD_ENTER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_WOOD_ENTER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_WOOD_RICOCHET.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_WOOD_RICOCHET: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_WOOD_RICOCHET, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_WOOD_EXIT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_WOOD_EXIT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_WOOD_EXIT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_CONCRETE_ENTER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_CONCRETE_ENTER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_CONCRETE_ENTER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_CONCRETE_RICOCHET.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_CONCRETE_RICOCHET: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_CONCRETE_RICOCHET, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_CONCRETE_EXIT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_CONCRETE_EXIT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_CONCRETE_EXIT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_FOLIAGE_ENTER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_FOLIAGE_ENTER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_FOLIAGE_ENTER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_FOLIAGE_RICOCHET.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_FOLIAGE_RICOCHET: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_FOLIAGE_RICOCHET, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_FOLIAGE_EXIT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_FOLIAGE_EXIT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_FOLIAGE_EXIT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_GRASS_ENTER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_GRASS_ENTER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_GRASS_ENTER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_GRASS_RICOCHET.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_GRASS_RICOCHET: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_GRASS_RICOCHET, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_DIRT_ENTER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_DIRT_ENTER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_DIRT_ENTER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_DIRT_RICOCHET.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_DIRT_RICOCHET: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_DIRT_RICOCHET, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_DIRT_EXIT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_DIRT_EXIT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_DIRT_EXIT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_RUBBER_ENTER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_RUBBER_ENTER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_RUBBER_ENTER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_RUBBER_RICOCHET.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_RUBBER_RICOCHET: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_RUBBER_RICOCHET, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_RUBBER_EXIT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_RUBBER_EXIT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_RUBBER_EXIT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_GRAVEL_ENTER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_GRAVEL_ENTER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_GRAVEL_ENTER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_GRAVEL_RICOCHET.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_GRAVEL_RICOCHET: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_GRAVEL_RICOCHET, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_GRAVEL_EXIT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_GRAVEL_EXIT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_GRAVEL_EXIT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_PLASTER_ENTER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_PLASTER_ENTER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_PLASTER_ENTER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_PLASTER_RICOCHET.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_PLASTER_RICOCHET: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_PLASTER_RICOCHET, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_PLASTER_EXIT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_PLASTER_EXIT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_PLASTER_EXIT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_METAL_ENTER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_METAL_ENTER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_METAL_ENTER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_METAL_RICOCHET.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_METAL_RICOCHET: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_METAL_RICOCHET, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_METAL_EXIT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_METAL_EXIT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_METAL_EXIT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_MEAT_ENTER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_MEAT_ENTER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_MEAT_ENTER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_MEAT_RICOCHET.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_MEAT_RICOCHET: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_MEAT_RICOCHET, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_MEAT_EXIT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_MEAT_EXIT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_MEAT_EXIT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_MEATBONES_ENTER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_MEATBONES_ENTER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_MEATBONES_ENTER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_MEATBONES_RICOCHET.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_MEATBONES_RICOCHET: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_MEATBONES_RICOCHET, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_MEATBONES_EXIT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_MEATBONES_EXIT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_MEATBONES_EXIT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_GLASS_ENTER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_GLASS_ENTER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_GLASS_ENTER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_GLASS_RICOCHET.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_GLASS_RICOCHET: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_GLASS_RICOCHET, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_GLASS_EXIT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_GLASS_EXIT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_GLASS_EXIT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_WATER_SMALL_ENTER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_WATER_SMALL_ENTER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_WATER_SMALL_ENTER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_WATER_MEDIUM_ENTER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_WATER_MEDIUM_ENTER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_WATER_MEDIUM_ENTER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_WATER_LARGE_ENTER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_WATER_LARGE_ENTER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_WATER_LARGE_ENTER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_TEXTILE_ENTER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_TEXTILE_ENTER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_TEXTILE_ENTER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_TEXTILE_RICOCHET.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_TEXTILE_RICOCHET: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_TEXTILE_RICOCHET, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_TEXTILE_EXIT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_TEXTILE_EXIT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_TEXTILE_EXIT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_SAND_ENTER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_SAND_ENTER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_SAND_ENTER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_SAND_RICOCHET.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_SAND_RICOCHET: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_SAND_RICOCHET, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_SAND_EXIT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_SAND_EXIT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_SAND_EXIT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_PLASTIC_ENTER.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_PLASTIC_ENTER: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_PLASTIC_ENTER, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_PLASTIC_RICOCHET.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_PLASTIC_RICOCHET: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_PLASTIC_RICOCHET, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_IMPACT_PLASTIC_EXIT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_IMPACT_PLASTIC_EXIT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.IMPACT_PLASTIC_EXIT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_EXPLOSION_LANDMINE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_EXPLOSION_LANDMINE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.EXPLOSION_LANDMINE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_EXPLOSION_TEST.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_EXPLOSION_TEST: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.EXPLOSION_TEST, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_SMOKING_HELI_WRECK.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_SMOKING_HELI_WRECK: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.SMOKING_HELI_WRECK, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_AURORA_SANTA_WRECK.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_AURORA_SANTA_WRECK: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.AURORA_SANTA_WRECK, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_SMOKE_GENERIC_WRECK.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_SMOKE_GENERIC_WRECK: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.SMOKE_GENERIC_WRECK, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_SMOKING_CAR_ENGINE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_SMOKING_CAR_ENGINE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.SMOKING_CAR_ENGINE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_EVAPORATION.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_EVAPORATION: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.EVAPORATION, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_HATCHBACK_COOLANT_OVERHEATING.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_HATCHBACK_COOLANT_OVERHEATING: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.HATCHBACK_COOLANT_OVERHEATING, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_HATCHBACK_COOLANT_OVERHEATED.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_HATCHBACK_COOLANT_OVERHEATED: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.HATCHBACK_COOLANT_OVERHEATED, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_HATCHBACK_ENGINE_OVERHEATING.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_HATCHBACK_ENGINE_OVERHEATING: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.HATCHBACK_ENGINE_OVERHEATING, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_HATCHBACK_ENGINE_OVERHEATED.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_HATCHBACK_ENGINE_OVERHEATED: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.HATCHBACK_ENGINE_OVERHEATED, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_HATCHBACK_EXHAUST_SMOKE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_HATCHBACK_EXHAUST_SMOKE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.HATCHBACK_EXHAUST_SMOKE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_ENV_SWARMING_FLIES.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_ENV_SWARMING_FLIES: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.ENV_SWARMING_FLIES, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BONFIRE_FIRE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BONFIRE_FIRE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BONFIRE_FIRE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_BONFIRE_SMOKE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_BONFIRE_SMOKE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.BONFIRE_SMOKE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_SPOOKY_MIST.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_SPOOKY_MIST: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.SPOOKY_MIST, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_VOMIT_BLOOD.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_VOMIT_BLOOD: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.VOMIT_BLOOD, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_CONTAMINATED_AREA_GAS_TINY.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_CONTAMINATED_AREA_GAS_TINY: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.CONTAMINATED_AREA_GAS_TINY, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_CONTAMINATED_AREA_GAS_AROUND.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_CONTAMINATED_AREA_GAS_AROUND: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.CONTAMINATED_AREA_GAS_AROUND, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_CONTAMINATED_AREA_GAS_BIGASS.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_CONTAMINATED_AREA_GAS_BIGASS: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.CONTAMINATED_AREA_GAS_BIGASS, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_CONTAMINATED_AREA_GAS_GROUND.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_CONTAMINATED_AREA_GAS_GROUND: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.CONTAMINATED_AREA_GAS_GROUND, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_CONTAMINATED_AREA_GAS_SHELL.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_CONTAMINATED_AREA_GAS_SHELL: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.CONTAMINATED_AREA_GAS_SHELL, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_FIREWORKS_SHOT.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_FIREWORKS_SHOT: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.FIREWORKS_SHOT, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_FIREWORKS_EXPLOSION_RED.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_FIREWORKS_EXPLOSION_RED: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.FIREWORKS_EXPLOSION_RED, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_FIREWORKS_EXPLOSION_GREEN.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_FIREWORKS_EXPLOSION_GREEN: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.FIREWORKS_EXPLOSION_GREEN, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_FIREWORKS_EXPLOSION_BLUE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_FIREWORKS_EXPLOSION_BLUE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.FIREWORKS_EXPLOSION_BLUE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_FIREWORKS_EXPLOSION_YELLOW.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_FIREWORKS_EXPLOSION_YELLOW: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.FIREWORKS_EXPLOSION_YELLOW, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_FIREWORKS_EXPLOSION_PINK.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_FIREWORKS_EXPLOSION_PINK: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.FIREWORKS_EXPLOSION_PINK, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_FIREWORKS_FUSE.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_FIREWORKS_FUSE: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.FIREWORKS_FUSE, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_FIREWORKS_AFTERBURN_START.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_FIREWORKS_AFTERBURN_START: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.FIREWORKS_AFTERBURN_START, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_FIREWORKS_AFTERBURN_END.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_FIREWORKS_AFTERBURN_END: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.FIREWORKS_AFTERBURN_END, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_GRENADE_CHEM_BREAK.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_GRENADE_CHEM_BREAK: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_CHEM_BREAK, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_CLAYMORE_EXPLOSION.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_CLAYMORE_EXPLOSION: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.CLAYMORE_EXPLOSION, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_PLASTIC_EXPLOSION.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_PLASTIC_EXPLOSION: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.PLASTIC_EXPLOSION, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_WATER_JET.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_WATER_JET: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.WATER_JET, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_WATER_JET_WEAK.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_WATER_JET_WEAK: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.WATER_JET_WEAK, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_WATER_SPILLING.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_WATER_SPILLING: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.WATER_SPILLING, this, Vector(0, 0, 0));
	}
};

/**
 * CW95_Effect_DROWNING_BUBBLES.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Effect_DROWNING_BUBBLES: CW95_Effect_Base
{
	override void DoEffect()
	{
        m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.DROWNING_BUBBLES, this, Vector(0, 0, 0));
	}
};
