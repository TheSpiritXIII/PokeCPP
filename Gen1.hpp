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
#include "Monster.hpp"
#include "Nature.hpp"

namespace PokeCPP
{
	namespace Gen1
	{
		class Bulbasaur : public Monster
		{
		public:
			Bulbasaur();
			virtual bool can_evolve_level_up(size_t) const;
			virtual Monster evolve_level_up(size_t) const;
			inline bool met_evolve_conditions() const
			{
				return get_level() == 16;
			}
		};

		/*class Ivysaur : public Monster
		{
		public:
			Ivysaur();
			virtual bool can_evolve_level_up(size_t) const;
			virtual Monster evolve_level_up(size_t) const;
			inline bool met_evolve_conditions() const
			{
				return get_level() == 32;
			}
		};

		class Venusaur : public Monster
		{
		public:
			Venusaur();
		};*/
	}
}
