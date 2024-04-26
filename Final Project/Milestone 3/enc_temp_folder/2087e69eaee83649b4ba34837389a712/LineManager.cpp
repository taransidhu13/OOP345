// Name: Tarandeep Kaur
// Seneca Student ID: 139389225
// Seneca email: tarandeep-kaur6@myseneca.ca
// Date of completion: 31 March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <fstream>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"


namespace seneca {

	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
		Utilities utility;

		std::ifstream input(file);
		if (!input.is_open()) {
			throw std::string("Unable to open file.");
		}


		std::string data;
		while (!input.eof())
		{
			getline(input, data);
			size_t pos = 0;
			bool more = true;
			std::string curStation, nextStation;
			curStation = utility.extractToken(data, pos, more);

			if (more) {
				nextStation = utility.extractToken(data, pos, more);
			}

			Workstation* curWorkstation = nullptr;
			Workstation* nextWorkstation = nullptr;
			for_each(stations.begin(), stations.end(), [&curWorkstation, &nextWorkstation, curStation, nextStation](Workstation* ws) {
				if (ws->getItemName() == curStation) {
					curWorkstation = ws;
				}
				else if (ws->getItemName() == nextStation) {
					nextWorkstation = ws;
				}
				});

			if (m_activeLine.size() == 0) {
				m_firstStation = curWorkstation;
			}

			curWorkstation->setNextStation(nextWorkstation);
			m_activeLine.push_back(curWorkstation);
		}

		input.close();

	}

	void LineManager::reorderStations() {
		std::vector<Workstation*> newStations;
		Workstation* lastStation = nullptr;
		unsigned int count = 0;
		while (count < m_activeLine.size()) {
			for (unsigned int i = 0; i < m_activeLine.size(); i++) {
				if (m_activeLine[i]->getNextStation() == lastStation) {
					newStations.push_back(m_activeLine[i]);
					lastStation = m_activeLine[i];
					count++;
					break;
				}
			}
		}
		reverse(newStations.begin(), newStations.end());
		m_firstStation = newStations[0];
		m_activeLine = newStations;
	}

	bool LineManager::run(std::ostream& os) {
		static int iterationCount = 0; // Keep track of the current iteration number
		iterationCount++;

		os << "Line Manager Iteration: " << iterationCount << std::endl; // Insert iteration number into stream

		if (!g_pending.empty()) {
			(*m_firstStation) += std::move(g_pending.front()); // Move the order at the front of g_pending to m_firstStation
			g_pending.pop_front(); // Remove it from the queue
		}

		// Execute fill operation for each station
		for (auto station : m_activeLine) {
			station->fill(os);
		}

		// Attempt to move an order down the line for each station
		for (auto station : m_activeLine) {
			station->attemptToMoveOrder();
		}

		// Check if all customer orders have been filled or cannot be filled
		bool allOrdersProcessed = true;
		for (auto station : m_activeLine) {
			if (!station->empty()) {
				allOrdersProcessed = false;
				break;
			}
		}

		return allOrdersProcessed;
	}


	void LineManager::display(std::ostream& os) const {
		for (unsigned int i = 0; i < m_activeLine.size(); i++) {
			m_activeLine[i]->display(os);
		}
	}

}