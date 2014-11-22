/*
 * Copyright (c) 2014  Daniel Hrabovcak
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
**/
#include "Gen1.hpp"
#include "Type.hpp"
#include "Ability.hpp"

PokeCPP::Gen1::Bulbasaur::Bulbasaur() : Monster(1, "Bulbasaur", "For some time "
		"after its birth, it grows by gaining nourishment from the seed on its "
		"back.", Type::Grass, Type::Poison, Ability::Overgrow,
		Ability::Undefined, Ability::Chlorophyll, 45, 49, 49, 65, 65, 45, 70,
		0, 0, 0, 1, 0, 0) {}

bool PokeCPP::Gen1::Bulbasaur::can_evolve_level_up(size_t) const
{
	if (met_evolve_conditions())
	{
		return true;
	}
	return false;
}

PokeCPP::Monster PokeCPP::Gen1::Bulbasaur::evolve_level_up(size_t) const
{
	if (met_evolve_conditions())
	{
		//return Ivysaur();
	}
	return PokeCPP::Monster::MissingNo();
}

/*PokeCPP::Gen1::Ivysaur::Ivysaur() : Monster(2, "Bulbasaur") {}

bool PokeCPP::Gen1::Ivysaur::can_evolve_level_up(size_t) const
{
	if (met_evolve_conditions())
	{
		return true;
	}
	return false;
}

PokeCPP::Monster PokeCPP::Gen1::Ivysaur::evolve_level_up(size_t) const
{
	if (met_evolve_conditions())
	{
		return Venusaur();
	}
	return MissingNo();
}

PokeCPP::Gen1::Venusaur::Venusaur() : Monster(3, "Venusaur") {}
*/
