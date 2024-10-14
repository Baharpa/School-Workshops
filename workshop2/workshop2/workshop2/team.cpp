#include "team.h"
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

    int Team::findMember(const std::string& c) const {
        for (size_t i = 0; i < m_size; ++i) {
            if (m_team[i]->getName() == c) {
                return i;
            }
        }
        return -1;
    }

    Team::Team()
        : m_size(0), m_capacity(2), m_team(new Character* [m_capacity]),
        m_name("") {}

    Team::Team(const char* name)
        : m_size(0), m_capacity(2), m_team(new Character* [m_capacity]),
        m_name(name) {}

    Team::Team(const Team& other) {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_team = new Character * [m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            m_team[i] = other.m_team[i]->clone();
        }
        m_name = other.m_name;
    }

    Team& Team::operator=(const Team& other) {
        if (this != &other) {
            for (size_t i = 0; i < m_size; ++i) {
                delete m_team[i];
            }
            delete[] m_team;

            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_team = new Character * [m_capacity];
            for (size_t i = 0; i < m_size; ++i) {
                m_team[i] = other.m_team[i]->clone();
            }
            m_name = other.m_name;
        }
        return *this;
    }

    Team::Team(Team&& other) noexcept {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_team = other.m_team;
        m_name = other.m_name;

        other.m_size = 0;
        other.m_capacity = 0;
        other.m_team = nullptr;
        other.m_name = "";
    }

    Team& Team::operator=(Team&& other) noexcept {
        if (this != &other) {
            for (size_t i = 0; i < m_size; ++i) {
                delete m_team[i];
            }
            delete[] m_team;

            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_team = other.m_team;
            m_name = other.m_name;

            other.m_size = 0;
            other.m_capacity = 0;
            other.m_team = nullptr;
            other.m_name = "";
        }
        return *this;
    }

    Team::~Team() {
        for (size_t i = 0; i < m_size; ++i) {
            delete m_team[i];
        }
        delete[] m_team;
    }

    void Team::addMember(const Character* c) {
        if (findMember(c->getName()) != -1) {
            return;
        }

        if (m_size == m_capacity) {
            m_capacity *= 2;
            Character** temp = new Character * [m_capacity];
            for (size_t i = 0; i < m_size; ++i) {
                temp[i] = m_team[i];
            }
            delete[] m_team;
            m_team = temp;
        }

        m_team[m_size++] = c->clone();
    }

    void Team::removeMember(const string& c) {
        int index = findMember(c);
        if (index == -1) {
            return;
        }

        delete m_team[index];

        for (size_t i = index; i < m_size - 1; ++i) {
            m_team[i] = m_team[i + 1];
        }
        m_size--;
    }

    Character* Team::operator[](size_t idx) const {
        if (idx >= m_size) {
            return nullptr;
        }
        return m_team[idx];
    }

    void Team::showMembers() const {
        if (m_capacity == 0) {
            cout << "No team.\n";
            return;
        }

        cout << "[Team] " << m_name << "\n";
        for (size_t i = 0; i < m_size; ++i) {
            cout << "    " << i + 1 << ": " << *m_team[i] << "\n";
        }
    }

}
