#include "tree.h"

int compare(Node* curr, int& key) {

    int node_value { container_of(curr, Data, node)->key };
    if (curr->value < key) {
        return -1;
    } else if (curr->value > key) {
        return 1;
    } else {
        return 0;
    }
}

Node** tree_search(Node** from, const std::function<int(Node*, int&)> &comp, int& key) {
    Node* node { *from };

    if (!node) {
        return nullptr;
    }

    int result { comp(node, key) };

    if (result < 0) {
        return tree_search(&node->left, comp, key);
    } else if (result > 0) {
        return tree_search(&node->right, comp, key);
    } else {
        return from;
    }
}

bool tree_insert(int& key, const std::function<int(Node*, int&)> &comp) {
    Data* new_data;
    new_data->key = key;

    Node** insert_location { tree_search(&root->root, compare, key) };

    if (!*insert_location) {
        insert_location = &new_data->node;
        return true;
    } else {
        return false;
    }
}

bool tree_delete(int& key, const std::function<int(Node*, int&)> &comp) {
    
}