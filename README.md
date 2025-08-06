# 🎵 PlayWise – Smart Music Playlist Management Engine

##  Overview
PlayWise is a **C++-based backend engine** for a smart music playlist platform.  
It provides **real-time playlist manipulation**, **instant song lookup**, **personalized recommendations**, and **memory-efficient data management** using a combination of advanced data structures.

This project was developed as part of a **Data Structures & Algorithms Hackathon** challenge.

---

 Features
- **Playlist Engine (Doubly Linked List)**
  - Add, delete, move, and reverse songs.
  - Maintain song order efficiently.
- **Playback History (Stack)**
  - Undo recently played songs.
- **Song Rating Tree (BST)**
  - Fast insertion, search, and deletion of songs by rating.
- **Instant Song Lookup (HashMap)**
  - Retrieve song metadata in O(1) time by ID or title.
- **Sorting Module (Custom & Built-in)**
  - Sort by title, duration (ascending/descending).
- **Pinned Songs**
  - Keep specific songs at fixed positions even after sorting/shuffling.
- **Snapshot Module**
  - Get top 5 longest songs, recent plays, and rating distributions.
- **Playlist Summary Generator**
  - Get total playtime, unique artist count, and genre distribution.

---

Architecture
**Core Modules:**
1. `playlist.hpp / playlist.cpp` – Playlist engine using **Doubly Linked List**.
2. `history.hpp` – Playback history using **Stack**.
3. `ratingtree.hpp / ratingtree.cpp` – Song rating index using **Binary Search Tree**.
4. `songdb.hpp` – Song lookup using **HashMap**.
5. `sort.hpp` – Sorting functions (Merge/Quick sort and std::sort).
6. `snapshot.hpp` – Dashboard & snapshot generation.
7. `pinned.hpp` – Logic for pinned songs.
8. `summary.hpp` – Playlist summary calculations.
