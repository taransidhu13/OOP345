/*                       Workshop 8 Part 2

Name: Tarandeep Kaur
Student ID: 139389225
Student Email: tarandeep-kaur6@myseneca.ca
Professor: Masood Khan Patel
Date: 19 March 2024

Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include <memory>
#include "list.h"
#include "element.h"
#include "utilities.h"

using namespace std;

namespace seneca {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		for (size_t i = 0; i < desc.size(); ++i) {
			for (size_t j = 0; j < price.size(); ++j) {
				if (desc[i].code == price[j].code) {
					Product* product = new Product(desc[i].desc, price[j].price);
					try {
						product->validate();
						priceList += product;
					} 
					catch (const std::string& errMsg) {
						delete product; // Clean up if validation fails
						throw errMsg; // Rethrow the exception
					}
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		for (size_t i = 0; i < desc.size(); i++)
		{
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code)
				{
					unique_ptr<Product> p(new Product(desc[i].desc, price[j].price));
					p->validate();
					priceList += std::move(p);
				}
			}
		}
		return priceList;
	}
}