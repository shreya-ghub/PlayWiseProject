#ifndef RATINGTREE_HPP
#define RATINGTREE_HPP

#include <set>
#include <iostream>

struct BSTNode {
    int rating;
    std::set<int> song_ids; // store song IDs having this rating
    BSTNode *left, *right;

    BSTNode(int rate);
};

class RatingTree {
private:
    BSTNode* root;

    BSTNode* insert(BSTNode* node, int rating, int song_id);
    BSTNode* delete_song(BSTNode* node, int song_id);
    BSTNode* delete_song_from_node(BSTNode* node, int song_id);
    BSTNode* find_min(BSTNode* node);
    BSTNode* delete_node(BSTNode* node, int rating);
    BSTNode *delete_song(BSTNode *node, int song_id, int rating);
    void delete_song(int song_id, int rating);
    void search(BSTNode *node, int rating, std::set<int> &result);
    
    void search(BSTNode *node, int rating, std::set<int> &result) const;
    void delete_tree(BSTNode* node);

public:
    RatingTree();
    ~RatingTree();
    std::set<int> search_by_rating(int rating);

    void insert_song(int song_id, int rating);
    void delete_song(int song_id);
    std::set<int> search_by_rating(int rating) const;
};

#endif
