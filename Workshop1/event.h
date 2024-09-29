/*
* Workshop 1
* Name: Bahar Parsaeian
* Student ID: 118314210
* subject name: OOP345 NEE
* Date: 2024/09/28
*/

#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H


#include <string>
#include <iostream>
#include <fstream>
#include <cstring> 
#include <chrono>

namespace seneca{
class Event {
	static int counter; 
	std::string m_name{};
	std::chrono::nanoseconds m_duration{};

public: 

	Event() = default;
	Event(const char* name, const std::chrono::nanoseconds& duration);
	
	friend std::ostream& operator<<(std::ostream& os, const Event& event);


};


}
#endif