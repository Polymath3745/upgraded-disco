#include "LinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include <iostream>

int main()
{
    // Create the doubly linked list object
    DoublyLinkedList list;

    list.insertBeginning(3);
    list.insertBeginning(2);
    list.insertBeginning(1);
    list.getNthNodeFromEnd(2);
    
    return 0;
}