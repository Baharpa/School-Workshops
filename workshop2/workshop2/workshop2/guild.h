#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H
/*
Name: Bahar
Last name: Parsaeian
Class: OOP345 NEE
Prof: Masood Khan Patel
Workshop : 2

Integrity: I have completed the entire assignment by myself
with no use of other people's sources.


*/
#include "character.h"
#include <string>

namespace seneca {
    
    class Guild {
        size_t m_size;
        size_t m_capacity;
        Character** m_members;

        std::string m_name;

        int findMember(const std::string& c) const {
            for (size_t i = 0; i < m_size; ++i) {
                if (m_members[i]->getName() == c) {
                    return i;
                }
            }
            return -1;
        }

    public:
        Guild()
            : m_size(0), m_capacity(2), m_members(new Character* [m_capacity]),
            m_name("") {}

        Guild(const char* name)
            : m_size(0), m_capacity(2), m_members(new Character* [m_capacity]),
            m_name(name) {}

        Guild(const Guild& other);
        Guild& operator=(const Guild& other);
        Guild(Guild&& other) noexcept;
        Guild& operator=(Guild&& other) noexcept;
        ~Guild();

        void addMember(Character* c);
        void removeMember(const std::string& c);
        Character* operator[](size_t idx) const;
        void showMembers() const;
    };

} 
#endif
