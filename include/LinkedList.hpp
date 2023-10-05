#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <iostream>
// Define the structure of a node
struct Node
{
    Node(int value)
    : data(value), next(nullptr)
    {

    }

    int data;
    Node* next;
};

class LinkedList
{
    public:
        // Constructor to initialize the linked list
        LinkedList();

        // Destructor to free the memory when the list is deleted
        ~LinkedList();

        // Function to insert a new node at the beginning of the list
        void insertAtBeginning(int value);

        // Function to print the elements of the list
        void printList() const;

        // Function to insert a new node at the end of the list
        void insertAtEnd(int value);

        // Function to delete the first node in the list
        void deleteFirstNode();

        // Function to delete the last node in the list
        void deleteLastNode();

        // Function to delete any node in the list
        void deleteNode(int key);

        // Function to search for certain node in the list
        bool search(int key) const;

        // Function to count nodes in a list
        int count();

        // Function to reverse the linked list
        void reverse();
        
        // TODO : Declare other linked list operations

    private:
        Node* head; // Pointer to the first node in the linked list
};
#endif //LINKEDLIST_HPP