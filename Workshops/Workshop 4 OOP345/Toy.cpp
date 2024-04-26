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
#include <iomanip>
#include "Toy.h"

using namespace std;
namespace seneca
{
	void seneca::Toy::update(int numItems)
	{
		m_No_Item = numItems;
	}

	Toy::Toy(const string& toy)
	{
		string str = toy;
		string orderID, name, numOfItems, price;

		orderID = str.substr(0, str.find(":"));
		str.erase(0, str.find(":") + 1);

		name = str.substr(0, str.find(":"));
		str.erase(0, str.find(":") + 1);

		numOfItems = str.substr(0, str.find(":"));
		str.erase(0, str.find(":") + 1);

		price = str.substr(0, str.find(":"));
		str.erase(0, str.find(":") + 1);

		name.erase(0, name.find_first_not_of(' '));
		name.erase(name.find_last_not_of(' ') + 1);

		m_OrderId = stoi(orderID);
		m_Toy_Name = name;
		m_No_Item = stoi(numOfItems);
		m_Price = stod(price);
	}

	ostream& operator<<(ostream& os, const Toy& toy)
	{
		double subTotal = toy.m_Price * double(toy.m_No_Item);
		double tax = subTotal * toy.m_HST;
		double total = subTotal + tax;

		os << "Toy";
		os << setw(8) << toy.m_OrderId << ":";
		os << right << setw(18) << toy.m_Toy_Name;
		os << setw(3) << toy.m_No_Item;

		os << " items" << setw(8) << fixed << setprecision(2) << toy.m_Price;
		os << "/item  subtotal:" << setw(7) << fixed << setprecision(2) << subTotal;
		os << " tax:" << setw(6) << fixed << setprecision(2) << tax;
		os << " total:" << setw(7) << fixed << setprecision(2) << total << endl;

		return os;
	}
}
