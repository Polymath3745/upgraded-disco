#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

struct DoubleNode
{
    DoubleNode(int value)
    : data(value), prev(nullptr), next(nullptr)
    {

    }

    int data;
    DoubleNode* prev;
    DoubleNode* next;
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

        // Function to delete a node in the list
        void deleteNode(int key);

        // Function to search for a node in the list
        bool search(int key);

        // Function for finding the 'nth' node from the end
        DoubleNode* getNthNodeFromEnd(int n);
    private:
        DoubleNode* head; // Pointer to the first node in the linked list
        DoubleNode* tail; // Pointer to the last node in the linked list
};
#endif