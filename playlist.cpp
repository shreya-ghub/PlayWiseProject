#include "playlist.hpp"
#include <iostream>

Node::Node(const Song& s) : song(s), prev(nullptr), next(nullptr) {}

Playlist::Playlist() : head(nullptr), tail(nullptr), size(0) {}

Playlist::~Playlist() {
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
}

Song::Song(int _id, const std::string& _title, const std::string& _artist, int _duration)
    : id(_id), title(_title), artist(_artist), duration(_duration) {}

void Playlist::add_song(const Song& song) {
    Node* newNode = new Node(song);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    ++size;
}

bool Playlist::delete_song(int index) {
    if (index < 0 || index >= size) return false;
    Node* curr = head;
    for (int i = 0; i < index; ++i) curr = curr->next;

    if (curr->prev) curr->prev->next = curr->next;
    else head = curr->next;

    if (curr->next) curr->next->prev = curr->prev;
    else tail = curr->prev;

    delete curr;
    --size;
    return true;
}

bool Playlist::move_song(int from_index, int to_index) {
    if (from_index == to_index || from_index < 0 || to_index < 0 || from_index >= size || to_index >= size)
        return false;

    // Find node to move
    Node* curr = head;
    for (int i = 0; i < from_index; ++i) curr = curr->next;

    // Remove curr from its current position
    if (curr->prev) curr->prev->next = curr->next;
    else head = curr->next;

    if (curr->next) curr->next->prev = curr->prev;
    else tail = curr->prev;

    // Insert curr at new position
    if (to_index == 0) {
        curr->next = head;
        curr->prev = nullptr;
        if (head) head->prev = curr;
        head = curr;
        if (!tail) tail = curr;
    } else {
        Node* target = head;
        for (int i = 0; i < to_index; ++i) target = target->next;

        if (target) {
            curr->next = target;
            curr->prev = target->prev;
            if (target->prev) target->prev->next = curr;
            target->prev = curr;
        } else {
            // Insert at tail
            curr->prev = tail;
            curr->next = nullptr;
            if (tail) tail->next = curr;
            tail = curr;
        }
    }

    return true;
}

void Playlist::reverse_playlist() {
    Node* curr = head;
    Node* temp = nullptr;

    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp) {
        temp = temp->prev;
        std::swap(head, tail);
    }
}

void Playlist::print_playlist() const {
    Node* curr = head;
    while (curr) {
        std::cout << curr->song.title << " - " << curr->song.artist << " (" << curr->song.duration << "s)" << std::endl;
        curr = curr->next;
    }
}

int Playlist::get_size() const {
    return size;
}
