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

// Function to delete the first node in the list
void LinkedList::deleteFirstNode()
{
    // If the list is empty, there's nothing to delete
    if (this->head == nullptr)
    {
        return;
    }

    // Store the current head node to delete it later
    Node* temp = this->head;

    // Update the head pointer to point to the second node
    this->head = this->head->next;

    delete temp;
}

// Function to delete the last node in the list
void LinkedList::deleteLastNode()
{
    // If the list is empty, there's nothing to delete
    if (this->head == nullptr)
    {
        return;
    }

    // If there's only one node in the list
    if (this->head->next == nullptr)
    {
        delete this->head;
        this->head = nullptr;
        return;
    }

    // Traverse the list to find the second-to-last node
    Node* temp = this->head;
    while(temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    // Delete the last node
    delete temp->next;

    // Set the next pointer of the second-to-last node to nullptr
    temp->next = nullptr;

}

void LinkedList::deleteNode(int key)
{
    // If the list is empty, there's nothing to delete
    if (this->head == nullptr)
    {
        return;
    }

    // Special case: if the node to be deleted is the head
    if (this->head->data == key)
    {
        Node* temp = this->head;
        this->head = this->head->next;
        delete temp;

        return;
    }

    // Traverse the list to find the node to be deleted and its previous node
    Node* temp = this->head;
    Node* prev = nullptr;
    while(temp != nullptr && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the node was not found
    if(temp == nullptr)
    {
        return;
    }

    // Adjust pointers to skip the node to be deleted
    prev->next = temp->next;

    // Delete the node
    delete temp;
}

bool LinkedList::search(int key) const
{
    Node* temp = head;
    while (temp != nullptr)
    {
        if(temp->data == key)
        {
            // Found the node with the given key
            return true;
        }
        temp = temp->next;
    }
    // Node with the given key not found
    return false;
}

int LinkedList::count()
{
    Node* temp = this->head; // Start from the head of the linked list
    int count = 0; // Inistialize a counter to keep track

    // Traverse the list and count the nodes
    while (temp != nullptr)
    {
        count++; // Increment the counter for each node
        temp = temp->next; // Move to the next node
    }

    return count; // Return the total number of nodes in the list
}

void LinkedList::reverse()
{
    Node* prev = nullptr;
    Node* current = this->head;
    Node* next = nullptr;

    // Traverse the list and reverse the pointers of each node
    while(current != nullptr)
    {
        next = current->next; // Save the next node
        current->next = prev; // Reverse the pointer
        prev = current;       // Move the prev to the current node
        current = next;       // Move current to the next node
    }

    this->head = prev;         // Set the head to the last node, which is now the first node
}
// TODO: Implement other linked list operations