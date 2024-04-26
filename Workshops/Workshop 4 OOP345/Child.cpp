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

#include "Child.h"
using namespace std;
namespace seneca {
	Child::Child()
	{
		delete[] toy;
		toy = nullptr;

		m_Number = 0;
		m_Child_Name = "";
		m_Age = 0;
	}

	Child& Child::operator=(const Child& child)
	{
		if (this != &child)
		{
			m_Number = child.m_Number;
			m_Child_Name = child.m_Child_Name;
			m_Age = child.m_Age;

			delete[] toy;
			toy = new Toy[m_Number];

			for (size_t i = 0; i < m_Number; i++)
			{
				toy[i] = child.toy[i];
			}
		}

		return *this;
	}

	Child::Child(const Child& child)
	{
		*this = child;
	}

	Child::Child(Child&& child) noexcept
	{
		*this = move(child);
	}
	Child& Child::operator=(Child&& child) noexcept
	{
		if (this != &child)
		{
			m_Number = child.m_Number;
			m_Child_Name = child.m_Child_Name;
			m_Age = child.m_Age;

			delete[] toy;
			toy = child.toy;

			child.toy = nullptr;
			child.m_Number = 0;
			child.m_Child_Name = "";
			child.m_Age = 0;

		}

		return *this;
	}

	Child::~Child()
	{
		delete[] toy;
		toy = nullptr;
	}

	Child::Child(std::string name, int age, const Toy* toys[], size_t count)
	{
		toy = new Toy[count];
		m_Child_Name = name;
		m_Age = age;
		m_Number = count;

		for (size_t i = 0; i < count; i++)
		{
			toy[i] = *toys[i];
		}
	}
	size_t Child::size() const
	{
		return m_Number;
	}

	ostream& operator<<(ostream& os, const Child& child)
	{
		static size_t CALL_CNT;
		++CALL_CNT;
		os << "--------------------------\n"
			<< "Child " << CALL_CNT << ": " << child.m_Child_Name << " " << child.m_Age << " years old:" << endl;
		os << "--------------------------\n";

		if (child.m_Number == 0) {
			os << "This child has no toys!" << endl;
		}
		else {
			for (size_t i = 0; i < child.m_Number; i++) {
				os << child.toy[i];
			}
		}
		os << "--------------------------\n";
		return os;
	}
}
