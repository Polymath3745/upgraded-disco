#include "LinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include "DoublyCircular.hpp"
#include "RecursionExamples.hpp"
#include <iostream>

int main()
{
    // Create the doubly linked list object
    //DoublyCircular circleList;

    //circleList.insertAtBeginning(4);
    //circleList.insertAtBeginning(3);
    //circleList.insertAtBeginning(2);
    //circleList.insertAtBeginning(1);

    //circleList.display();

    //circleList.reverse();

    //circleList.display();
    int num = 5;
    int result = factorial(num);
    std::cout << result << std::endl;

    int n = 5;
    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;
    
    return 0;
}