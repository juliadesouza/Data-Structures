#include <set>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
    }
};

node *breakChain(node *head)
{
    set<node *> visitedNodes;
    node *temp = head;
    visitedNodes.insert(temp);

    while (temp != NULL)
    {
        node *value = temp->next;
        if (visitedNodes.find(value) != visitedNodes.end())
        { // se o elemento já foi adicionado
            temp->next = NULL;
            break;
        }
        visitedNodes.insert(value);
        temp = temp->next;
    }
    return head;
}
