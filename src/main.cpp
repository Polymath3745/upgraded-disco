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
    // balanced tree
    tree.insert(10);
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(7);
    tree.insert(15);
    tree.insert(12);
    tree.insert(11);
    tree.insert(18);
    
    // unbalanced tree
/*     tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(2);
    tree.insert(9);
    tree.insert(1); */
    

    bool result = tree.isBST();
    std::cout << result << std::endl;

    
    // Perform search and retrieve node if found;
    //TreeNode* result = tree.search(2);

    return 0;
}