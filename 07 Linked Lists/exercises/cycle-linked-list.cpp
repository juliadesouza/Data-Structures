// Yes, a Linked List may contain a Cycle ! See this example below, where the last node
// instead of pointing to a NULL points to some middle node of the linked list.
// Your task is to write a function, that returns true/false depending upon whether the
// linked contains a cycle or not!

// Do you need hints?

// Hint - 1 Think @ using Runner Technique - Two Pointers (Fast & Slow)
// Hint - 2 If they enter inside the loop, they will match at some point.

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

bool containsCycle(node *head)
{
    //Complete this function
    node *f = head->next;
    node *s = head;

    while (f != NULL && f->next != NULL)
    {
        if (s == f)
        {
            return true;
        }
        f = f->next->next;
        s = s->next;
    }
    return false;
}
