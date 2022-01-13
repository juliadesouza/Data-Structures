#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;

    Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};

bool isPresent(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }

    if (key == root->key)
    {
        return true;
    }
    if (key < root->key)
    {
        return isPresent(root->left, key);
    }
    else
    {
        return isPresent(root->right, key);
    }

    return false;
}