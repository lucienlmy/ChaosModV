#include <stdafx.h>

#include "Effects/Register/RegisterEffect.h"

static void OnTick()
{
	Player player = PLAYER_ID();

	SET_EXPLOSIVE_MELEE_THIS_FRAME(player);
	SET_EXPLOSIVE_AMMO_THIS_FRAME(player);

	Vector3 impactCoords;

	for (Ped ped : GetAllPeds())
		if (GET_PED_LAST_WEAPON_IMPACT_COORD(ped, &impactCoords))
			ADD_EXPLOSION(impactCoords.x, impactCoords.y, impactCoords.z, 4, 9999.f, true, false, 1.f, false);
}

// clang-format off
REGISTER_EFFECT(nullptr, nullptr, OnTick, 
	{
		.Name = "Explosive Combat",
		.Id = "player_explosivecombat",
		.IsTimed = true
	}
);