#include "BinaryTree.hpp"

BinaryTree::BinaryTree()
: root(nullptr)
{

}

void BinaryTree::insert(int val)
{
    insert(root, val);
}


void BinaryTree::insert(TreeNode* node, int val)
{
    // New node to insert
    TreeNode* newNode = new TreeNode(val);
    // Copy of root node
    TreeNode* current = node;
    // keep track of parentiously visited node
    TreeNode* parent = current;

    if (node == nullptr)
    {
        node = newNode; // If the tree is empty, the new node becomes the root
        return;
    }

    while(current != nullptr)
    {
        parent = current;
        if(val < current->data)
        {
            current = current->left;
        }

        else if (val > current->data)
        {
            current = current->right;
            
        }
        else if (val == current->data)
        {
            // Duplicate node entered
            delete newNode;
            return;
        }
    }

    if(val < parent->data)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }

}

TreeNode* BinaryTree::search(int val)
{
    TreeNode* result;
    result = search(root, val);
    return result;
}

TreeNode* BinaryTree::search(TreeNode* node, int val)
{
    TreeNode* current = node;

    if (current == nullptr)
    {
        std::cout << "Tree is currently empty" << std::endl;
        return nullptr;
    }

    while(current != nullptr)
    {
        if (val < current->data)
        {
            current = current->left;
        }

        else if (val > current->data)
        {
            current = current->right;
        }
    }

    if (current == nullptr)
    {
        std::cout << "Node not found in Tree" << std::endl;
        return nullptr;
    }

    std::cout << "Node found!" << std::endl;
    return current;
}

