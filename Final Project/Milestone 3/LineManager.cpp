// Name: Tarandeep Kaur
// Seneca Student ID: 139389225
// Seneca email: tarandeep-kaur6@myseneca.ca
// Date of completion: 31 March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <fstream>
#include <string>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"


namespace seneca {

	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		std::ifstream is(file);
		std::string temp;
		std::string itemname;
		std::string from;
		std::string to;
		size_t pos = 0;
		bool more = true;
		Utilities util;
		Utilities::setDelimiter('|');
		std::vector<Workstation*> remainfirst;
		while (!is.eof()) {
			getline(is, temp);
			pos = 0;
			more = true;
			itemname = util.extractToken(temp, pos, more);
			Workstation* wp;
			wp = *(find_if(stations.begin(), stations.end(), [&](Workstation* sp) {
				return sp->getItemName() == itemname;
				}));
			m_activeLine.push_back(wp);
			remainfirst.push_back(wp);
		}
		is.seekg(std::ios::beg);
		while (!is.eof()) {
			getline(is, temp);
			pos = 0;
			more = true;
			from = util.extractToken(temp, pos, more);
			if (more) {
				Workstation* fromWp, * toWp;
				to = util.extractToken(temp, pos, more);
				toWp = *(find_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* wp) {
					return wp->getItemName() == to;
					}));
				remove(remainfirst.begin(), remainfirst.end(), toWp);
				fromWp = *(find_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* wp) {
					return wp->getItemName() == from;
					}
				));
				fromWp->setNextStation(toWp);
			}
		}
		m_cntCustomerOrder = g_pending.size();
		m_firstStation = remainfirst.front();
	}
	void LineManager::reorderStations()
	{
		std::vector<Workstation*> tempLine;
		Workstation* tp;
		tempLine.push_back(m_firstStation);
		while ((tp = tempLine.back()->getNextStation())) {
			tempLine.push_back(tp);
		}
		m_activeLine.clear();
		m_activeLine = tempLine;
	}
	bool LineManager::run(std::ostream& os)
	{
		static size_t count{}; 
		count++;
		os << "Line Manager Iteration: " << count << std::endl;
		if (!g_pending.empty()) {
			*m_firstStation += std::move(g_pending.front());
			g_pending.pop_front();
		}

		for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
			ws->fill(os);
			});
		for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
			ws->attemptToMoveOrder();
			});

		return g_completed.size() + g_incomplete.size() == m_cntCustomerOrder;
	}

	void LineManager::display(std::ostream& os) const
	{
		for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
			ws->display(os);
			});
	}
}