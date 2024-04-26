#pragma once
// Name: Tarandeep Kaur
// Seneca Student ID: 139389225
// Seneca email: tarandeep-kaur6@myseneca.ca
// Date of completion: 14 March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include <string>
#include <stdexcept>

namespace seneca {
    class Utilities {
        size_t m_widthField = 1;
        static char m_delimiter;

    public:
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter) {
            m_delimiter = newDelimiter;
        }
        static char getDelimiter() {
            return m_delimiter;
        }
    };
};

#endif