#include <string>

struct Node {
    Node* parent;
    Node* left;
    Node* right;
    int count;
    int value;
};

struct Data {
    Node* node;
    int key;
};