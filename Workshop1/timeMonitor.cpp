/*
* Workshop 1
* Name: Bahar Parsaeian
* Student ID: 118314210
* subject name: OOP345 NEE
* Date: 2024/09/28
*/

#include <chrono>
#include "timeMonitor.h"

namespace seneca {

    // when timing starts
    void TimeMonitor::startEvent(const char* name) {
        
        start = std::chrono::steady_clock::now();
        m_eventName = name;
   
    
    }


    //when timing stops
    Event TimeMonitor::stopEvent() {
       
        auto stop = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
       
        
        return Event(m_eventName.c_str(), duration);
    }

}
