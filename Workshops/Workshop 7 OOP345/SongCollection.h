#pragma once
/*                       Workshop 7 Part 2

Name: Tarandeep Kaur
Student ID: 139389225
Student Email: tarandeep-kaur6@myseneca.ca
Professor: Masood Khan Patel
Date: 14 March 2024

Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SENECA_SONGCOLLECTION_H
#define SENECA_SONGCOLLECTION_H

#include <string>
#include <vector>
#include <list>

namespace seneca {

	struct Song 
	{
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		size_t m_year;
		size_t m_songLength;
	};

	class SongCollection 
	{
		std::vector<Song> songList;
	public:
		SongCollection(std::string filename);
		void display(std::ostream& out) const;
		void sort(const std::string& field);
		void cleanAlbum();
		bool inCollection(const std::string& artist) const;
		std::list<Song> getSongsForArtist(const std::string& artist) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);


}

#endif