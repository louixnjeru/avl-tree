#pragma once

#include "node.h"

#include <functional>

#define container_of(ptr, T, member) \
    ((T *)( (char *)ptr - offsetof(T, member) ))

struct Tree {
    Node* root {};
};

static Tree* root;


int compare(Node* curr, int& key);

Node** tree_search(Node** from, std::function<int(Node*, int&)> &comp, int& key);
bool tree_insert(int& key, std::function<int(Node*, int&)> &comp);
bool tree_delete(int& key, const std::function<int(Node*, int&)> &comp);
