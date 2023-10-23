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





