// Name: Tarandeep Kaur
// Seneca Student ID: 139389225
// Seneca email: tarandeep-kaur6@myseneca.ca
// Date of completion: 20 March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

size_t seneca::Station::m_widthField = 0;
int seneca::Station::id_generator = 0;

seneca::Station::Station(std::string& record) {
    Utilities utilities;
    size_t next_pos = 0;
    bool more = true;

    m_stationID = ++id_generator;
    m_itemName = utilities.extractToken(record, next_pos, more);
    m_nextSerialNum = stoi(utilities.extractToken(record, next_pos, more));
    m_numItems = stoi(utilities.extractToken(record, next_pos, more));
    m_widthField = m_widthField > utilities.getFieldWidth() ? m_widthField : utilities.getFieldWidth();
    m_Description = utilities.extractToken(record, next_pos, more);
}

const std::string& seneca::Station::getItemName() const {
    return m_itemName;
}

size_t seneca::Station::getNextSerialNumber() {
    return m_nextSerialNum++;
}

size_t seneca::Station::getQuantity() const {
    return m_numItems;
}

void seneca::Station::updateQuantity() {
    if (m_numItems > 0) {
        m_numItems--;
    }
}

void seneca::Station::display(std::ostream& os, bool full) const {
    os << std::setw(3) << std::setfill('0') << m_stationID << " | ";
    os << std::left << std::setfill(' ') << std::setw(m_widthField + 1) << m_itemName << "| ";
    os << std::right << std::setw(6) << std::setfill('0') << m_nextSerialNum << " | ";

    if (full) {
        os << std::setfill(' ');
        os << std::right;
        os << std::setw(4) << m_numItems << " | " << m_Description;
    }

    os << std::endl;
}