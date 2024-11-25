#include <iostream>
#include <string>
#include <cstring>
#include "Utilities.h"
namespace seneca {
	char Utilities::m_delimiter{};

	void Utilities::setFieldWidth(size_t newWidth) {
		if (newWidth) {
			m_widthField = newWidth;
		}
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
				more = true; 
				throw "ERROR: No token.";
			
			}

			next_pos = (std::string::npos) ? std::string::npos : isItFound + 1; 

			// std::string::npos would be the same value of isItFound if not found
			more = (isItFound != std::string::npos) && !theToken.empty();

			theToken.erase(0, theToken.find_first_not_of(' '));
			
			theToken.erase(theToken.find_last_not_of(' ') + 1);
		
			return theToken; 
	}


}