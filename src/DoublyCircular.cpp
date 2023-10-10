#include "DoublyCircular.hpp"
#include <iostream>

DoublyCircular::DoublyCircular()
: head(nullptr)
{

}

void DoublyCircular::insertNode(int val)
{
    CircleNode* newNode = new CircleNode(val);

    if(head == nullptr)
    {
        head = newNode;
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
    }
}

void DoublyCircular::deleteNode(int key)
{
    if(head == nullptr)
    {
        return;
    }

    if (head->data == key)
    {
        CircleNode* tempNode = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        delete tempNode;
    }

    CircleNode* current = head->next;
    while(current != head && current->data != key)
    {
        current = current->next;
    }

    if (current == head)
    {
        std::cout << "Node not found " << std::endl;
        return;
    }

    CircleNode* temp = current;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete temp;
}
