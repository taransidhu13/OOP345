/*                       Workshop 2 Part 2

Name: Tarandeep Kaur
Student ID: 139389225
Student Email: tarandeep-kaur6@myseneca.ca
Professor: Masood Khan Patel
Date: 28 January 2024

Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include "StringSet.h"
#include <iostream>
#include <string>
#include <fstream>

namespace seneca {
	StringSet::StringSet() : S{ nullptr }, numOfStr{ 0u } { }

	StringSet::StringSet(const char* fn) {
		std::string fileName = std::string(fn) + ".txt";
		std::ifstream fi(fileName);

		while (!fi.eof()) {
			if (fi.get() == ' ') {
				numOfStr++;
			}
		}
		numOfStr++;

		fi.clear();
		fi.seekg(std::ios::beg);

		S = new std::string[numOfStr];
		for (size_t i = 0; i < numOfStr; i++) {
			std::getline(fi, S[i], ' ');
		}
	}

	StringSet::StringSet(const StringSet& src) {
		if (src.S != nullptr) {
			numOfStr = src.numOfStr;
			S = new std::string[numOfStr];
			for (size_t i = 0; i < numOfStr; i++) {
				S[i] = src.S[i];
			}
		}
		else {
			*this = StringSet();
		}
	}

	StringSet& StringSet::operator=(const StringSet& src) {
		if (this != &src) {
			numOfStr = src.numOfStr;
			delete[] S;
			if (src.S != nullptr) {
				S = new std::string[numOfStr];
				for (size_t i = 0; i < numOfStr; i++) {
					S[i] = src.S[i];
				}
			}
			else {
				*this = StringSet();
			}
		}
		return *this;
	}

	StringSet::StringSet(StringSet&& src) {
		*this = std::move(src);
	}

	StringSet& StringSet::operator=(StringSet&& src) {
		if (this != &src) {
			delete[] S;
			S = src.S;
			numOfStr = src.numOfStr;
			src.S = nullptr;
			src.numOfStr = 0u;
		}
		return *this;
	}

	size_t StringSet::size() {
		return numOfStr;
	}

	std::string StringSet::operator[](size_t index) {
		return index < numOfStr ? S[index] : "";
	}

	StringSet::~StringSet() {
		delete[] S;
		S = nullptr;
	}
}
