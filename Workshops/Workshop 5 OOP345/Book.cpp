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

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Book.h"

namespace seneca {

	Book::Book() {};
	void Book::setNewPrice(double price)
	{
		m_price = price;
	}
	const std::string& Book::title() const
	{
		return m_title;
	}
	const std::string& Book::country() const
	{
		return m_country;
	}
	const size_t& Book::year() const
	{
		return m_year;
	}
	double& Book::price()
	{
		return m_price;
	}
	Book::Book(const std::string& strBook)
	{
		std::string temp = strBook;
		std::string author = temp.substr(0, temp.find(','));
		trim(author);

		temp.erase(0, temp.find(',') + 1);

		std::string title = temp.substr(0, temp.find(','));
		trim(title);

		temp.erase(0, temp.find(',') + 1);

		std::string country = temp.substr(0, temp.find(','));
		trim(country);

		temp.erase(0, temp.find(',') + 1);

		double price = std::stod(temp);

		temp.erase(0, temp.find(',') + 1);

		int year = std::stoi(temp);



		temp.erase(0, temp.find(',') + 1);

		std::string desc = temp;
		trim(desc);
		m_author = author;
		m_title = title;
		m_country = country;
		m_year = year;
		m_price = price;
		m_desc = desc;
	}

	void Book::trim(std::string& src)
	{
		int begin = src.find_first_not_of(' ');
		int end = src.find_last_not_of(' ');
		src = src.substr(begin, end - begin + 1);
	}
	std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		os << std::setw(20) << std::right << book.m_author << " | ";
		os << std::setw(22) << std::right << book.m_title << " | ";
		os << std::setw(5) << std::right << book.m_country << " | ";
		os << std::setw(4) << std::right << book.m_year << " | ";
		os << std::setw(6) << std::fixed << std::setprecision(2) << std::right << book.m_price << " | ";
		os << book.m_desc << std::endl;

		return os;
	}
}