#include <iostream>

#include "LinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include "DoublyCircular.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "RecursionExamples.hpp"
#include "BinaryTree.hpp"
#include "Graph.hpp"
#include "PriorityQueue.hpp"

int main()
{
    PriorityQueue* pq = new PriorityQueue();
    pq->enqueue(10, 3);
    pq->enqueue(11,5);
    pq->enqueue(12,6);
    pq->enqueue(13,15);
    pq->enqueue(1, 12);
    return 0;
}