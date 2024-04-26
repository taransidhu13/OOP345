#pragma once
/*                       Workshop 2 Part 2

Name: Tarandeep Kaur
Student ID: 139389225
Student Email: tarandeep-kaur6@myseneca.ca
Professor: Masood Khan Patel
Date: 2 February 2024

Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H
#include <iostream>
#include <string>

namespace seneca {
	class Pair{
		std::string m_key{};
		std::string m_value{};

	public:
		Pair() : m_key{ "" }, m_value{ "" } {};

		const std::string& getKey() const { return m_key; }
		const std::string& getValue() const{ return m_value; }
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value } {};

		static bool havingSameKey(const Pair& left, const Pair& other);
		virtual std::ostream& display(std::ostream& ostr = std::cout) const;
		bool operator==(const Pair& other)const { return m_key == other.getKey();}
	};
	std::ostream& operator<<(std::ostream& ostr, const Pair& left);
}
#endif // SENECA_PAIR_H
