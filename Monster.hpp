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
#include <string>
using std::string;

namespace PokeCPP
{

	 class Monster
	{
	public:

		 /*!
		  * @brief  Stores the resulting stat differences of a level up.
		 **/
		 struct LevelUpResult
		 {
			 uint8_t hp = 0;
			 uint8_t attack = 0;
			 uint8_t defense = 0;
			 uint8_t spattack = 0;
			 uint8_t spdefense = 0;
			 uint8_t speed = 0;
			 bool evolve = false;
		 };

		/*!
		 * @brief  Returns the unique identifier value of the monster.
		 *
		 * Each monster species is given a unique value.
		**/
		size_t get_uuid() const;

		/*!
		 * @brief  Returns the monster's default species name.
		**/
		const char *get_species_name() const;

		/*!
		 * @brief  Returns the monster's default species description.
		**/
		const char *get_species_description() const;

		/*!
		 * @brief  Returns true if the monster has a nickname.
		 *
		 * Monsters are considered to use a nickname if their name is not the
		 * species name.
		**/
		bool has_nickname() const;

		/*!
		 * @brief  Returns the monster's current name.
		 * @see    set_nickname()
		 * @see    get_species_name();
		 *
		 * If the name is the species name, then this name will change when it
		 * evolves into another species.
		**/
		string get_name() const;

		uint8_t get_nature() const
		{
			return 0; // TODO
		}

		/*!
		 * @brief  Sets the monster's nickname.
		 * @see    get_name()
		 *
		 * If the monster's nickname is the same as the species name, then the
		 * monster's name will not be considered a nickname.
		**/
		void set_nickname(const string &nickname);

		/*!
		 * @brief  Returns the monster's current level.
		**/
		uint8_t get_level() const;

		/*!
		 * @brief  Increases the monster's level and updates the statistics.
		 * @return True if the monster is able to evolve, false otherwise.
		**/
		//LevelUpResult level_up(size_t location_uuid);

		LevelUpResult add_exp(size_t exp, size_t location_uuid,
			uint8_t hp_yield = 0, uint8_t attack_yield = 0,
			uint8_t defense_yield = 0, uint8_t spattack_yield = 0,
			uint8_t spdefense_yield = 0, uint8_t speed_yield = 0);

		/*!
		 * @brief  Evolves a monster as a result of a level increase.
		 * @see    level_up()
		**/
		virtual Monster evolve_level_up(size_t location_uuid) const;

		/*!
		 * @brief  Returns true if the monster is able to evolve as a result of
		 *         a trade, false otherwise.
		 *
		 * The following may be reasons why a monster evolves during trading:
		 *  - Simply because it is being traded.
		 *  - It is holding a certain item.
		 *  - It knows a certain move.
		 *  - It is traded for a specific other monster.
		 *
		 * By default, this returns false.
		**/
		virtual bool can_evolve_trade(size_t traded_for) const;

		/*!
		 * @brief  Evolves a monster as a result of a trade.
		**/
		virtual Monster evolve_trade(size_t traded_for) const;

		/*!
		 * @brief  Returns true if the monster is able to evolve as a result of
		 *         an item.
		 * @param  item_uuid The unique identifier value of the item being
		 *         traded.
		 *
		 * By default, this returns false.
		**/
		virtual bool can_evolve_item(size_t item_uuid) const;

		/*!
		 * @brief  Evolves a monster as a result of an item usage.
		**/
		virtual Monster evolve_item(size_t item_uuid) const;

		uint16_t get_hp() const;
		uint16_t get_attack() const;
		uint16_t get_defense() const;
		uint16_t get_spattack() const;
		uint16_t get_spdefense() const;
		uint16_t get_speed() const;

		uint8_t get_base_hp() const;
		uint8_t get_base_attack() const;
		uint8_t get_base_defense() const;
		uint8_t get_base_spattack() const;
		uint8_t get_base_spdefense() const;
		uint8_t get_base_speed() const;

		uint8_t get_ev_hp() const;
		uint8_t get_ev_attack() const;
		uint8_t get_ev_defense() const;
		uint8_t get_ev_spattack() const;
		uint8_t get_ev_spdefense() const;
		uint8_t get_ev_speed() const;

		uint8_t get_iv_hp() const;
		uint8_t get_iv_attack() const;
		uint8_t get_iv_defense() const;
		uint8_t get_iv_spattack() const;
		uint8_t get_iv_spdefense() const;
		uint8_t get_iv_speed() const;

		uint8_t get_yield_hp() const;
		uint8_t get_yield_attack() const;
		uint8_t get_yield_defense() const;
		uint8_t get_yield_spattack() const;
		uint8_t get_yield_spdefense() const;
		uint8_t get_yield_speed() const;

		/*!
		 * @brief  Returns an error monster with a unique identifier value of 0.
		 *
		 * This value should always be used on error, for example, if an
		 * evolution is not possible but forced.
		**/
		static Monster MissingNo();

	protected:

		Monster(size_t uuid, const char *species_name,
			const char *species_description, uint8_t type1_uuid,
			uint8_t type2_uuid,
			uint8_t ability1_uuid, uint8_t ability2_uuid, uint8_t ability3_uuid,
			uint8_t base_hp, uint8_t base_attack, uint8_t base_defense,
				uint8_t base_spattack, uint8_t base_spdefense,
				uint8_t base_speed, uint8_t base_happiness,
			uint8_t yield_hp, uint8_t yield_attack, uint8_t yield_defense,
				uint8_t yield_spattack, uint8_t yield_spdefense,
				uint8_t yield_speed,
			// uint8_t yield_hp,
			uint8_t ability_number = 0,
			uint8_t iv_hp = 32, uint8_t iv_attack = 32, uint8_t iv_defense = 32,
				uint8_t iv_spattack = 32, uint8_t iv_spdefense = 32,
				uint8_t iv_speed = 32);

		/*!
		 * @brief  Recalculates statistics.
		 *
		 * This class may be reimplemented for monsters whose statistics do not
		 * change normally when they level up. For example, Shedninja's HP is
		 * always 0.
		 *
		 * Do not reimplement this function if you want stats to be recalculated
		 * as normal.
		**/
		virtual void recalculate_stats(LevelUpResult &result);

		/*!
		 * @brief  Returns true if the monster is able to evolve, false
		 *         otherwise.
		 * @todo   Get party members.
		 *
		 * A monster may level up by the following:
		 *  - Friendship has reached a high level.
		 *  - It is holding a certain item.
		 *  - It knows a certain move.
		 *  - It is in a certain location.
		 *  - It is with a certain monster or monster of a certain type is
		 *    currently in the party.
		 *
		 * By default, this returns false.
		**/
		virtual bool can_evolve_level_up(size_t location_uuid) const;

	private:

		// Default values and identifiers.
		const size_t uuid_;
		const char *species_name_;
		const char *species_description_;

		const uint8_t type1_uuid_;
		const uint8_t type2_uuid_;

		const uint8_t ability1_uuid_;
		const uint8_t ability2_uuid_;
		const uint8_t ability3_uuid_;
		const uint8_t ability_number_ : 2;

		const uint8_t base_hp_;
		const uint8_t base_attack_;
		const uint8_t base_defense_;
		const uint8_t base_spattack_;
		const uint8_t base_spdefense_;
		const uint8_t base_speed_;
		const uint8_t base_happiness_;

		const uint8_t yield_hp_ : 2;
		const uint8_t yield_attack_ : 2;
		const uint8_t yield_defense_ : 2;
		const uint8_t yield_spattack_ : 2;
		const uint8_t yield_spdefense_ : 2;
		const uint8_t yield_speed_ : 2;

		const uint8_t iv_hp_ : 4;
		const uint8_t iv_attack_ : 4;
		const uint8_t iv_defense_ : 4;
		const uint8_t iv_spattack_ : 4;
		const uint8_t iv_spdefense_ : 4;
		const uint8_t iv_speed_ : 4;

		//const uint8_t nature_uuid_;
		//const uint8_t catch_rate_;
		//const uint8_t group1_uuid_;
		//const uint8_t group2_uuid_;
		//const uint8_t gender_ratio_;
		// Hatch time.
		//float weight; // in kg
		//float height; // in m
		//const uint8_t exp_yield_;
		//const uint8_t leveling_rate_;
		//const uint8_t body_style_;
		//const uint8_t color_;

		// Nicknames.
		string nickname_;
		bool nick_modified_ = false;

		// Current stats.
		uint8_t level_ = 1;
		uint16_t stat_hp_ = 1;
		uint16_t stat_attack_ = 1;
		uint16_t stat_defense_ = 1;
		uint16_t stat_spattack_ = 1;
		uint16_t stat_spdefense_ = 1;
		uint16_t stat_speed_ = 1;
		uint8_t stat_happiness_ = 1;

		uint16_t ev_hp_ = 0;
		uint16_t ev_attack_ = 0;
		uint16_t ev_defense_ = 0;
		uint16_t ev_spattack_ = 0;
		uint16_t ev_spdefense_ = 0;
		uint16_t ev_speed_ = 0;
	};
}
