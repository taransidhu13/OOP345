/*                       Workshop 9 Part 2

Name: Tarandeep Kaur
Student ID: 139389225
Student Email: tarandeep-kaur6@myseneca.ca
Professor: Masood Khan Patel
Date: 25 March 2024

Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <future>
#include <functional>
#include "TreasureMap.h"

namespace seneca {

    size_t digForTreasure(const std::string& str, char mark) {
        size_t cnt = 0;
        for (auto& x : str) {
            if (x == mark) {
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename) {
        std::fstream fin(filename);
        if (fin) {
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while (fin) {
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap() {
        delete[] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const {
        if (map) {
            for (size_t i = 0; i < rows; ++i) {
                os << map[i] << std::endl;
            }
        }
        else
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename) {
        // Binary write
        if (map) {

            std::ofstream ofs(filename, std::ios::binary);
            if (!ofs) {
                throw(std::string("Invalid file name!"));
            }
            ofs.write((const char*)&rows, sizeof(rows));
            ofs.write((const char*)&colSize, sizeof(colSize));

            for (unsigned i{ 0 }; i < rows; i++) {
                ofs.write(map[i].c_str(), colSize);
            }

            
        }
        else {
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename) {
        // Binary read
        std::ifstream ifs(filename, std::ios::binary);

        if (!ifs) {
            throw(std::string("Invalid file name!"));
        }

        ifs.read((char*)&rows, sizeof(rows));
        ifs.read((char*)&colSize, sizeof(colSize));
        map = new std::string[rows];

        char ch{};

        for (unsigned i{ 0 }; i < rows; i++) {
            ch = -1;

            for (unsigned j{ 0 }; j < colSize; j++) {
                ifs.read((char*)&ch, sizeof(ch));
                map[i] += ch;
            };
        }       

        // END TODO
    }

    void TreasureMap::clear() {
        delete[] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark) {
        size_t count = 0;

        // TODO: For part 2, comment this "for" loop and write the multihreaded version.
        //for (size_t i = 0; i < rows; ++i) {
        //    count += digForTreasure(map[i], mark);
        //}

        size_t remainder = rows % 4;
        size_t divisible = rows - remainder;
        std::string partition[4]{};

        for (size_t i = 0; i < (divisible / 4); i++) {
            partition[0] += map[i];
        }
        for (size_t i = divisible / 4; i < (divisible / 2); i++) {
            partition[1] += map[i];
        }
        for (size_t i = (divisible / 2); i < (divisible / 4 * 3); i++) {
            partition[2] += map[i];
        }
        for (size_t i = (divisible / 4 * 3); i < divisible + (remainder); i++) {
            partition[3] += map[i];
        }

        std::packaged_task<size_t()> t1(std::bind(digForTreasure, partition[0], mark));
        std::packaged_task<size_t()> t2(std::bind(digForTreasure, partition[1], mark));
        std::packaged_task<size_t()> t3(std::bind(digForTreasure, partition[2], mark));
        std::packaged_task<size_t()> t4(std::bind(digForTreasure, partition[3], mark));

        std::future<size_t> res1 = t1.get_future();
        std::future<size_t> res2 = t2.get_future();
        std::future<size_t> res3 = t3.get_future();
        std::future<size_t> res4 = t4.get_future();

        t1();
        t2();
        t3();
        t4();

        count = res1.get() + res2.get() + res3.get() + res4.get();

        return count;
    }
}