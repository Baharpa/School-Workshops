/*
* Workshop 1
* Name: Bahar Parsaeian
* Student ID: 118314210
* subject name: OOP345 NEE
* Date: 2024/09/28
*/

#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H


#include <string>
#include <iostream>
#include <fstream>
#include <cstring> 
#include "event.h"

namespace seneca {

    class TimeMonitor {
        std::chrono::time_point<std::chrono::steady_clock> start;
        std::string m_eventName;

    public:
        void startEvent(const char* name);
        Event stopEvent();
    };

}

#endif
