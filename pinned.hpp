#ifndef PINNED_HPP
#define PINNED_HPP

#include <unordered_map>

class PinnedSongs {
private:
    // Map song ID to pinned index position in playlist
    std::unordered_map<int, int> pinned_positions;

public:
    void pin_song(int song_id, int index) {
        pinned_positions[song_id] = index;
    }

    void unpin_song(int song_id) {
        pinned_positions.erase(song_id);
    }

    bool is_pinned(int song_id) const {
        return pinned_positions.find(song_id) != pinned_positions.end();
    }

    int get_pinned_index(int song_id) const {
        auto it = pinned_positions.find(song_id);
        if (it != pinned_positions.end()) return it->second;
        return -1; // Not pinned
    }

    const std::unordered_map<int, int>& get_all_pinned() const {
        return pinned_positions;
    }
};

#endif
