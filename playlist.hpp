#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <string>
#include <iostream>

struct Song {
    int id;
    std::string title, artist;
    int duration; // in seconds

    Song() = default;
    Song(int _id, const std::string& _title, const std::string& _artist, int _duration);
};

struct Node {
    Song song;
    Node* prev;
    Node* next;

    Node(const Song& s);
};

class Playlist {
private:
    Node* head;
    Node* tail;
    int size;

public:
    Playlist();
    ~Playlist();

    void add_song(const Song& song);
    bool delete_song(int index);
    bool move_song(int from_index, int to_index);
    void reverse_playlist();

    void print_playlist() const;

    int get_size() const;
};

#endif // PLAYLIST_HPP
