// Middle Element
// This is an easy problem! Apply runner technique to find mid-point of a given linked list in a
// single pass.
// Input
// Head of the Linked List is given as input.
// 1->2->3->4->5->6->7->8
// Output
// 4.

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

int getMid(node *head)
{
    node *f = head->next;
    node *s = head;

    while (f && f->next)
    {
        f = f->next->next;
        s = s->next;
    }

    return s->data;
}