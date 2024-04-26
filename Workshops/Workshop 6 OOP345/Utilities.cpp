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
#include "Employee.h"
#include "Student.h"
#include "Professor.h"
#include "Utilities.h"
#include "Person.h"

namespace seneca{
    // Creates instances on the Person hierarchy
    Person* buildInstance(std::istream& in) {
        char ch{};
        Person* p{};
        in >> ch;
        in.ignore();
        if (ch == 'e' || ch == 'E')
            p = new Employee(in);
        else if (ch == 's' || ch == 'S')
            p = new Student(in);
        else if (ch == 'p' || ch == 'P')
            p = new Professor(in);
        return p;
    }
}
