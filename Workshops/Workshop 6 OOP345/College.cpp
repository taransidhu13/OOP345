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
#include <iomanip>
#include "College.h"
#include "Employee.h"
#include "Person.h"


namespace seneca {
    // add Person pointer to the vector
    College& College::operator+=(Person* thePerson) {
        m_persons.push_back(thePerson);
        return *this;
    }

    // Display tests one and two
    void College::display(std::ostream& os) const {
        os << "------------------------------------------------------------------------------------------------------------------------\n";
        os << "|                                        Test #1 Persons in the college!                                               |\n";
        os << "------------------------------------------------------------------------------------------------------------------------\n";
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it) {
            (*it)->display(os);
            std::cout << std::endl;
        }
        os << "------------------------------------------------------------------------------------------------------------------------\n";
        os << "|                                        Test #2 Persons in the college!                                               |\n";
        os << "------------------------------------------------------------------------------------------------------------------------\n";
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
            os << "| " << std::setw(10) << (*it)->status() << "| " << std::setw(10) << (*it)->id() << "| " << std::setw(20) << (*it)->name()
            << " | " << std::setw(3) << (*it)->age() << " |\n";
        os << "------------------------------------------------------------------------------------------------------------------------\n";
    }

    // ensure no memory leaks of m_persons
    College::~College() {
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it) {
            delete* it;
        }
    }
}