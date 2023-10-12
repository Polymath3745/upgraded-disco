#include "Stack.hpp"

Stack::Stack()
: top(nullptr)
{

}

Stack::~Stack()
{
    while (top != nullptr)
    {
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
    
}

void Stack::push(int val)
{
    StackNode* newNode = new StackNode(val);
    if (top == nullptr)
    {
        top = newNode;
    }

    else
    {
        newNode->next = top;
        top = newNode;
    }
}

void Stack::pop()
{
    if (top == nullptr)
    {
        return;
    }

    else
    {
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
}

int Stack::peek()
{
    if (top == nullptr)
    {
        return -1;
    }

    else
    {
        return top->data;
    }
}