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
#include <sstream>
#include <iomanip>
#include <string>
#include "Movie.h"

namespace seneca {

	void Movie::trim(std::string& src)
	{
		int begin = src.find_first_not_of(' ');
		int end = src.find_last_not_of(' ');
		src = src.substr(begin, end - begin + 1);
	}

	Movie::Movie() {}

	const std::string& Movie::title() const
	{
		return m_title;
	}

	Movie::Movie(const std::string& strMovie)
	{
		std::string temp = strMovie;

		std::string title = temp.substr(0, temp.find(','));
		trim(title);

		temp.erase(0, temp.find(',') + 1);
		int year = std::stoi(temp);

		temp.erase(0, temp.find(',') + 1);
		std::string description = temp;
		trim(description);

		m_title = title;
		m_year = year;
		m_description = description;
	}


	std::ostream& operator<<(std::ostream& os, const Movie& movie)
	{
		os << std::setw(40) << std::right << movie.m_title << " | ";
		os << std::setw(4) << std::right << movie.m_year << " | ";
		os << movie.m_description << std::endl;

		return os;
	}

}