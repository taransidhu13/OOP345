#pragma once
/*                       Workshop 2 Part 2

Name: Tarandeep Kaur
Student ID: 139389225
Student Email: tarandeep-kaur6@myseneca.ca
Professor: Masood Khan Patel
Date: 2 February 2024

Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SENECA_SET_H
#define SENECA_SET_H

#include <iostream>
#include <cmath>
#include <string>
#include "Pair.h"
#include "Collection.h"


namespace seneca {

    template<class T>
    class Set : public Collection<T, 100> {
        const size_t CAPACITY = 100;
    public:

        Set() { ; }
        bool add(const T& item) {
            for (int i = 0; (unsigned)i < this->numElements; i++){
                if (item == this->array[i]){
                    return false;
                }
            }
            return Collection<T, 100>::add(item);
        }
    };

    template<>
    bool Set<double>::add(const double& item) {
        for (int i = 0; (unsigned)i < this->numElements; i++){
            if (std::fabs(item - this->array[i]) <= 0.01) {
                return false;
            }
        }
        return Collection<double, 100>::add(item);
    };
 }

#endif // SENECA_SET_H
