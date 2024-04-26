#pragma once
/*                       Workshop 3 Part 2

Name: Tarandeep Kaur
Student ID: 139389225
Student Email: tarandeep-kaur6@myseneca.ca
Professor: Masood Khan Patel
Date: 2 February 2024

Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <iostream>
#include "Pair.h"
#include <string>

namespace seneca {
    template<class T, size_t CAPACITY>
    class Collection{
    protected:
        T array[CAPACITY];
        size_t numElements{ 0 };
        T dummy{};

    public:
        Collection() {}
        virtual ~Collection() {}
        size_t size(){  return numElements;}

        void display(std::ostream& ostr = std::cout)const {
            ostr << "----------------------" << std::endl;
            ostr << "|" << " Collection Content " << "|" << std::endl;
            ostr << "----------------------" << std::endl;
            for (size_t i = 0; i < numElements; i++) {
                ostr << array[i] << std::endl;
            }
            ostr << "----------------------" << std::endl;
        }

        virtual bool add(const T& item) {
            bool result = false;
            if (numElements < CAPACITY) {
                array[numElements] = item;
                numElements++;
                result = true;
            }
            return result;
        }

        T& operator[](int index) {
            if (index >= 0 && (unsigned)index < numElements) {
                return array[index];
            }
            return dummy;
        }
    };

    template<> Collection<Pair, 100>::Collection() {
        Pair a("No Key", "No Value");
        dummy = a;

    }; 
}

#endif // SENECA_COLLECTION_H