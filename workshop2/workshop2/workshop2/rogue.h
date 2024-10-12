#pragma once
#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H
#include <iostream>
#include <iomanip>
#include <string>

namespace myseneca{
template <typename T, typename FirstAbility_t, typename SecondAbility_t>
class Rogue : public haracterTpL<T>{
	T m_baseDefense; 
	T m_baseAttack; 
	FirstAbility_t m_firstAbility; 
	SecondAbility_t  m_secondAbility; 
	seneca::Danger m_weapon; 


Rogue(const char* name, int healthMax, int baseAttack, int baseDefense) :
{}

};
}

#endif