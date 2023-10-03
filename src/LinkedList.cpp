#include "LinkedList.hpp"
#include <iostream>

// Constructor initializes an empty linked list
LinkedList::LinkedList()
: head(nullptr)
{

}

// Destructor to free memory when the list is deleted
LinkedList::~LinkedList()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Function to insert a new node at the beginning of the list
void LinkedList::insertAtBeginning(int value)
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Function to print the elements of the list
void LinkedList::printList() const
{
    Node* temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// TODO: Implement other linked list operations