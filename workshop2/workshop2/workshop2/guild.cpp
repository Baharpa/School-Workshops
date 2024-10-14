
#include "guild.h"
#include <iostream>
#include <string>
/*
Name: Bahar
Last name: Parsaeian
Class: OOP345 NEE
Prof: Masood Khan Patel
Workshop : 2

Integrity: I have completed the entire assignment by myself
with no use of other people's sources.


*/
using namespace std;
namespace seneca {

    Guild::Guild(const Guild& other) {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_members = new Character * [m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            m_members[i] = other.m_members[i];
        }
        m_name = other.m_name;
    }

    Guild& Guild::operator=(const Guild& other) {
        if (this != &other) {
            delete[] m_members;

            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_members = new Character * [m_capacity];
            for (size_t i = 0; i < m_size; ++i) {
                m_members[i] = other.m_members[i];
            }
            m_name = other.m_name;
        }

        return *this;
    }

    Guild::Guild(Guild&& other) noexcept {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_members = other.m_members;
        m_name = other.m_name;

        other.m_size = 0;
        other.m_capacity = 0;
        other.m_members = nullptr;
        other.m_name = "";
    }

    Guild& Guild::operator=(Guild&& other) noexcept {
        if (this != &other) {
            delete[] m_members;

            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_members = other.m_members;
            m_name = other.m_name;

            other.m_size = 0;
            other.m_capacity = 0;
            other.m_members = nullptr;
            other.m_name = "";
        }
        return *this;
    }

    Guild::~Guild() {
        delete[] m_members;
    }

    void Guild::addMember(Character* c) {
        int index = findMember(c->getName());
        if (index != -1) {
            return;
        }

        if (m_size == m_capacity) {
            m_capacity *= 2;
            Character** temp = new Character * [m_capacity];
            for (size_t i = 0; i < m_size; ++i) {
                temp[i] = m_members[i];
            }
            delete[] m_members;
            m_members = temp;
        }

        c->setHealthMax(c->getHealthMax() + 300);
        c->setHealth(c->getHealthMax());

        m_members[m_size++] = c;
    }

    void Guild::removeMember(const std::string& c) {
        int index = findMember(c);
        if (index == -1) {
            return;
        }

        m_members[index]->setHealthMax(m_members[index]->getHealthMax() - 300);
        m_members[index]->setHealth(m_members[index]->getHealthMax());

        for (size_t i = index; i < m_size - 1; ++i) {
            m_members[i] = m_members[i + 1];
        }
        m_size--;
    }

    Character* Guild::operator[](size_t idx) const {
        if (idx >= m_size) {
            return nullptr;
        }

        return m_members[idx];
    }

    void Guild::showMembers() const {
        if (m_capacity == 0) {
            cout << "No guild. " << m_name << "\n";
            return;
        }

        cout << "[Guild] " << m_name << "\n";
        for (size_t i = 0; i < m_size; ++i) {
            cout << "    " << i + 1 << ": " << *m_members[i] << "\n";
        }
    }

} 
