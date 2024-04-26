#pragma once
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

#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

#include <string>

namespace seneca {
    extern size_t g_sysClock;

    class Event {
    private:
        std::string description;
        size_t startTime;

    public:
        Event(); // Default constructor
        void display() const;
        void set(const char* description = nullptr);
    };
}

#endif
