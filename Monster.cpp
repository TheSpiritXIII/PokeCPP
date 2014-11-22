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
#include "Monster.hpp"
#include "Type.hpp"
#include "Ability.hpp"
#include "Nature.hpp"

#include <ctime>
#include <cstdlib>
#include <cassert>

size_t PokeCPP::Monster::get_uuid() const
{
	return uuid_;
}

const char *PokeCPP::Monster::get_species_name() const
{
	return species_name_;
}

const char *PokeCPP::Monster::get_species_description() const
{
	return species_description_;
}

bool PokeCPP::Monster::has_nickname() const
{
	return nick_modified_;
}

string PokeCPP::Monster::get_name() const
{
	return nickname_;
}

void PokeCPP::Monster::set_nickname(const string &nickname)
{
	nickname_ = nickname;
	nick_modified_ = (nickname_ == species_name_);
}

uint8_t PokeCPP::Monster::get_level() const
{
	return level_;
}

PokeCPP::Monster::LevelUpResult PokeCPP::Monster::add_exp(size_t exp,
	size_t location_uuid, uint8_t hp_yield, uint8_t attack_yield,
	uint8_t defense_yield, uint8_t spattack_yield, uint8_t spdefense_yield,
	uint8_t speed_yield)
{
	LevelUpResult result;

	ev_hp_ += hp_yield;
	ev_attack_ += attack_yield;
	ev_defense_ += defense_yield;
	ev_attack_ += spattack_yield;
	ev_defense_ += spdefense_yield;
	ev_speed_ += speed_yield;

	if (false) // TODO check if added enough exp to level up.
	{
		++level_;
		recalculate_stats(result);
		result.evolve = can_evolve_level_up(location_uuid);
	}

	return result;
}

PokeCPP::Monster PokeCPP::Monster::evolve_level_up(size_t) const
{
	return MissingNo();
}

bool PokeCPP::Monster::can_evolve_trade(size_t) const
{
	return false;
}

PokeCPP::Monster PokeCPP::Monster::evolve_trade(size_t) const
{
	return MissingNo();
}

bool PokeCPP::Monster::can_evolve_item(size_t) const
{
	return false;
}

uint16_t PokeCPP::Monster::get_hp() const
{
	return stat_hp_;
}

uint16_t PokeCPP::Monster::get_attack() const
{
	return stat_attack_;
}

uint16_t PokeCPP::Monster::get_defense() const
{
	return stat_defense_;
}

uint16_t PokeCPP::Monster::get_spattack() const
{
	return stat_spattack_;
}

uint16_t PokeCPP::Monster::get_spdefense() const
{
	return stat_spdefense_;
}

uint16_t PokeCPP::Monster::get_speed() const
{
	return stat_speed_;
}

uint8_t PokeCPP::Monster::get_base_hp() const
{
	return base_hp_;
}

uint8_t PokeCPP::Monster::get_base_attack() const
{
	return base_attack_;
}

uint8_t PokeCPP::Monster::get_base_defense() const
{
	return base_defense_;
}

uint8_t PokeCPP::Monster::get_base_spattack() const
{
	return base_spattack_;
}

uint8_t PokeCPP::Monster::get_base_spdefense() const
{
	return base_spdefense_;
}

uint8_t PokeCPP::Monster::get_base_speed() const
{
	return base_speed_;
}

uint8_t PokeCPP::Monster::get_ev_hp() const
{
	return ev_hp_;
}

uint8_t PokeCPP::Monster::get_ev_attack() const
{
	return ev_attack_;
}

uint8_t PokeCPP::Monster::get_ev_defense() const
{
	return ev_defense_;
}

uint8_t PokeCPP::Monster::get_ev_spattack() const
{
	return ev_spattack_;
}

uint8_t PokeCPP::Monster::get_ev_spdefense() const
{
	return ev_spdefense_;
}

uint8_t PokeCPP::Monster::get_ev_speed() const
{
	return ev_speed_;
}

uint8_t PokeCPP::Monster::get_iv_hp() const
{
	return iv_hp_;
}

uint8_t PokeCPP::Monster::get_iv_attack() const
{
	return iv_attack_;
}

uint8_t PokeCPP::Monster::get_iv_defense() const
{
	return iv_defense_;
}

uint8_t PokeCPP::Monster::get_iv_spattack() const
{
	return iv_spattack_;
}

uint8_t PokeCPP::Monster::get_iv_spdefense() const
{
	return iv_spdefense_;
}

uint8_t PokeCPP::Monster::get_iv_speed() const
{
	return iv_speed_;
}

uint8_t PokeCPP::Monster::get_yield_hp() const
{
	return yield_hp_;
}

PokeCPP::Monster PokeCPP::Monster::evolve_item(size_t) const
{
	return MissingNo();
}

PokeCPP::Monster PokeCPP::Monster::MissingNo()
{
	return Monster(0, "MissingNo", "---", Type::Normal, Type::Undefined,
		Ability::Undefined, Ability::Undefined, Ability::Undefined,
		33, 136, 0, 6, 6, 29, 70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

PokeCPP::Monster::Monster(size_t uuid,
	const char *species_name, const char *species_description,
	uint8_t type1_uuid, uint8_t type2_uuid,
	uint8_t ability1_uuid, uint8_t ability2_uuid, uint8_t ability3_uuid,
	uint8_t base_hp, uint8_t base_attack, uint8_t base_defense,
		uint8_t base_spattack, uint8_t base_spdefense,
		uint8_t base_speed, uint8_t base_happiness,
	uint8_t yield_hp, uint8_t yield_attack, uint8_t yield_defense,
		uint8_t yield_spattack, uint8_t yield_spdefense,
		uint8_t yield_speed,
	uint8_t ability_number,
	uint8_t iv_hp, uint8_t iv_attack, uint8_t iv_defense,
		uint8_t iv_spattack, uint8_t iv_spdefense, uint8_t iv_speed) :
	uuid_(uuid),
	species_name_(species_name), species_description_(species_description),
	type1_uuid_(type1_uuid), type2_uuid_(type2_uuid),
	ability1_uuid_(ability1_uuid), ability2_uuid_(ability2_uuid),
		ability3_uuid_(ability3_uuid), ability_number_(ability_number),
	base_hp_(base_hp), base_attack_(base_attack), base_defense_(base_defense),
		base_spattack_(base_spattack), base_spdefense_(base_spdefense),
		base_speed_(base_speed), base_happiness_(base_happiness),
	// TOOD: EV yields
	yield_hp_(yield_hp), yield_attack_(yield_attack),
		yield_defense_(yield_defense), yield_spattack_(yield_spattack),
		yield_spdefense_(yield_spdefense), yield_speed_(yield_speed),
	// IV values are always between 0 and 31.
	// Any higher, we discard it and generate one instead.
	iv_hp_(iv_hp > 31 ? iv_hp : rand() % 32),
		iv_attack_(iv_attack > 32 ? iv_attack : rand() % 32),
		iv_defense_(iv_defense > 32 ? iv_defense : rand() % 32),
		iv_spattack_(iv_spattack > 32 ? iv_spattack : rand() % 32),
		iv_spdefense_(iv_spdefense > 32 ? iv_spdefense : rand() % 32),
		iv_speed_(iv_speed > 32 ? iv_speed : rand() % 32)
{
	assert(ability_number < 3);

	LevelUpResult result; // Unused.
	recalculate_stats(result);
}

void PokeCPP::Monster::recalculate_stats(LevelUpResult &result)
{
	uint16_t value;

	// HP
	value = ((get_iv_hp() + (2 * get_base_hp()) + (get_ev_hp()) + 100) *
		get_level()) / 100 + 10;
	result.hp = value - get_hp();
	stat_hp_ = value;

	// Attack
	value = static_cast<uint16_t>(get_iv_attack() +
		(2 * get_base_attack()) + (get_ev_attack() / 4) * get_level() /
		100.0f + 5) * Nature::Calculator::get_attack_boost(get_nature());
	result.attack = value - get_attack();
	stat_attack_ = value;

	// Defense
	value = static_cast<uint16_t>(get_iv_defense() +
		(2 * get_base_defense()) + (get_ev_defense() / 4) * get_level() /
		100.0f + 5) * Nature::Calculator::get_defense_boost(get_nature());
	result.defense = value - get_defense();
	stat_defense_ = value;

	// Sp. Attack
	value = static_cast<uint16_t>(get_iv_spattack() +
		(2 * get_base_spattack()) + (get_ev_spattack() / 4) * get_level() /
		100.0f + 5) * Nature::Calculator::get_spattack_boost(get_nature());
	result.spattack = value - get_spattack();
	stat_spattack_ = value;

	// Sp. Defense
	value = static_cast<uint16_t>(get_iv_spdefense() +
		(2 * get_base_spdefense()) + (get_ev_spdefense() / 4) * get_level() /
		100.0f + 5) * Nature::Calculator::get_spdefense_boost(get_nature());
	result.spdefense = value - get_spdefense();
	stat_spdefense_ = value;

	// Speed
	value = static_cast<uint16_t>(get_iv_speed() +
		(2 * get_base_speed()) + (get_ev_speed() / 4) * get_level() /
		100.0f + 5) * Nature::Calculator::get_speed_boost(get_nature());
	result.speed = value - get_speed();
	stat_speed_ = value;
}

bool PokeCPP::Monster::can_evolve_level_up(size_t) const
{
	return false;
}
