#ifndef SUMMARY_HPP
#define SUMMARY_HPP

#include <unordered_map>
#include <string>
#include <vector>
#include "playlist.hpp"

class PlaylistSummary {
public:
    struct Summary {
        std::unordered_map<std::string, int> genre_distribution; // If genre added to Song later
        int total_playtime; // in seconds
        int unique_artists;
    };

    Summary generate_summary(const std::vector<Song>& songs) {
        Summary summary;
        summary.total_playtime = 0;
        std::unordered_map<std::string, bool> artist_seen;

        for (const Song& song : songs) {
            summary.total_playtime += song.duration;
            artist_seen[song.artist] = true;
            // If genre exists, count here
            // summary.genre_distribution[song.genre]++;
        }
        summary.unique_artists = static_cast<int>(artist_seen.size());

        return summary;
    }
};

#endif
