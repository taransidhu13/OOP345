#pragma once
/*                       Workshop 5 Part 2

Name: Tarandeep Kaur
Student ID: 139389225
Student Email: tarandeep-kaur6@myseneca.ca
Professor: Masood Khan Patel
Date: 12 February 2024

Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <iostream>
#include <string>
namespace seneca {
	template<typename T>
	class Collection {
		std::string m_name;
		T* m_array;
		size_t m_size;
		void (*m_observer)(const Collection<T>&, const T&);
	public:
		Collection(const std::string& name) : m_name(name), m_array{}, m_size{}, m_observer{}
		{
		}
		Collection(const Collection& I) = delete;
		Collection(Collection&& I) = delete;
		Collection& operator=(const Collection& other) = delete;
		Collection& operator=(Collection&& other) = delete;
		~Collection() {
			delete[] m_array;
		}
		const std::string& name() const {
			return m_name;
		}
		size_t size() const {
			return m_size;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observer = observer;
		}
		Collection<T>& operator+=(const T& item) {
			bool isFound = false;
			if (m_size == 0) {
				m_array = new T[1];
				m_array[m_size] = item;
				m_size++;
			}
			else if (m_size > 0) {
				for (size_t i = 0; i < m_size && !isFound; i++) {
					if (m_array[i].title() == item.title()) isFound = true;
				}
				if (!isFound) {
					T* temp = new T[m_size];
					for (size_t i = 0; i < m_size; i++) {
						temp[i] = m_array[i];
					}
					delete[] m_array;
					m_array = new T[++m_size];
					for (size_t i = 0; i < m_size - 1; i++) {
						m_array[i] = temp[i];
					}
					delete[] temp;
					m_array[m_size - 1] = item;
					if (m_observer != nullptr) m_observer(*this, item);
				}
			}
			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx < 0 || idx >= m_size)
				throw std::out_of_range(std::string("Bad index [") + std::to_string(idx) + std::string("]. Collection has [") + std::to_string(m_size) + std::string("] items."));
			else return m_array[idx];
		}

		T* operator[](const std::string& title) const {
			int isFound = -1;
			for (size_t i = 0; i < m_size && isFound < 0; i++) {
				if (m_array[i].title() == title) isFound = i;
			}
			return isFound > 0 ? &m_array[isFound] : nullptr;
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
		for (size_t i = 0; i < collection.size(); i++) {
			os << collection[i];
		}
		return os;
	}

}
#endif // !SENECA_COLLECTION_H