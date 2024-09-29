/*
* Workshop 1
* Name: Bahar Parsaeian
* Student ID: 118314210
* subject name: OOP345 NEE
* Date: 2024/09/28
*/

#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H


#include <string>
#include <iostream>
#include <fstream>
#include <cstring> 

#include "event.h"



namespace seneca {


	class Logger {
		Event* event;
		size_t count;
		size_t max;

	public:
		Logger();
		~Logger();

	
		void addEvent(const Event& event);


		int getCount() const;          
		const Event* getEvents() const; 


		friend std::ostream& operator<<(std::ostream& os, const Logger& logger);

	};

}



#endif