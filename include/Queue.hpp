#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include "BinaryTree.hpp"

// Node structure for the queue
struct QueueNode
{
    QueueNode(int val)
    : data(val), next(nullptr)
    {

    }

    QueueNode(TreeNode* node)
    : m_node(node), next(nullptr)
    {

    }

    int data;
    TreeNode* m_node;
    QueueNode* next;
};
// TODO: Perhaps I can make this a Template class to get rid of the overloaded functions...
class Queue
{
    public:
        Queue();

        // Add element to the rear of the queue
        void enqueue(int val);

        // For BinaryTree class
        void enqueue(TreeNode* node);

        // Remove and return element from the front of the queue
        int dequeue();

        // For BinaryTree class
        TreeNode* BSTdequeue();

        // Check if the queue is empty
        bool isEmpty();

        // peek the data in the front element
        int peek();

        // get size of queue
        int getSize();

        // clear
        void clear();
        
    private:
        QueueNode* front;
        QueueNode* rear;
};
#endif