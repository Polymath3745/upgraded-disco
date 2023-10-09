#include "DoublyCircular.hpp"

DoublyCircular::DoublyCircular()
: head(nullptr), tail(nullptr)
{

}

void DoublyCircular::insert(int val)
{
    CircleNode* newNode = new CircleNode(val);

    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }

    else
    {   
        // Sets the newNode prev pointer to original heads previous node
        newNode->prev = head->prev;
        // Sets the newNodes next pointer to original head;
        newNode->next = head;

        // Sets the original heads prev pointer to the new Node
        head->prev = newNode;

        // Tricky part * sets the node (before the orginal head ) next pointer to the newNode
        head->prev->next = newNode;
        head = newNode;
        tail = newNode;
    }
}

