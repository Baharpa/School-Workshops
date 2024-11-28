/*
Name : Bahar Parsaeian
Email: bparsaeian@myseneca.ca
Student ID: 118314210
Date: 2024-11-27

Academic Integrity:
I declare that this submission is the result of my own work
and I only copied the code that my professor provided to complete my workshops and assignments. 
This submitted piece of work has not been shared with any other student or 3rd party content provider.

*/

#ifndef SENECA_STATION_H
#define SENECA_STATION_H
#include <string>

namespace seneca
{
	class Station
	{

		//intsance variables: 
		int m_id{};

		std::string m_name{};

		std::string m_desc{};

		unsigned int m_serial{};

		size_t m_stock{};

		//class variable become static: 
		static size_t m_widthField;
		static size_t id_generator;

	public:
		Station();


		Station(const std::string& record);


		virtual ~Station();


		const std::string& getItemName() const;


		size_t getNextSerialNumber();


		size_t getQuantity() const;


		void updateQuantity();


		void display(std::ostream& os, bool full) const;
	};
}

#endif