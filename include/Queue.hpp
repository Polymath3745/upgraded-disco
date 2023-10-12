#include <iostream>

// Node structure for the queue
struct QueueNode
{
    QueueNode(int val)
    : data(val), next(nullptr)
    {

    }

    int data;
    QueueNode* next;
};

class Queue
{
    public:
        Queue();

        // Add element to the rear of the queue
        void enqueue(int val);

        // Remove and return element from the front of the queue
        int dequeue();

        // Check if the queue is empty
        bool isEmpty();

        // peek the data in the front element
        int peek();

    private:
        QueueNode* front;
        QueueNode* rear;
};