#ifndef SENECA_ARCHER_H
#define SENECA_ARCHER_H
#include <iostream>
#include <iomanip>
#include <string>
#include "weapons.h"
#include "characterTpI.cpp"
#include "character.h"

namespace myseneca{
template <typename Weapon_t>
class Archer : public CharacterTpL<seneca::SuperHealth> {
	int m_baseDefense; 
	int m_baseAttack; 
	Weapon_t m_weapon; 

public: 
	Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon) :
		: 
		CharacterTpl<seneca::SuperHealth>(name, healthMax),
		m_baseAttack(baseAttack),
		m_baseDefense(baseDefense),
		m_weapon(weapon) 
	{}
	int getAttackAmnt() const override {
		return static_cast<int>(1.3 * m_baseAttack);
	}

	int getDefenseAmnt() const override {
		return static_cast<int>(1.2 * m_baseDefense);
	}

	Character* clone() const override {
		return new <Weapon_t>(*this); 
	}

	void attack(Character* enemy) {
		std::cout << this->m_name << "is attacking" << enemy->getName() << "." << std::endl;

		int damage = getAttackAmnt(); 

		std::cout << "Archer deals " << damage << " ranged damage!" << std::endl;

		enemy->takeDamage(damage);


		void takeDamage(int dmg) override {
			std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
			std::cout << "Archer has a defense of " << getDefenseAmnt() << ". Reducing damage received." << std::endl;

			dmg -= getDefenseAmnt();
			if (dmg < 0) dmg = 0;  

			CharacterTpl<seneca::SuperHealth>::takeDamage(dmg);
		}
	}
};
}
#endif