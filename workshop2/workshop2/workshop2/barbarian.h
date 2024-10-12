#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H
#include <iostream>
#include <iomanip>
#include <string>
#include "character.h"


namespace seneca {
	template <typename T, typename Ability_t, typename Weapon_t>
	class Barbarian : public CharacterTpL<T> {
		Ability_t m_ability;
		T m_baseAttack
			T m_baseDefense;
		Weapon_t m_weapon[2];

		Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon);
		int getAttackAmnt() const;
		int getDefenseAmnt() const;
		Character* clone() const;
		void attack(Character* enemy);
		void takeDamage(int dmg);



	};

}

#endif