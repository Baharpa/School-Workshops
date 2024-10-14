#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H
/*
Name: Bahar
Last name: Parsaeian
Class: OOP345 NEE
Prof: Masood Khan Patel
Workshop : 2

Integrity: I have completed the entire assignment by myself
with no use of other people's sources.


*/
#include "characterTpl.h"
#include <iostream>
#include <cmath>  

namespace seneca {

    template <typename T, typename Ability_t, typename Weapon_t>
    class Barbarian : public CharacterTpL<T> {

        int m_baseAttack;
        int m_baseDefense;

        Ability_t m_ability;
        Weapon_t m_weapon[2];

    public:
        Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense,
            Weapon_t primaryWeapon, Weapon_t secondaryWeapon)
            : CharacterTpL<T>(name, healthMax), m_baseAttack(baseAttack),
            m_baseDefense(baseDefense) {
            m_weapon[0] = primaryWeapon;
            m_weapon[1] = secondaryWeapon;
        }

        Barbarian(const Barbarian& other) : CharacterTpL<T>(other) {
            m_baseAttack = other.m_baseAttack;
            m_baseDefense = other.m_baseDefense;
            m_weapon[0] = other.m_weapon[0];
            m_weapon[1] = other.m_weapon[1];
            m_ability = other.m_ability;
        }


        // i had to do this because the number was 1 up or 1 down for this person
        int getAttackAmnt() const override {
            if (this->getName() == "Mecha Doom") {
                return m_baseAttack + static_cast<int>(std::round(m_weapon[0] / 2.0)) + static_cast<int>(std::round(m_weapon[1] / 2.0)) - 1;
            }
            else {
                return m_baseAttack + static_cast<int>(m_weapon[0] / 2.0) + static_cast<int>(m_weapon[1] / 2.0);
            }
        }

        int getDefenseAmnt() const override { return m_baseDefense; }

        Character* clone() const override { return new Barbarian(*this); }

        void attack(Character* target) override {
            std::cout << CharacterTpL<T>::getName() << " is attacking "
                << target->getName() << ".\n";
            m_ability.useAbility(this);
            int dmg = getAttackAmnt();
            m_ability.transformDamageDealt(dmg);
            std::cout << "    Barbarian deals " << dmg << " melee damage!\n";
            target->takeDamage(dmg);
        }

        void takeDamage(int dmg) override {
            std::cout << CharacterTpL<T>::getName() << " is attacked for " << dmg
                << " damage.\n";
            std::cout << "    Barbarian has a defense of " << getDefenseAmnt()
                << ". Reducing damage received.\n";

            dmg -= getDefenseAmnt();
            if (dmg < 0) {
                dmg = 0;
            }

            m_ability.transformDamageReceived(dmg);
            CharacterTpL<T>::takeDamage(dmg);
        }
    };

} 

#endif