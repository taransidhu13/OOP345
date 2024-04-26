#pragma once
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

#ifndef SENECA_TIMEDEVENTS_H
#define SENECA_TIMEDEVENTS_H

#include <iostream>
#include <chrono>
#include <string>

namespace seneca {

	const int MAX_EVENTS = 10;

	class TimedEvents {
		int nRecords{ 0 };
		std::chrono::steady_clock::time_point tstart;
		std::chrono::steady_clock::time_point tend;

		struct Event {
			std::string name{};
			std::string units{};
			std::chrono::steady_clock::duration duration{};
		};
		Event events[MAX_EVENTS];


	public:
		void startClock();
		void stopClock();
		void addEvent(const char*);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& Event);
	};

}

#endif // SENECA_TIMEDEVENTS_H
