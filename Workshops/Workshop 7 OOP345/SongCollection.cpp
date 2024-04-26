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

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "SongCollection.h"

using namespace std;
namespace seneca {

	void remove_blankSpace(string& str)
	{
		if (str.length() > 0) 
		{
			int start = str.find_first_not_of(' ');
			int end = str.find_last_not_of(' ');
			if (start == -1) str = "";
			else str = str.substr(start, end - start + 1);
		}
	}

	SongCollection::SongCollection(string filename)
	{
		ifstream file(filename);
		Song tmp;
		string line;

		if (!file)
		{
			cerr << "ERROR: Cannot open the file named " << filename << endl;
			exit(-1);
		}
		
		do {
			getline(file, line);
			if (file) {
				tmp.m_title = line.substr(0, 25);
				remove_blankSpace(tmp.m_title);
				tmp.m_artist = line.substr(25, 25);
				remove_blankSpace(tmp.m_artist);
				tmp.m_album = line.substr(50, 25);
				remove_blankSpace(tmp.m_album);
				try {
					tmp.m_year = stoi(line.substr(75, 5));
				}
				catch (invalid_argument&) {
					tmp.m_year = 0;
				}
				tmp.m_songLength = stoi(line.substr(80, 5));
				tmp.m_price = stod(line.substr(85, 5));
				songList.push_back(tmp);
			}

		} while (file);
		file.close();
	}

	void SongCollection::display(ostream& out) const
	{
		size_t listeningTime = 0;
		for_each(songList.begin(), songList.end(), [&out, &listeningTime](const Song& song)
		{
				out << song << endl; listeningTime += song.m_songLength; 
		});

		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "| " << std::right << std::setw(77) << "Total Listening Time: " <<    listeningTime / 3600 << ':' << (listeningTime % 3600) / 60 << ':' <<
		listeningTime % 60  << " |\n";
	    
	}

	void SongCollection::sort(const std::string& field)
	{
		std::sort(songList.begin(), songList.end(), [&field](const Song& songA, const Song& songB)
			{
				if (field == "album") return songA.m_album < songB.m_album;
				else if (field == "length") return songA.m_songLength< songB.m_songLength;
				else return songA.m_title < songB.m_title;
			}
		);
	}

	void SongCollection::cleanAlbum()
	{
		Song tmp;
		replace_if(songList.begin(), songList.end(), [&tmp](const Song& song) {tmp = song; tmp.m_album = ""; return song.m_album == "[None]"; }, tmp);
	}

	bool SongCollection::inCollection(const std::string& artist) const
	{
		return any_of(songList.begin(), songList.end(), [&artist](const Song& song) {return song.m_artist == artist; });
	}

	std::list<Song> SongCollection::getSongsForArtist(const std::string& artist) const
	{
		std::list<Song> songlist(songList.size());
		auto result_iterator = copy_if(songList.begin(), songList.end(), songlist.begin(), [&artist](const Song& song) {return song.m_artist == artist; });
		songlist.resize(std::distance(songlist.begin(), result_iterator));
		return songlist;
	}

	ostream& operator<<(ostream& out, const Song& theSong)
	{
		out << "| " << setw(20) << left << theSong.m_title << " | "
			<< setw(15) << left << theSong.m_artist << " | "
			<< setw(20) << left << theSong.m_album << " | " << 
			setw(6) << right;
		if (theSong.m_year == 0) out << ' ';
		else out << theSong.m_year;
		out << " | " << theSong.m_songLength / 60 << ':' << setfill('0') << setw(2) << theSong.m_songLength % 60
			<< setfill(' ') << " | " << theSong.m_price << " |";
		return out;
	}

}