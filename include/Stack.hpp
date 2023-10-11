#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>

struct StackNode
{
    StackNode(int value)
    : data(value), next(nullptr)
    {

    }

    int data;
    StackNode* next;
};

class Stack
{
    public:
        Stack();
        ~Stack();

        void push(int value);
        void pop();
        int peek();
        bool isEmpty();
        void printStack();

    private:
        StackNode* top;
};


#endif // STACK_HPP