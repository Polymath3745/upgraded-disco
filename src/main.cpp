#include "LinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include "DoublyCircular.hpp"
#include "RecursionExamples.hpp"
#include "BinaryTree.hpp"
#include <iostream>

int main()
{
    // Create a BinarySearchTree instance
    BinaryTree tree;

    // Insert elements into the tree
    tree.insert(1);
    tree.insert(3);
    tree.insert(2);
    tree.insert(8);
    tree.insert(6);
    
    // Perform in-order traversal and print the nodes
    std::cout << "In-order traversal: ";
    tree.inorderTraversal();
    std::cout << std::endl;

    return 0;
}