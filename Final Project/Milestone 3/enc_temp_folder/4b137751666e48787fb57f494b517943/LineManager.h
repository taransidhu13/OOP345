#pragma once
// Name: Tarandeep Kaur
// Seneca Student ID: 139389225
// Seneca email: tarandeep-kaur6@myseneca.ca
// Date of completion: 31 March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef SENECA_LINEMANAGER_H
#define SENECA_LINEMANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include "Workstation.h"


namespace seneca {
    class LineManager {
        std::vector<Workstation*> m_activeLine;
        size_t m_cntCustomerOrder;
        Workstation* m_firstStation = nullptr;

    public:
        LineManager(const std::string& file, const std::vector<Workstation*>& stations);
        void reorderStations();
        bool run(std::ostream& os);
        void display(std::ostream& os) const;
    };
};

#endif