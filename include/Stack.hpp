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

        // pushes node to stack
        void push(int value);

        // pops node off of stack
        void pop();

        // returns the top data in stack
        int peek();

        // checks if the stck is empty
        bool isEmpty();

        // prints contents of the stack
        void printStack();

        // clear the stack
        void clear();

        // gets the size of the stack
        int getSize();

    private:
        StackNode* top;
};


#endif // STACK_HPP