#pragma once
// Name: Tarandeep Kaur
// Seneca Student ID: 139389225
// Seneca email: tarandeep-kaur6@myseneca.ca
// Date of completion: 20 March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SENECA_STATION_H
#define SENECA_STATION_H
#include <string>

namespace seneca {
    class Station {
        int m_stationID;
        std::string m_itemName;
        std::string m_Description;
        unsigned int m_nextSerialNum;
        unsigned int m_numItems;

        static size_t m_widthField;
        static int id_generator;

    public:
        Station(const std::string& record);
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };
};


#endif