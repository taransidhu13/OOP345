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
#include "Professor.h"
#include "Employee.h"

namespace seneca {
    // build a professor using the employee constructor
    Professor::Professor(std::istream& is) : Employee(is) {
        std::string dept{};
        getline(is, dept, '\n');
        m_department = trim(dept, " ");
    }
    // display professor using the display from Employee and adding the department
    void Professor::display(std::ostream& os) const {
        Employee::display(os);
        os << m_department << "| Professor";
    }

    // queries
    std::string Professor::status() const {
        return "Professor";
    }
    std::string Professor::department() const {
        return m_department;
    }
}