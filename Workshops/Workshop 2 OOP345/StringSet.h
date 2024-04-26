#pragma once
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

#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H

#include <iostream>

namespace seneca {
	class StringSet {
		std::string* S {nullptr};
		size_t numOfStr{ 0 };
	public:
		StringSet();
		StringSet(const char* fn);
		StringSet(const StringSet& src);
		StringSet& operator=(const StringSet& src);
		StringSet(StringSet&& src);
		StringSet& operator=(StringSet&& src);
		size_t size();
		std::string operator[](size_t index);
		virtual ~StringSet();
	};
}
#endif



