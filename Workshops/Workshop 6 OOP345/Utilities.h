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

#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include "Utilities.h"
#include "Person.h"
#include "Student.h"
#include "Professor.h"
#include "Employee.h"

namespace seneca {

    Person* buildInstance(std::istream& in);
}

#endif 