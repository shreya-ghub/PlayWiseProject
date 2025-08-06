#ifndef SNAPSHOT_HPP
#define SNAPSHOT_HPP

#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include "playlist.hpp"  // for Song

class Snapshot {
public:
    // Return top 5 longest songs from a playlist
    std::vector<Song> get_top_5_longest(const std::vector<Song>& songs) const {
        auto cmp = [](const Song& a, const Song& b) { return a.duration < b.duration; };
        std::priority_queue<Song, std::vector<Song>, decltype(cmp)> pq(cmp);
        for (const auto& s : songs) {
            pq.push(s);
            if (pq.size() > 5) pq.pop(); // keep only top 5 largest durations
        }

        std::vector<Song> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        std::reverse(result.begin(), result.end()); // longest first
        return result;
    }

    // Count how many songs for each rating value
    std::map<int, int> count_by_rating(const std::vector<std::pair<Song, int>>& ratedSongs) const {
        std::map<int, int> count;
        for (const auto& pair : ratedSongs) {
            count[pair.second]++;
        }
        return count;
    }

    // Export snapshot: return a summary struct or here simplified to return top 5 longest songs
    // In real system, could return a struct with all snapshot info
    std::vector<Song> export_snapshot(const std::vector<Song>& playlist, const std::vector<Song>& recent) const {
        // For demonstration, print top 5 longest and recent songs
        std::vector<Song> top = get_top_5_longest(playlist);

        std::cout << "Top 5 Longest Songs:\n";
        for (const auto& s : top) {
            std::cout << s.title << " - " << s.artist << " (" << s.duration << "s)\n";
        }

        std::cout << "Most Recently Played Songs:\n";
        for (const auto& s : recent) {
            std::cout << s.title << " - " << s.artist << "\n";
        }

        return top;
    }
};

#endif
