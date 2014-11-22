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

namespace PokeCPP
{
	namespace Nature
	{
		const uint8_t Undefined	= 0;
		const uint8_t Hardy		= 1;
		const uint8_t Lonely	= 2;
		const uint8_t Brave		= 3;
		const uint8_t Adamant	= 4;
		const uint8_t Naughty	= 5;
		const uint8_t Bold		= 6;
		const uint8_t Docile	= 7;
		const uint8_t Relaxed	= 8;
		const uint8_t Impish	= 9;
		const uint8_t Lax		= 10;
		const uint8_t Timid		= 11;
		const uint8_t Hasty		= 12;
		const uint8_t Serious	= 13;
		const uint8_t Jolly		= 14;
		const uint8_t Naive		= 15;
		const uint8_t Modest	= 16;
		const uint8_t Mild		= 17;
		const uint8_t Quiet		= 18;
		const uint8_t Bashful	= 19;
		const uint8_t Rash		= 20;
		const uint8_t Calm		= 21;
		const uint8_t Gentle	= 22;
		const uint8_t Sassy		= 23;
		const uint8_t Careful	= 24;
		const uint8_t Quirky	= 25;

		class Calculator
		{
		public:

			static float get_attack_boost(uint8_t nature_uuid)
			{
				switch (nature_uuid)
				{
				case Lonely:
				case Brave:
				case Adamant:
				case Naughty:
					return 1.1f;
				case Bold:
				case Modest:
				case Calm:
				case Timid:
					return 0.9f;
				default:
					return 1.0f;
				}
			}

			static float get_defense_boost(uint8_t nature_uuid)
			{
				switch (nature_uuid)
				{
				case Bold:
				case Impish:
				case Lax:
				case Relaxed:
					return 1.1f;
				case Lonely:
				case Mild:
				case Gentle:
				case Hasty:
					return 0.9f;
				default:
					return 1.0f;
				}
			}

			static float get_spattack_boost(uint8_t nature_uuid)
			{
				switch (nature_uuid)
				{
				case Modest:
				case Mild:
				case Rash:
				case Quiet:
					return 1.1f;
				case Adamant:
				case Impish:
				case Careful:
				case Jolly:
					return 0.9f;
				default:
					return 1.0f;
				}
			}

			static float get_spdefense_boost(uint8_t nature_uuid)
			{
				switch (nature_uuid)
				{
				case Calm:
				case Gentle:
				case Careful:
				case Sassy:
					return 1.1f;
				case Naughty:
				case Lax:
				case Rash:
				case Naive:
					return 0.9f;
				default:
					return 1.0f;
				}
			}

			static float get_speed_boost(uint8_t nature_uuid)
			{
				switch (nature_uuid)
				{
				case Timid:
				case Hasty:
				case Jolly:
				case Naive:
					return 1.1f;
				case Brave:
				case Relaxed:
				case Quiet:
				case Sassy:
					return 0.9f;
				default:
					return 1.0f;
				}
			}
		};
	}
}
