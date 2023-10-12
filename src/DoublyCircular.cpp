#include "DoublyCircular.hpp"
#include <iostream>

DoublyCircular::DoublyCircular()
: head(nullptr)
{

}

void DoublyCircular::insertAtBeginning(int val)
{
    CircleNode* newNode = new CircleNode(val);

    if(head == nullptr)
    {
        head = newNode;
        head->next = newNode;
        head->prev = newNode;
    }

    else
    {   
        // Sets the newNode prev pointer to original heads previous node
        newNode->prev = head->prev;
        // Sets the newNodes next pointer to original head;
        newNode->next = head;

        // Tricky part * sets the node (before the orginal head ) next pointer to the newNode
        head->prev->next = newNode;

        // Sets the original heads prev pointer to the new Node
        head->prev = newNode;
            
        head = newNode;
    }
}
void DoublyCircular::deleteNode(int key)
{
    if(head == nullptr)
    {
        return;
    }

    if (head->data == key)
    {
        CircleNode* tempNode = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        delete tempNode;
    }

    CircleNode* current = head->next;
    while(current != head && current->data != key)
    {
        current = current->next;
    }

    if (current == head)
    {
        std::cout << "Node not found " << std::endl;
        return;
    }

    CircleNode* temp = current;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete temp;
}

CircleNode* DoublyCircular::search(int key)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    CircleNode* current = head->next;
    while(current != head && current->data != key)
    {
        current = current->next;
    }

    if (current == head)
    {
        std::cout << "Node not found in list" << std::endl;
        return nullptr;
    }

    std::cout << "Node found!" << std::endl;
    return current;
}

void DoublyCircular::insert(int pos, int val)
{
    CircleNode* newNode = new CircleNode(val);
    if (head == nullptr)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
    }

    if (pos == 0)
    {
        insertAtBeginning(val);
    }

    // Validate position
    if (pos < 0)
    {
        std::cout << "Invalid position!" << std::endl;
        return;
    }


    CircleNode* current = head->next;
    int positionCount = 0;
    while(current != head && positionCount < pos)
    {
        current = current->next;
        positionCount++;
    }

    if (current == head)
    {
        std::cout << "position not in list!" << std::endl;
    }

    newNode->prev = current->prev;
    newNode->next = current;
    current->prev = newNode;
    current->prev->next = newNode;
}

int DoublyCircular::length()
{
    CircleNode* current = head->next;
    int length{0};

    if (head == nullptr)
    {
        return length;
    }

    while(current != head)
    {
        current = current->next;
        length++;
    }

    length++;
    return length;
}

void DoublyCircular::reverse()
{
    if (head == nullptr)
    {
        return;
    }

    CircleNode* current = head->next;
    CircleNode* tempPrev = current->prev;
    CircleNode* tempNext = nullptr;

    while(current != head)
    {
        tempNext = current->next;
        current->next = tempPrev;
        current->prev = tempNext;
        tempPrev = current;
        current = tempNext; 
    }

    head->next = tempPrev;
    head->prev = current;
    head = tempPrev;
}

void DoublyCircular::display()
{
    CircleNode* current = head;
    while(current != head->prev)
    {
        std::cout << current->data << std::endl;
        current = current->next;
    }

    std::cout << current->data << std::endl;
}