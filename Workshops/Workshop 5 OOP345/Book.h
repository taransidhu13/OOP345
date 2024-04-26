#pragma once
/*                       Workshop 5 Part 2

Name: Tarandeep Kaur
Student ID: 139389225
Student Email: tarandeep-kaur6@myseneca.ca
Professor: Masood Khan Patel
Date: 12 February 2024

Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iostream>

namespace seneca 
{
	class Book 
	{
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		size_t m_year{};
		double m_price{};
		std::string m_desc{};
		void trim(std::string& src);

	public:
		Book();
		void setNewPrice(double price);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_desc);
		}
		friend std::ostream& operator<<(std::ostream& os, const Book& book);
	};
}
#endif // !SENECA_BOOK_H