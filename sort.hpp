#ifndef SORT_HPP
#define SORT_HPP

#include <vector>
#include <algorithm>
#include "playlist.hpp"  // For Song definition

// Comparison functions
inline bool compare_title_asc(const Song& a, const Song& b) {
    return a.title < b.title;
}

inline bool compare_duration_asc(const Song& a, const Song& b) {
    return a.duration < b.duration;
}

inline bool compare_duration_desc(const Song& a, const Song& b) {
    return a.duration > b.duration;
}

// Enum for sorting criteria
enum class SortCriteria {
    TITLE_ASC,
    DURATION_ASC,
    DURATION_DESC,
    RECENTLY_ADDED  // Assumes songs vector is ordered by add-time (default)
};

// Sort function supporting multiple criteria
inline void sort_songs(std::vector<Song>& songs, SortCriteria criteria = SortCriteria::TITLE_ASC) {
    switch (criteria) {
        case SortCriteria::TITLE_ASC:
            std::sort(songs.begin(), songs.end(), compare_title_asc);
            break;
        case SortCriteria::DURATION_ASC:
            std::sort(songs.begin(), songs.end(), compare_duration_asc);
            break;
        case SortCriteria::DURATION_DESC:
            std::sort(songs.begin(), songs.end(), compare_duration_desc);
            break;
        case SortCriteria::RECENTLY_ADDED:
            // Assume original order is recently added, so no sorting needed
            break;
    }
}

#endif // SORT_HPP
