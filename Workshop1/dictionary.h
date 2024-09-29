/*
* Workshop 1 
* Name: Bahar Parsaeian
* Student ID: 118314210
* subject name: OOP345 NEE
* Date: 2024/09/28
*/
#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H


#include <string>
#include <iostream>
#include <fstream>
#include <cstring> 


namespace seneca {

	enum class PartOfSpeech
	{
		Unknown,
		Noun,
		Pronoun,
		Adjective,
		Adverb,
		Verb,
		Preposition,
		Conjunction,
		Interjection,
	};
	struct Word
	{
		std::string m_word{};
		std::string m_definition{};
		PartOfSpeech m_pos = PartOfSpeech::Unknown;
	};


	class Dictionary {
		Word* words; 
		int count = 0;

	public: 

		Dictionary(); 
		~Dictionary();

		Dictionary(const char* nameOfFile); 

		Dictionary(const Dictionary& other);
		Dictionary(Dictionary&& other) noexcept;


		Dictionary& operator=(const Dictionary& other);
		Dictionary& operator=(Dictionary&& other) noexcept;


		void searchWord(const char* word);


	};

	std::ostream& operator<<(std::ostream& os, PartOfSpeech pos);
}

#endif