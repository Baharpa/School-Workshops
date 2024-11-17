
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include "mediaItem.h"
#include "settings.h"
/*
Name : Bahar Parsaeian
Email: bparsaeian@myseneca.ca
Student ID: 118314210
Date: 2024-11-12

Academic Integrity:
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

*/
#include <string>
#include <iomanip>
#include <sstream>

namespace seneca {

    class Book : public MediaItem {
        std::string m_author;
        std::string m_country;
        double m_price;

        Book(const std::string& title, const std::string& summary, unsigned short year,
            const std::string& author, const std::string& country, double price)
            : MediaItem(title, summary, year), m_author(author), m_country(country), m_price(price) {}

    public:
        void display(std::ostream& out) const override;

        static Book* createItem(const std::string& strBook);
    };

}

#endif