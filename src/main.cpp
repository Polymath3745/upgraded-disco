#include "LinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include "DoublyCircular.hpp"
#include <iostream>

int main()
{
    // Create the doubly linked list object
    DoublyCircular circleList;

    circleList.insertAtBeginning(4);
    circleList.insertAtBeginning(3);
    circleList.insertAtBeginning(2);
    circleList.insertAtBeginning(1);

    circleList.display();

    circleList.reverse();

    circleList.display();
    
    return 0;
}