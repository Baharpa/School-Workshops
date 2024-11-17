/*
Name : Bahar Parsaeian
Email: bparsaeian@myseneca.ca
Student ID: 118314210
Date: 2024-11-12

Academic Integrity:
I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

*/
#include "collection.h"
#include <stdexcept>
#include <iomanip>

namespace seneca {


    Collection::Collection(const std::string& name) : m_name(name) {}


    Collection::~Collection() {
        for (auto item : m_items) {
            delete item;  
        }
    }


    const std::string& Collection::name() const {
        return m_name;
    }


    size_t Collection::size() const {
        return m_items.size();
    }


    void Collection::setObserver(void (*observer)(const Collection&, const MediaItem&)) {
        m_observer = observer;
    }


    Collection& Collection::operator+=(MediaItem* item) {
        auto it = std::find_if(m_items.begin(), m_items.end(),
            [item](const MediaItem* existingItem) {
                return existingItem->getTitle() == item->getTitle();
            });

        if (it != m_items.end()) {
            delete item;  
        }
        else {
            m_items.push_back(item);  
            if (m_observer) {
                m_observer(*this, *item);  
            }
        }

        return *this;
    }


    MediaItem* Collection::operator[](size_t idx) const {
        if (idx >= m_items.size()) {
            throw std::out_of_range("Bad index [" + std::to_string(idx) +
                "]. Collection has [" + std::to_string(m_items.size()) + "] items."); 
        }
        return m_items[idx];
    }


    MediaItem* Collection::operator[](const std::string& title) const {
        auto it = std::find_if(m_items.begin(), m_items.end(),
            [title](const MediaItem* item) {
                return item->getTitle() == title;
            });

        return (it != m_items.end()) ? *it : nullptr;
    }


    void Collection::removeQuotes() {
        std::for_each(m_items.begin(), m_items.end(),
            [](MediaItem* item) {
                if (item) { 
                    std::string title = item->getTitle();
                    if (!title.empty()) {
                        if (title.front() == '"' && title.back() == '"') {
                            title = title.substr(1, title.length() - 2); 
                        }
                        else if (title.front() == '"') {
                            title = title.substr(1); 
                        }
                        else if (title.back() == '"') {
                            title.pop_back(); 
                        }
                        item->setTitle(title);
                    }

                    std::string summary = item->getSummary();
                    if (!summary.empty()) {
                        if (summary.front() == '"' && summary.back() == '"') {
                            summary = summary.substr(1, summary.length() - 2);
                        }
                        else if (summary.front() == '"') {
                            summary = summary.substr(1); 
                        }
                        else if (summary.back() == '"') {
                            summary.pop_back(); 
                        }
                        item->setSummary(summary); 
                    }
                }
            });
    }


    void Collection::sort(const std::string& field) {
        if (field == "title") {
            std::sort(m_items.begin(), m_items.end(),
                [](const MediaItem* a, const MediaItem* b) {
                    return a->getTitle() < b->getTitle(); 
                });
        }
        else if (field == "year") {
            std::sort(m_items.begin(), m_items.end(),
                [](const MediaItem* a, const MediaItem* b) {
                    return a->getYear() < b->getYear(); 
                });
        }
    }


    std::ostream& operator<<(std::ostream& out, const Collection& collection) {
        for (const auto item : collection.m_items) {
            out << *item;  
        }
        return out;
    }

}
