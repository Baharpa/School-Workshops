#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H
#include <iostream>
#include <iomanip>
#include <string>
#include "character.h"


namespace seneca {
	template <typename T, typename Ability_t, typename Weapon_t>
	class Barbarian : public CharacterTpl<T> {
		Ability_t m_ability;
		T m_baseAttack;
		T m_baseDefense;
		Weapon_t m_weapon[2];

	public: 
		Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon)
			: CharacterTpl<T>(name, healthMax), m_baseAttack(baseAttack), m_baseDefense(baseDefense){
			m_weapond[0] = primaryWeapon; 
			m_weapon[1] = secondaryWeapon;
		}

		int getAttackAmnt() const override {
			return static_cast<int>(m_baseAttack);
		}
		int getDefenseAmnt() const {
			int W1 = static_cast<int>(m_weapons[0]);  
			int W2 = static_cast<int>(m_weapons[1]); 

			int totalAttack = m_baseAttack + (W1 / 2) + (W2 / 2);

			return totalAttack;
		}
		Character* clone() const override {
			return new Barbarian<T, Ability_t, Weapon_t>(*this);
		}
		void attack(Character* enemy) override {
			std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
			m_ability.useAbility(this); 
			int number = getAttackAmnt(); 
			m_ability.transformDamageDealt(number);
			std::cout << "Barbarian deals " << number << " melee damage!" << std::endl;
			enemy->takeDamage(number); 
		}
		void takeDamage(int dmg) override {
			std::cout << this->getName() << " is attacked for " << getAttackAmnt() << "damage." << std::endl; 
			std::cout << "Barbarian has a defense of " << dmg << " Reducing damage received." << std::endl; 
			dmg -= getDefenseAmnt();
			if (dmg < 0) dmg = 0;

			m_ability.transformDamageReceived(dmg);
			CharacterTpl<T>::takeDamage(dmg);

		}



	};

}

#endif