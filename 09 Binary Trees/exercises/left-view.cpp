#include <vector>
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
void getLeftView(Node *root, vector<int> &arr, int level, int *lastLevel)
{
    if (root == NULL)
    {
        return;
    }

    if (level > *lastLevel)
    {
        arr.push_back(root->key);
        *lastLevel = level;
    }
    getLeftView(root->left, arr, level + 1, lastLevel);
    getLeftView(root->right, arr, level + 1, lastLevel);
}
vector<int> leftView(Node *root)
{
    vector<int> arr;
    int max_level = 0;
    getLeftView(root, arr, 1, &max_level);
    return arr;
}