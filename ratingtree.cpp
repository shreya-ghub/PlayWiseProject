#include "ratingtree.hpp"
#include <iostream>

BSTNode::BSTNode(int rate) : rating(rate), left(nullptr), right(nullptr) {}

RatingTree::RatingTree() : root(nullptr) {}

BSTNode* RatingTree::insert(BSTNode* node, int rating, int song_id) {
    if (!node) {
        node = new BSTNode(rating);
        node->song_ids.insert(song_id);
        return node;
    }
    if (rating < node->rating) {
        node->left = insert(node->left, rating, song_id);
    } else if (rating > node->rating) {
        node->right = insert(node->right, rating, song_id);
    } else {
        // rating == node->rating
        node->song_ids.insert(song_id);
    }
    return node;
}

void RatingTree::insert_song(int song_id, int rating) {
    root = insert(root, rating, song_id);
}

BSTNode* RatingTree::find_min(BSTNode* node) {
    while (node && node->left) node = node->left;
    return node;
}

BSTNode* RatingTree::delete_node(BSTNode* node, int rating) {
    if (!node) return nullptr;
    if (rating < node->rating) node->left = delete_node(node->left, rating);
    else if (rating > node->rating) node->right = delete_node(node->right, rating);
    else {
        // node with only one child or no child
        if (!node->left) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }
        // node with two children: get inorder successor (min in right subtree)
        BSTNode* temp = find_min(node->right);
        node->rating = temp->rating;
        node->song_ids = temp->song_ids;
        node->right = delete_node(node->right, temp->rating);
    }
    return node;
}

BSTNode* RatingTree::delete_song(BSTNode* node, int song_id, int rating) {
    if (!node) return nullptr;
    if (rating < node->rating) {
        node->left = delete_song(node->left, song_id, rating);
    } else if (rating > node->rating) {
        node->right = delete_song(node->right, song_id, rating);
    } else {
        // Found rating node, remove song_id from set
        node->song_ids.erase(song_id);
        // If empty, delete this node
        if (node->song_ids.empty()) {
            node = delete_node(node, rating);
        }
    }
    return node;
}

void RatingTree::delete_song(int song_id, int rating) {
    root = delete_song(root, song_id, rating);
}

void RatingTree::search(BSTNode* node, int rating, std::set<int>& result) {
    if (!node) return;
    if (rating < node->rating) {
        search(node->left, rating, result);
    } else if (rating > node->rating) {
        search(node->right, rating, result);
    } else {
        // exact match
        result = node->song_ids;
    }
}

std::set<int> RatingTree::search_by_rating(int rating) {
    std::set<int> result;
    search(root, rating, result);
    return result;
}
void free_tree(BSTNode* node) {
    if (!node) return;
    free_tree(node->left);
    free_tree(node->right);
    delete node;
}

RatingTree::~RatingTree() {
    free_tree(root);
}

