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
#ifndef SENECA_CHILD_H
#define SENECA_CHILD_H

#include <iostream>
#include <string>
#include "Toy.h"

namespace seneca {
	class Child
	{
	private:
		Toy* toy{};
		size_t m_Number;
		std::string m_Child_Name;
		int m_Age;
	public:
		Child();
		Child& operator=(const Child& child);
		Child(const Child& child);
		Child(Child&& child) noexcept;
		Child& operator=(Child&& child) noexcept;
		~Child();

		Child(std::string name, int age, const Toy* toys[], size_t count);
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Child& child);
	};
}
#endif // !SENECA_CHILD_H