#pragma once
/*                       Workshop 4 Part 2

Name: Tarandeep Kaur
Student ID: 139389225
Student Email: tarandeep-kaur6@myseneca.ca
Professor: Masood Khan Patel
Date: 8 February 2024

Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SENECA_TOY_H
#define SENECA_TOY_H

#include <string>

namespace seneca {
	class Toy
	{
		unsigned int m_OrderId;
		std::string m_Toy_Name;
		int m_No_Item;
		double m_Price;
		double m_HST = 0.13;

	public:
		Toy() = default;
		void update(int numItems);
		Toy(const std::string& toy);
		friend std::ostream& operator<<(std::ostream& os, const Toy& toy);
	};
}
#endif // !SENECA_TOY_H