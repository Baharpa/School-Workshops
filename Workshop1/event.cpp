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
#include "settings.h"

 seneca::Settings g_settings; 

namespace seneca {

    
    // constructor
    Event::Event(const char* name, const std::chrono::nanoseconds& duration) :
        m_name(name), m_duration(duration) 
    {}


    // print ostream operator
    std::ostream& operator<<(std::ostream& os, const Event& event) {
       
        
        static int counter = 1;
       
        int N = 0;
        if (g_settings.m_time_units == "seconds") {
            N = 2;
        }
        else if (g_settings.m_time_units == "milliseconds") {
            N = 5;
        }
        else if (g_settings.m_time_units == "microseconds") {
            N = 8;
        }
        else {
            N = 11;
        }

        double duration_value = 0.0;
        if (g_settings.m_time_units == "seconds") {
            duration_value = std::chrono::duration_cast<std::chrono::duration<double>>(event.m_duration).count();
           
            // I added this because I wanted it to show 0 if it was less than 1
            if (duration_value < 1.0) {
                duration_value = 0.0;
            }

        }

        else if (g_settings.m_time_units == "microseconds") {
            duration_value = std::chrono::duration_cast<std::chrono::duration<double, std::micro>>(event.m_duration).count();
        }

        else if (g_settings.m_time_units == "milliseconds") {
            duration_value = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(event.m_duration).count();
        }

        else {
            duration_value = std::chrono::duration_cast<std::chrono::nanoseconds>(event.m_duration).count();
        }


        os << std::setw(2) 
           << std::right 
           << counter++ 
           << ": " 
           << std::setw(40) 
           << std::right 
           << event.m_name 
           << " -> "
           << std::setw(N) 
           << std::fixed 
           << std::setprecision(0) 
           << duration_value 
           << " " 
           << g_settings.m_time_units;
        
        return os;
    }


}
