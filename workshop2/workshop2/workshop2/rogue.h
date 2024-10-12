#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H
//deleted the unnecessary <include> in most of my files to make it more near 
#include "weapons.h"
/*
Name: Bahar
Last name: Parsaeian
Class: OOP345 NEE
Prof: Masood Khan Patel
Workshop : 2

Integrity: I have completed the entire assignment by myself
with no use of other people's sources.


*/
namespace seneca {

    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    class Rogue : public CharacterTpL<T> {

        int m_baseAttack;
        int m_baseDefense;

        FirstAbility_t m_firstAbility;
        SecondAbility_t m_secondAbility;
        Dagger m_weapon;

    public:
        Rogue(const char* name, int healthMax, int baseAttack, int baseDefense)
            : CharacterTpL<T>(name, healthMax), m_baseAttack(baseAttack),
            m_baseDefense(baseDefense) {}

        Rogue(const Rogue& other) : CharacterTpL<T>(other) {
            m_baseAttack = other.m_baseAttack;
            m_baseDefense = other.m_baseDefense;
            m_firstAbility = other.m_firstAbility;
            m_secondAbility = other.m_secondAbility;
            m_weapon = other.m_weapon;
        }

        int getAttackAmnt() const override {
            return m_baseAttack + static_cast<int>(2 * static_cast<double>(m_weapon));
        }



        int getDefenseAmnt() const override { return m_baseDefense; }

        Character* clone() const override { return new Rogue(*this); }

        void attack(Character* enemy) override {
            std::cout << CharacterTpL<T>::getName() << " is attacking "
                << enemy->getName() << ".\n";
            m_firstAbility.useAbility(this);
            m_secondAbility.useAbility(this);

            int dmg = getAttackAmnt();
            m_firstAbility.transformDamageDealt(dmg);
            m_secondAbility.transformDamageDealt(dmg);

            std::cout << "Rogue deals " << dmg << " melee damage!\n";
            enemy->takeDamage(dmg);
        }

        void takeDamage(int dmg) override {
            std::cout << CharacterTpL<T>::getName() << " is attacked for " << dmg
                << " damage.\n";
            dmg -= getDefenseAmnt();
            if (dmg < 0) {
                dmg = 0;
            }

            m_firstAbility.transformDamageReceived(dmg);
            m_secondAbility.transformDamageReceived(dmg);
            CharacterTpL<T>::takeDamage(dmg);
        }
    };

}

#endif