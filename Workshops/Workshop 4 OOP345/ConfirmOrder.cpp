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

#include "ConfirmOrder.h"
#include <iostream>

using namespace std;
namespace seneca {
	ConfirmOrder::~ConfirmOrder()
	{
		delete[] m_toy;
		m_toy = nullptr;
	}

	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& order)
	{
		if (this != &order)
		{
			m_Number = order.m_Number;
			delete[] m_toy;
			m_toy = new const Toy * [m_Number];

			for (size_t i = 0; i < m_Number; i++)
			{
				m_toy[i] = order.m_toy[i];
			}
		}

		return *this;
	}

	ConfirmOrder::ConfirmOrder(const ConfirmOrder& order)
	{
		*this = order;
	}

	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& order) noexcept
	{
		if (this != &order)
		{
			m_Number = order.m_Number;
			delete[] m_toy;
			m_toy = order.m_toy;

			order.m_toy = nullptr;
			order.m_Number = 0;

		}

		return *this;
	}

	ConfirmOrder::ConfirmOrder(ConfirmOrder&& order) noexcept
	{
		*this = move(order);
	}

	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
	{
		bool inArray = false;

		for (size_t i = 0; i < m_Number; i++) {
			if (m_toy[i] == &toy) {
				inArray = true;
			}
		}

		if (!inArray)
		{
			const Toy** temp = nullptr;
			temp = new const Toy * [m_Number + 1];

			for (size_t i = 0; i < m_Number; i++)
			{
				temp[i] = m_toy[i];
			}

			temp[m_Number] = &toy;
			m_Number++;
			delete[] m_toy;
			m_toy = temp;
		}

		return *this;
	}

	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
	{
		bool inArray = false;

		for (size_t i = 0; i < m_Number; i++) {
			if (m_toy[i] == &toy) {
				inArray = true;
			}
		}

		if (inArray)
		{

			for (size_t i = 0; i < m_Number; i++)
			{
				if (m_toy[i] == &toy)
				{
					m_toy[i] = nullptr;
				}
			}

			m_Number--;
		}

		return *this;
	}

	ostream& operator<<(ostream& os, const ConfirmOrder& order)
	{
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		if (order.m_Number == 0) {
			os << "There are no confirmations to send!\n";
		}
		else {
			for (size_t i = 0; i < order.m_Number; i++) {
				if (order.m_toy[i] != nullptr) {
					os << *order.m_toy[i];
				}
			}
		}
		os << "--------------------------\n";

		return os;
	}
}