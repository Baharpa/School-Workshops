/*
* Workshop 1
* Name: Bahar Parsaeian
* Student ID: 118314210
* subject name: OOP345 NEE
* Date: 2024/09/28
*/

#ifndef SENECA_SETTINGS_H   
#define SENECA_SETTINGS_H   


#include <string>
#include <iostream>


namespace seneca {


	struct Settings {
		bool m_show_all = false;
		bool m_verbose = false; 
		std::string m_time_units = "nanoseconds";
	};

	extern Settings g_settings; 




}
#endif 