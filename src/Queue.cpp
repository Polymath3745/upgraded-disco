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

// dequeue
int Queue::dequeue()
{
    if (front == nullptr)
    {
        return 0;
    }

    QueueNode* tempNode = front;
    int val = front->data;
    front = front->next;
    delete tempNode;

    return val;
}

// isEmpty
bool Queue::isEmpty()
{
    if(front == nullptr)
    {
        return true;
    }

    return false;
}