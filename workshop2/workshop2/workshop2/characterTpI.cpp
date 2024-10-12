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


	template<typename T>
	class characterTpl : public Character {
		//integer
		//max health
		H m_healthMax;
		// when this value gets to 0 the patient dies
		T m_health;

	public:
		characterTpl(char* ch1, T max) :
			Character(ch1), m_healthMax(max)
		{}

		void takeDamage(int dmg) override {
			m_health -= dmg;

			// the way to write Master Chief took 46 damage, 954 health remaining.
			if (m_health > 0) {
				std::cout << getName() << " took" << dmg << " damage, " << m_health << " health remaining." << std::endl >
			}
			else {
				std::cout << getName() << "has been defeated!" << std::endl;
			}
		}

		int getHealth() const override {
			return static_cast<int>(m_health);
		}

		int getHealthMax() const override {
			return static_cast<int>(m_healthMax)l;
		}

		void setHealth(int health) override {
			m_health = static_cast<T>(health);
		}

		void setHealthMax(int healthmax) override {
			m_healthMax = static_cast<T>(healthmax);
		}

	};


}