// Name: Tarandeep Kaur
// Seneca Student ID: 139389225
// Seneca email: tarandeep-kaur6@myseneca.ca
// Date of completion: 14 March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include "Utilities.h"

char seneca::Utilities::m_delimiter = '|';

void seneca::Utilities::setFieldWidth(size_t newWidth) {
    m_widthField = newWidth;
}

size_t seneca::Utilities::getFieldWidth() const {
    return m_widthField;
}

std::string seneca::Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

    if (str[next_pos] == m_delimiter || next_pos >= str.length()) {
        more = false;
        throw std::invalid_argument("Invalid next_pos arguement");
    }

    std::string token = "";
    std::string whitespace = "";

    while (next_pos < (size_t)str.length()) {
        if (str[next_pos] != ' ') {
            if (str[next_pos] == '\n' || str[next_pos] == '\r') {
                break;
            }
            else if (str[next_pos] == m_delimiter) {
                if (m_widthField < token.length()) {
                    m_widthField = token.length();
                }
                more = true;
                next_pos++;
                return token;
            }
            else {
                if (token.length() > 0) {
                    token += whitespace + str[next_pos];
                    whitespace = "";
                }
                else {
                    token += str[next_pos];
                    whitespace = "";
                }

                if (next_pos == (size_t)str.length() - 1) {
                    if (m_widthField < token.length()) {
                        m_widthField = token.length();
                    }
                    more = false;
                    next_pos++;
                    return token;
                }
            }
        }
        else {
            whitespace += ' ';
        }
        next_pos++;
    }

    more = false;
    return token;
}