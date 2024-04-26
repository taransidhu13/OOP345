
/*                       Workshop 2 Part 2

Name: Tarandeep Kaur
Student ID: 139389225
Student Email: tarandeep-kaur6@myseneca.ca
Professor: Masood Khan Patel
Date: 28 January 2024

Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include "TimedEvents.h"
#include <iomanip>

namespace seneca {
	void TimedEvents::startClock()
	{
		tstart = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		tend = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* eventName) {
		auto ms = std::chrono::duration_cast<std::chrono::nanoseconds>(tend - tstart);
		if (nRecords < MAX_EVENTS)
		{
			events[nRecords].name = eventName;
			events[nRecords].units = "nanoseconds";
			events[nRecords].duration = ms;
			nRecords++;
		}
	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents& Event)
	{
		os << "--------------------------\n";
		os << "Execution Times:\n";
		os << "--------------------------\n";
		for (int i = 0; i < Event.nRecords; i++)

			os << std::setw(21) << std::left
			<< Event.events[i].name << ' ' << std::setw(13) << std::right
			<< Event.events[i].duration.count() << ' '
			<< Event.events[i].units << '\n';
		os << "--------------------------\n";
		return os;

	}
}
