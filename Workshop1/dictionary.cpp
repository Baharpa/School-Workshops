/*
* Workshop 1
* Name: Bahar Parsaeian
* Student ID: 118314210
* subject name: OOP345 NEE
* Date: 2024/09/28
*/

#include <string>
#include <iostream>
#include <fstream>
#include <cstring> 
#include <chrono>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <ostream>
#include <algorithm> 
#include <limits> 
#include "settings.h"
#include "dictionary.h"

namespace seneca {


    // constructor and destructors: 
    Dictionary::Dictionary() : words(nullptr), count(0) {}

    Dictionary::~Dictionary() {
        delete[] words;
    }



    // Opening and reading the files for the command line 
    Dictionary::Dictionary(const char* nameOfFile) {
       
        std::ifstream file(nameOfFile);
        
        if (file) {
           
            std::string line;
           
            while (std::getline(file, line)) {
                count++;
            }
          
            words = new Word[count];
           
            file.clear();
            file.seekg(0, std::ios::beg);
            
            
            int i = 0;
            while (std::getline(file, line) && i < count) {
                
                std::stringstream ss(line);
                
                std::string word, pos, definition;
                
                std::getline(ss, word, ',');
                std::getline(ss, pos, ',');
                
                std::getline(ss, definition);

                words[i].m_word = word;
                words[i].m_definition = definition;
               
                if (pos == "n." || pos == "n. pl.") {
                    words[i].m_pos = PartOfSpeech::Noun;
                }
                else if (pos == "adv.") {
                    words[i].m_pos = PartOfSpeech::Adverb;
                }
                else if (pos == "a.") {
                    words[i].m_pos = PartOfSpeech::Adjective;
                }
                else if (pos == "v." || pos == "v. i." || pos == "v. t." || pos == "v. t. & i.") {
                    words[i].m_pos = PartOfSpeech::Verb;
                }
                else if (pos == "prep.") {
                    words[i].m_pos = PartOfSpeech::Preposition;
                }
                else if (pos == "pron.") {
                    words[i].m_pos = PartOfSpeech::Pronoun;
                }
                else if (pos == "conj.") {
                    words[i].m_pos = PartOfSpeech::Conjunction;
                }
                else if (pos == "interj.") {
                    words[i].m_pos = PartOfSpeech::Interjection;
                }
                else {
                    words[i].m_pos = PartOfSpeech::Unknown;
                }
                i++;
            }
        }
        else {
            words = nullptr;
            count = 0;
        }
    }

    // this is the copy constructor with &
    Dictionary::Dictionary(const Dictionary& other) : words(new Word[other.count]), count(other.count) {
        for (int i = 0; i < count; ++i) {
            words[i] = other.words[i];
        }
    }

    // this is the move constructor with && (always use && for move)
    Dictionary::Dictionary(Dictionary&& other) noexcept : words(other.words), count(other.count) {
        other.words = nullptr;
        other.count = 0;
    }

    // this is the copy assignment operator 
    Dictionary& Dictionary::operator=(const Dictionary& other) {
        if (this != &other) {
            delete[] words;
            count = other.count;
            words = new Word[count];
            for (int i = 0; i < count; ++i) {
                words[i] = other.words[i];
            }
        }
        return *this;
    }
    // this is the move assignment operator 
    Dictionary& Dictionary::operator=(Dictionary&& other) noexcept {
        if (this != &other) {
            delete[] words;
            count = other.count;
            words = other.words;
            other.count = 0;
            other.words = nullptr;
        }
        return *this;
    }

    // searching for the word
    void Dictionary::searchWord(const char* word) {
        bool found = false;

        for (int i = 0; i < count; ++i) {
            if (words[i].m_word == word) {
                if (!found) {
                    std::cout << words[i].m_word << " - ";
                    found = true;
                }
                else {
                    std::cout << std::setw(static_cast<int>(words[i].m_word.length() + 3)) << "- ";
                }

                if (g_settings.m_verbose && words[i].m_pos != PartOfSpeech::Unknown) {
                    std::cout << "(" << words[i].m_pos << ") ";
                }

                std::cout << words[i].m_definition << std::endl;

                if (!g_settings.m_show_all) {
                    break;
                }
            }
        }

        if (!found) {
            std::cout << "Word '" << word << "' was not found in the dictionary." << std::endl;
        }
    }

    // ostream operator for PartOfSpeach
    std::ostream& operator<<(std::ostream& os, PartOfSpeech pos) {
        switch (pos) {
        case PartOfSpeech::Noun: {
            return os << "noun";
        }
        case PartOfSpeech::Pronoun: {
            return os << "pronoun";
        }
        case PartOfSpeech::Adjective: {
            return os << "adjective";
        }
        case PartOfSpeech::Adverb: {
            return os << "adverb";
        }
        case PartOfSpeech::Verb: {
            return os << "verb";
        }
        case PartOfSpeech::Preposition: {
            return os << "preposition";
        }
        case PartOfSpeech::Conjunction: {
            return os << "conjunction";
        }
        case PartOfSpeech::Interjection: {
            return os << "interjection";
        }
        default: {
            return os << "unknown";
        }
        }

    }
}
