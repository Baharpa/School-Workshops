#include <iostream>
#include "character.h"



// some important instructions

// Implement a templated class named CharacterTpl,
// derived from the Character (supplied). 

//Template parameters :

//T: the type of the object storing the health.
//Private Members
//m_healthMax : an integer representing the maximum health this character can have
//m_health : an object of type T representing the current health of the character.When this value gets to 0, the character died.

namespace seneca {

    template <typename T> class CharacterTpL : public Character {
        int m_healthMax;
        T m_health;

    public:
        CharacterTpL(const char* name, int healthMax)
            : Character(name), m_healthMax(healthMax) {
            m_health = (int)m_healthMax;
        }

        CharacterTpL(const CharacterTpL& other)
            : Character(other.getName().c_str()), m_healthMax(other.m_healthMax) {
            m_health = (int)other.m_healthMax;
        }

        void takeDamage(int dmg) override {
            m_health -= dmg;
            if (m_health < 0) {
                m_health = 0;
            }

            if (Character::isAlive() == false) {
                std::cout << "    " << Character::getName() << " has been defeated!\n";
            }
            else {
                std::cout << "    " << Character::getName() << " took " << dmg
                    << " damage, " << getHealth() << " health remaining.\n";
            }
        }

        int getHealth() const override { return static_cast<int>(m_health); }

        int getHealthMax() const override { return m_healthMax; }

        void setHealth(int health) override { m_health = health; }

        void setHealthMax(int health) override { m_healthMax = health; }
    };

}