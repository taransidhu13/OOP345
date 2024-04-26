/*                       Workshop 6 Part 2

Name: Tarandeep Kaur
Student ID: 139389225
Student Email: tarandeep-kaur6@myseneca.ca
Professor: Masood Khan Patel
Date: 10 March 2024

Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/
#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H

#include <iostream>
#include <string>
#include "Employee.h"

namespace seneca {
    class Professor : public Employee {
        std::string m_department{};
        // trim 'whitespace' from begining and end of 'str'
        static std::string trim(const std::string& str,
            const std::string& whitespace) {
            const auto strBegin = str.find_first_not_of(whitespace);
            if (strBegin == std::string::npos)
                return ""; // no content
            const auto strEnd = str.find_last_not_of(whitespace);
            const auto strRange = strEnd - strBegin + 1;
            return str.substr(strBegin, strRange);
        }
    public:
        Professor(std::istream& is = std::cin);
        void display(std::ostream& os) const;
        std::string status() const;
        std::string department() const;
    };
}

#endif 