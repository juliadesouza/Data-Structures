// Warm Up - Search!
// -
// Complete the function which checks whether a given key is present in the Linked List or not!
// Input
// (The linked list is already created at the head pointer, you don't need to write any other
// functions except the one given)
// head
//     1 -> 2 -> 3 -> 4 -> 5 ->6 ->7
// Key = 4

// Output
//     true
// Since 4 is present in the linked list, we return true.

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

bool isPresent(node *head, int key)
{

    //Complete this function
    while (head->next != NULL)
    {
        if (head->data == key)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}
