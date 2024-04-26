/*                       Workshop 1 Part 2

Name: Tarandeep Kaur
Student ID: 139389225
Student Email: tarandeep-kaur6@myseneca.ca
Professor: Masood Khan Patel
Date: 21 January 2024

Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"

namespace seneca {
    size_t g_sysClock = 0;

    // Default constructor
    Event::Event() : startTime(0) {
    }

    // Display function
    void Event::display() const {
        static size_t counter = 0;
        std::cout << std::setfill(' ') << std::setw(2) << ++counter << ". ";

        if (description.empty()) {
            std::cout << "| No Event |";
        }
        else {
            size_t hours = startTime / 3600;
            size_t minutes = (startTime % 3600) / 60;
            size_t seconds = startTime % 60;

            std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                << std::setw(2) << minutes << ":"
                << std::setw(2) << seconds << " => " << description;
        }

        std::cout << '\n';
        
    }

    // Set function
    void Event::set(const char* description) {
        if (description != nullptr && std::strlen(description) > 0) {
            this->description = description;
            // Assuming a new event starts when set is called
            startTime = g_sysClock;
        }
        else {
            // Reset current instance to empty state
            this->description.clear();
            startTime = 0;
        }
    }
}
