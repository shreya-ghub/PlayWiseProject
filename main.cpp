#include "playlist.hpp"
#include "history.hpp"
#include "songdb.hpp"
#include "sort.hpp"
#include "snapshot.hpp"
#include "ratingtree.hpp"
#include "pinned.hpp"
#include "summary.hpp"
#include <iostream>
#include <vector>

int main() {
    Playlist playlist;
    SongDatabase db;
    PlaybackHistory history;
    Snapshot snapshot;
    RatingTree ratingTree;
    PinnedSongs pinnedSongs;
    PlaylistSummary summaryGen;

    // Create songs
    Song s1(1, "Believer", "Imagine Dragons", 204);
    Song s2(2, "Blinding Lights", "The Weeknd", 190);
    Song s3(3, "Counting Stars", "OneRepublic", 210);

    // Add songs to playlist and database
    playlist.add_song(s1);
    playlist.add_song(s2);
    playlist.add_song(s3);

    db.add_song(s1);
    db.add_song(s2);
    db.add_song(s3);

    // Insert ratings
    ratingTree.insert_song(s1.id, 4);
    ratingTree.insert_song(s2.id, 5);
    ratingTree.insert_song(s3.id, 3);

    // Pin a song
    pinnedSongs.pin_song(s2.id, 0); // Pin "Blinding Lights" at position 0

    std::cout << "Initial Playlist:\n";
    playlist.print_playlist();

    // Move song respecting pinned positions (you need to implement respecting pinned in Playlist move_song)
    std::cout << "\nAttempting to move 'Counting Stars' to position 0 (should skip pinned):\n";
    playlist.move_song(2, 0);  // Should not override pinned position if integrated

    playlist.print_playlist();

    std::cout << "\nReversing Playlist:\n";
    playlist.reverse_playlist();
    playlist.print_playlist();

    std::cout << "\nUndoing last play (simulate play and undo):\n";
    history.song_played(s1);
    Song undone = history.undo_last_play();
    playlist.add_song(undone);
    playlist.print_playlist();

    // Collect songs for sorting demonstration
    std::vector<Song> songs = { s1, s2, s3 };

    std::cout << "\nSorting songs by title:\n";
    sort_songs(songs, SortCriteria::TITLE_ASC);
    for (const auto& song : songs) {
        std::cout << song.title << " - " << song.artist << "\n";
    }

    std::cout << "\nSorting songs by duration descending:\n";
    sort_songs(songs, SortCriteria::DURATION_DESC);
    for (const auto& song : songs) {
        std::cout << song.title << " (" << song.duration << "s)\n";
    }

    // Example snapshot usage
    std::cout << "\nSnapshot - Top 5 Longest Songs:\n";
    auto top_songs = snapshot.get_top_5_longest(songs);
    for (auto& s : top_songs) {
        std::cout << s.title << " - " << s.duration << "s\n";
    }

    // Generate playlist summary
    std::cout << "\nPlaylist Summary:\n";
    PlaylistSummary::Summary summary = summaryGen.generate_summary(songs);
    std::cout << "Total playtime: " << summary.total_playtime << " seconds\n";
    std::cout << "Unique artists: " << summary.unique_artists << "\n";

    // Search songs by rating 5
    std::cout << "\nSongs with Rating 5:\n";
    auto rated_songs = ratingTree.search_by_rating(5);
    for (int id : rated_songs) {
        Song s = db.get_song_by_id(id);
        std::cout << s.title << " by " << s.artist << "\n";
    }

    return 0;
}
