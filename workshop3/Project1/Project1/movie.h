/*
Name : Bahar Parsaeian
Email: bparsaeian@myseneca.ca
Student ID: 118314210
Date: 2024-11-12

Academic Integrity:
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

*/
#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H

#include "mediaItem.h"
#include "settings.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

namespace seneca {

    class Movie : public MediaItem {

        Movie(const std::string& title, const std::string& summary, unsigned short year)
            : MediaItem(title, summary, year) {}

    public:
        void display(std::ostream& out) const override;

        static Movie* createItem(const std::string& strMovie);
    };

}

#endif