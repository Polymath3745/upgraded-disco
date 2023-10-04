#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

struct Node
{
    Node(int value)
    : data(value), prev(nullptr), next(nullptr)
    {

    }

    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList
{
    public:
        DoublyLinkedList();

        // Function to insert a node at the end of the list
        void insertEnd(int value);

        // Function to insert a node at the beginning of the list
        void insertBeginning(int value);

        // Function to print the list in forward direction
        void printForward();

        // Function to print the list in reverse direction
        void printReverse();

    private:
        Node* head; // Pointer to the first node in the linked list
        Node* tail; // Pointer to the last node in the linked list
};
#endif