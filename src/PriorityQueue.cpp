#include "PriorityQueue.hpp"

PriorityQueue::PriorityQueue()
    : front(nullptr)
    {

    }

void PriorityQueue::enqueue(int data, int priority)
{
    PriorityQueueNode* newNode = new PriorityQueueNode(data, priority);

    if (front == nullptr)
    {
        front = newNode;
    }

    else
    {
        if (newNode->m_priority < front->m_priority)
        {
            // insert at the front
            newNode->next = front;
            front = newNode;
        }

        else
        {
            // Traverse the queue to find the correct position based on priority
            PriorityQueueNode* current = front;
            
            while (current->next != nullptr && newNode->m_priority >= current->next->m_priority)
            {
                current = current->next;
            }

            // Insert the new node at the correct position
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}
