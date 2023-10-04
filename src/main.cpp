#include "LinkedList.hpp"
#include <iostream>

int main()
{
    // Create a LinkedList object
    LinkedList list;

    // Insert elements at the beginning of the list
    list.insertAtBeginning(3);
    list.insertAtBeginning(5);
    list.insertAtBeginning(7);
    list.insertAtBeginning(8);

    list.printList();
    bool found = list.search(7);
    int numOfNodes = list.count();
    list.reverse();
    list.printList();
    return 0;
}