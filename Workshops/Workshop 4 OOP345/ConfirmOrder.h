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
#ifndef SENECA_CONFIRMORDER_H
#define SENECA_CONFIRMORDER_H

#include "Toy.h"

namespace seneca
{
	class ConfirmOrder {
	private:
		const Toy** m_toy{ nullptr };
		size_t m_Number{ 0 };
	public:
		ConfirmOrder() = default;
		~ConfirmOrder();

		ConfirmOrder& operator=(const ConfirmOrder& order);
		ConfirmOrder(const ConfirmOrder& order);
		ConfirmOrder& operator=(ConfirmOrder&& order)noexcept;
		ConfirmOrder(ConfirmOrder&& order)noexcept;

		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& order);
	};
}
#endif // !SENECA_CONFIRMORDER_H
