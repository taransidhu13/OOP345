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
#include <iostream>
#include <string>
#include <iomanip>
#include "Employee.h"

namespace seneca {
    // Employee constructor - alsu used by professor constructor
    Employee::Employee(std::istream& is) {
        std::string str{}, str2{};
        getline(is, str, ',');
        m_name = trim(str, " ");
        getline(is, str, ',');
        m_age = trim(str, " ");
        char ch{};
        is.get(ch);
        do {
            str2 += ch;
            is.get(ch);
        } while (ch != '\n' && ch != ',');
        m_id = trim(str2, " ");
        if (m_id[0] != 'E')
            throw(m_name + "++Invalid record!");
    }

    // queries
    std::string Employee::status() const {
        return std::string("Employee");
    }
    std::string Employee::name() const {
        return m_name;
    }
    std::string Employee::id() const {
        return m_id;
    }
    std::string Employee::age() const {
        return m_age;
    }

    // display
    void Employee::display(std::ostream& os) const {
        os << "| " << std::left << std::setw(10) << "Employee" << "| "
            << std::setw(10) << m_id << "| " << std::setw(20) << m_name
            << " | " << std::setw(3) << m_age << " |";
    }
}