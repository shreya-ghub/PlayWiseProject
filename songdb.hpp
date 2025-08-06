#ifndef SONGDB_HPP
#define SONGDB_HPP

#include <unordered_map>
#include <string>
#include <stdexcept>
#include "playlist.hpp"  // For Song definition

class SongDatabase {
private:
    std::unordered_map<int, Song> id_map;
    std::unordered_map<std::string, Song> title_map;

public:
    // Add or update a song in the database
    void add_song(const Song& song) {
        id_map[song.id] = song;
        title_map[song.title] = song;
    }

    // Get song by ID, throws std::out_of_range if not found
    Song get_song_by_id(int id) const {
        auto it = id_map.find(id);
        if (it == id_map.end()) {
            throw std::out_of_range("Song ID not found");
        }
        return it->second;
    }

    // Get song by title, throws std::out_of_range if not found
    Song get_song_by_title(const std::string& title) const {
        auto it = title_map.find(title);
        if (it == title_map.end()) {
            throw std::out_of_range("Song title not found");
        }
        return it->second;
    }

    // Delete song by ID; also removes from title map
    void delete_song(int id) {
        auto it = id_map.find(id);
        if (it != id_map.end()) {
            title_map.erase(it->second.title);
            id_map.erase(it);
        }
    }

    // Optional: check if song exists by id or title
    bool contains_id(int id) const {
        return id_map.find(id) != id_map.end();
    }

    bool contains_title(const std::string& title) const {
        return title_map.find(title) != title_map.end();
    }
};

#endif 
