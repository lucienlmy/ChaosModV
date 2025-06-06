#include <stdafx.h>

#include "Effects/Register/RegisterEffect.h"

static void OnStart()
{
	auto playerPed = PLAYER_PED_ID();

	for (Ped ped : GetAllPeds())
	{
		if (!IS_PED_A_PLAYER(ped))
		{
			TASK_REACT_AND_FLEE_PED(ped, playerPed);

			SET_PED_FLEE_ATTRIBUTES(ped, 2, true);
		}
	}
}

// clang-format off
REGISTER_EFFECT(OnStart, nullptr, nullptr, 
	{
		.Name = "All Nearby Peds Are Fleeing",
		.Id = "peds_flee"
	}
);