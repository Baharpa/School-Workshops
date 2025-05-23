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


#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include <string>


namespace seneca {

	class Utilities {

		//intsance variable: 
		size_t m_widthField = 1;

		//class variable become static: 
		static char m_delimiter;

	public: 
		void setFieldWidth(size_t newWidth);

		size_t getFieldWidth() const;
		
		static void setDelimiter(char newDelimiter);
		static char getDelimiter(); 
	    std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

	};



}

#endif