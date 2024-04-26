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
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H
#define constexpr unsigned M_WORDS{ 6 };

namespace seneca {
	class SpellChecker {
		std::string m_badWords[6]{};
		std::string m_goodWords[6]{};
		size_t m_replaceCounter[6]{};
		std::size_t replace_all(std::string& inout, std::string what, std::string with);
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif // !SENECA_SPELLCHECKER_H