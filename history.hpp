#ifndef HISTORY_HPP
#define HISTORY_HPP

#include "playlist.hpp"  // For Song definition
#include <stack>
#include <stdexcept>

class PlaybackHistory {
private:
    std::stack<Song> history;

public:
    // Record a played song
    void song_played(const Song& song) {
        history.push(song);
    }

    // Undo last played song and return it
    // Throws runtime_error if history is empty
    Song undo_last_play() {
        if (history.empty()) {
            throw std::runtime_error("Playback history is empty, cannot undo.");
        }
        Song last = history.top();
        history.pop();
        return last;
    }

    // Check if history is empty
    bool is_empty() const {
        return history.empty();
    }

    // Clear all history
    void clear_history() {
        while (!history.empty()) {
            history.pop();
        }
    }

    // Get current history size
    size_t size() const {
        return history.size();
    }
};

#endif
