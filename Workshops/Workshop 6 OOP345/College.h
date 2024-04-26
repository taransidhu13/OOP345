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
#ifndef SENECA_COLLEGE_H
#define SENECA_COLLEGE_H

#include <iostream>
#include <vector>
#include <list>
#include "Person.h"


namespace seneca {
    class College {
        // persons vector
        std::vector<Person*> m_persons{};
    public:
        // deleted copy operations
        College() = default;
        College(const College&) = delete;
        College& operator=(const College&) = delete;
        College(College&&) = delete;
        // operator overloads
        College& operator=(College&&) = delete;
        College& operator+=(Person* thePerson);
        void display(std::ostream& os) const;
        virtual ~College();

        // select template function
        template <typename T>
        void select(const T& test, std::list<const Person*>& persons);
    };
    // select certian persons based on test condition and add them to the list
    template<typename T>
    void College::select(const T& test, std::list<const Person*>& persons) {
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
            if (test(*it))
                persons.push_back(*it);
    }
}

#endif 