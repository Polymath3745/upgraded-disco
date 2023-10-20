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
    tree.insert(4);
    tree.insert(8);
    tree.insert(6);
    tree.insert(2);
    
    // Perform search and retrieve node if found;
    TreeNode* result = tree.search(2);

    return 0;
}