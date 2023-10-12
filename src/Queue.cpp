#include "Queue.hpp"

// Constructor
Queue::Queue()
: front(nullptr), rear(nullptr)
{

}

// enqueue
void Queue::enqueue(int val)
{
    QueueNode* newNode = new QueueNode(val);

    if(front == nullptr)
    {
        front = newNode;
        rear = newNode;
    }

    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

