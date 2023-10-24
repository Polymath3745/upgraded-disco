#include "BinaryTree.hpp"

BinaryTree::BinaryTree()
: root(nullptr)
{

}

void BinaryTree::insert(int val)
{
    root  = insertRecursive(root, val);
}


TreeNode* BinaryTree::insertRecursive(TreeNode* node, int val)
{
    if (node == nullptr)
    {
        return new TreeNode(val);
    }

    if (val < node->data)
    {
        node->left = insertRecursive(node->left, val);
    }

    else if (val > node->data)
    {
        node->right = insertRecursive(node->right, val);
    }

    return node;

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

