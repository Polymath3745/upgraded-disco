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
    Node* current = this->head;
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
    newNode->next = this->head;
    this->head = newNode;
}

// Function to print the elements of the list
void LinkedList::printList() const
{
    Node* temp = this->head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Function to insert a new node at the end of the list
void LinkedList::insertAtEnd(int value)
{
    // Create a new node
    Node* newNode = new Node(value);

    // If the list is empty, make the new node the head
    if (this->head == nullptr)
    {
        this->head = newNode;
    }

    else
    {
        Node* temp = this->head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

// TODO: Implement other linked list operations