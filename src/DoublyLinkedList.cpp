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

void DoublyLinkedList::deleteNode(int key)
{
    // If the list is empty
    if(this->head == nullptr)
    {
        return;
    }

    // Special case: if the node to be deleted is the head
    if (this->head->data == key)
    {
        Node* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }

    // Special case: if the node to be deleted is the tail
    if (this->tail->data == key)
    {
        Node* temp = this->tail;
        this->tail = this->tail->prev;
        delete temp;
    }

    // Traverse the list until the key is found
    Node* temp = this->head;
    while(temp != nullptr && temp->data != key)
    {
        temp = temp->next;
    }

    // If the node was not found 
    if (temp == nullptr)
    {
        return;
    }

    // Update pointers
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    // Delete the node
    delete temp; 
}

bool DoublyLinkedList::search(int key)
{
    // If the list is empty
    if (this->head == nullptr)
    {
        return false;
    }

    // Traverse the list and search for node
    Node* temp = this->tail;
    while(temp != nullptr && temp->data != key)
    {
        temp = temp->prev;
    }

    // If node not found
    if (temp == nullptr)
    {
        return false;
    }

    else
    {
        std::cout << temp->data;
        return true;
    }
}