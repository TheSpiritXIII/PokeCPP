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
#pragma once
#include <cstdint>

namespace PokeCPP
{
	namespace Type
	{
		const uint8_t Undefined	= 0;
		const uint8_t None		= 1;
		const uint8_t Normal	= 2;
		const uint8_t Fire		= 3;
		const uint8_t Fighting	= 4;
		const uint8_t Water		= 5;
		const uint8_t Flying	= 6;
		const uint8_t Grass		= 7;
		const uint8_t Poison	= 8;
		const uint8_t Electric	= 9;
		const uint8_t Ground	= 10;
		const uint8_t Psychic	= 11;
		const uint8_t Rock		= 12;
		const uint8_t Ice		= 13;
		const uint8_t Bug		= 14;
		const uint8_t Dragon	= 15;
		const uint8_t Ghost		= 16;
		const uint8_t Dark		= 17;
		const uint8_t Steel		= 18;
		const uint8_t Fairy		= 19;
	}

	const char *type_to_string(uint8_t type);
}
