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

#include <iostream>
#include <sstream>
#include <algorithm>
#include "Utilities.h"
namespace seneca {
	char Utilities::m_delimiter{};

	void Utilities::setFieldWidth(size_t newWidth) {
		
			m_widthField = newWidth;
		
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;

	}

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter =  newDelimiter;
	}


	char Utilities::getDelimiter() {
		return m_delimiter;
	}

	/*

		Info needed for extractTOen function: 



		Nighttable|Desk
		Dresser|Armchair
		Filing Cabinet|Bookcase
		Bookcase
		Bed|Dresser
		Office Chair|Filing Cabinet
		Armchair|Nighttable
		Desk|Office Chair

		The data: 
		const struct { char delim; std::string data; } input[]
		
		{

		{ 'a', "a"},
		{ 'b', "a" },
		{ 'l', "Hello"},
		{ ',', "apple,orange,banana,kiwi,strawberry,yellow watermellon" },
		{ '|', "Gengar|Arcanine|Bulbasaur|Blaziken|C h a r i z a r d|Umbreon|Lucario|Eevee"}
		
		};

		and the function it has to read: 
			for (const auto& item : input)
	{
		seneca::Utilities::setDelimiter(item.delim);
		seneca::Utilities util;
		bool more = true; // if there are more tokens in the input string
		size_t pos = 0u; // position of the next token in the input string
		std::cout << "Data: [" << item.data << "]    Delimiter: [" << item.delim << "]\n";
		while (more)
		{
			try
			{
				auto token = util.extractToken(item.data, pos, more);
				std::cout << "   Token: [" << token << "] [" << util.getFieldWidth() << "]\n";
			}

			catch (...) { std::cout << "   ERROR: No token.\n"; }
		}
	}

	*/



	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		

		// isItFound is a number that tells us at what number of index the 
		// m_delimiter is found
		size_t isItFound = str.find(m_delimiter, next_pos);

		std::string theToken = str.substr(next_pos, isItFound - next_pos); 


			// checking to see if the index is found right at the starting point 
			if (isItFound == next_pos) {
				more = false; 
				throw "ERROR: No token.";
			
			}

			next_pos = isItFound + 1;

			if (isItFound == std::string::npos)
			{
				more = false;
			}
			else
			{
				if (!theToken.empty())	
				more = true;
			}


			theToken.erase(0, theToken.find_first_not_of(' '));
			
			theToken.erase(theToken.find_last_not_of(' ') + 1);


			m_widthField = (m_widthField < theToken.size()) ? theToken.size() : m_widthField;

		
			return theToken; 
	}


}