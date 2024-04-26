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

#include "Pair.h"
using namespace std;

namespace seneca {
    bool Pair::havingSameKey(const Pair& left, const Pair& other) {
        bool result = false;
        if (left.m_key == other.m_key) {
            result = true;
        }
        return result;
    }

    std::ostream& Pair::display(std::ostream& ostr) const {
        ostr.width(20);
        ostr.setf(ios::right);
        ostr << getKey();
        ostr.setf(ios::left);
        ostr << ": " << getValue();
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Pair& left) {
        return left.display(ostr);
    }
}

