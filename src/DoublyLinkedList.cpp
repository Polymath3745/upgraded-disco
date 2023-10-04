#include "DoublyLinkedList.hpp"
#include <iostream>

DoublyLinkedList::DoublyLinkedList()
: head(nullptr), tail(nullptr)
{

}

void DoublyLinkedList::insertEnd(int value)
{
    Node* newNode = new Node(value);
    if (this->head == nullptr)
    {
        // If the lsit is empty, set the new node ast both head and tail
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        // Otherwise, update tail's next and newNode's prev
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;

    }
}

void DoublyLinkedList::insertBeginning(int value)
{
    Node* newNode = new Node(value);
    if(this->head == nullptr)
    {
        // If the list is empty, set the new node as both head and tail
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        newNode->next = this->head;
        this->head->prev = newNode;
        this->head = newNode;
    }
}