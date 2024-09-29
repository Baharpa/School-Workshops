/*
* Workshop 1
* Name: Bahar Parsaeian
* Student ID: 118314210
* subject name: OOP345 NEE
* Date: 2024/09/28
*/

#include <string>
#include <iostream>
#include <fstream>
#include <cstring> 
#include <chrono>
#include <iomanip>
#include <chrono>


#include "event.h"
#include "logger.h"



namespace seneca {


	//constructor and destructor: 
	Logger::Logger() : event(nullptr), count(0), max(0) {}

	Logger::~Logger() {
		delete[] event;
	}

	int Logger::getCount() const {
		return count;
	}
	//////////////////////////////////
	
	// return events
	const Event* Logger::getEvents() const {
		return event;
	}

	//ostream overloaded function for logger
	std::ostream& operator<<(std::ostream& os, const Logger& logger) {
		for (size_t i = 0; i < static_cast<size_t>(logger.getCount()); ++i) {
			os << logger.getEvents()[i] << std::endl;
		}
		return os;
	}

	//adding events
	void Logger::addEvent(const Event& newEvent) {
		if (count == max) {
		
			max = (max == 0) ? 1 : max * 2;
			
			Event* temp = new Event[max];
		
		    for (size_t i = 0; i < static_cast<size_t>(count); ++i) {

				temp[i] = event[i];
			}
		
			delete[] event;
		
			event = temp;
		}
		event[count++] = newEvent;
	}

}