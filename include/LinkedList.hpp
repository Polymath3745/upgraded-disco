#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

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

        // TODO : Declare other linked list operations

    private:
        Node* head; // Pointer to the first node in the linked list
};
#endif //LINKEDLIST_HPP