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

// peek
int Queue::peek()
{
    if (front == nullptr)
    {
        return 0;
    }

    return front->data;
}

// get the size of the queue
int Queue::getSize()
{
    if (front == nullptr)
    {
        return 0;
    }

    QueueNode* tempNode  = front;
    int sizeCount = 1;
    while(tempNode != rear)
    {
        sizeCount++;
        tempNode = tempNode->next;
    }

    return sizeCount;
}

// clear the queue
void Queue::clear()
{
    if (front == nullptr)
    {
        std::cout << "queue is empty" << std::endl;
        return;
    }

    
    while(front != nullptr)
    {
        QueueNode* temp = front;
        front = front->next;
        delete temp;
    }
}