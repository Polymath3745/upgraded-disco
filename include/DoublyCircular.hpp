#ifndef DOUBLYCIRCULAR_HPP
#define DOUBLYCIRCULAR_HPP

struct CircleNode
{
    CircleNode(int data)
    : data(data), next(nullptr), prev(nullptr)
    {

    }
    int data;
    CircleNode* next;
    CircleNode* prev;
};

class DoublyCircular
{    
    public:
        // Constructor
        DoublyCircular();

        // Inserting
        void insertAtBeginning(int val);

        // Insert anywhere in list
        void insert(int pos, int val);

        // Deletion
        void deleteNode(int val);

        // Length
        int length();

        // Search
        CircleNode* search(int key);

        // Reverse
        void reverse();

        // Display
        void display();

    private:
        CircleNode* head;

};
#endif