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

#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H

namespace seneca {
	class Movie 
	{
		std::string m_title{};
		size_t m_year{};
		std::string m_description{};
		void trim(std::string& src);

	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}

		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);

	};

}
#endif // !SENECA_MOVIE_H