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

    // Print the elements of the list
    std::cout << "Linked List elements: ";
    list.printList(); // Output : Linked List elements: 7 5 3
    list.deleteNode(5);
    std::cout << "Linked List elements: ";
    list.printList();
    
    return 0;
}