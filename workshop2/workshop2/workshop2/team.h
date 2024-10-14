#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H
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

	class Team {
		size_t m_size = 0;
		size_t m_capacity = 0;
		Character** m_team;

		std::string m_name;

		int findMember(const std::string& c) const;

	public:
		Team();
		Team(const char* name);
		Team(const Team& other);
		Team& operator=(const Team& other);
		Team(Team&& other) noexcept;
		Team& operator=(Team&& other) noexcept;
		~Team();

		void addMember(const Character* c);
		void removeMember(const std::string& c);
		Character* operator[](size_t idx) const;
		void showMembers() const;
	};

} 

#endif
