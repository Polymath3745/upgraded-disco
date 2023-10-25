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

void BinaryTree::search(int val)
{
    TreeNode* result;
    result = searchRecursive(root, val);

    if (result == nullptr)
    {
        std::cout << "Node not found in tree" << std::endl;
    }

    else
    {
        std::cout << "Node found in tree : " << result->data << std::endl;
    }
}

TreeNode* BinaryTree::searchRecursive(TreeNode* node, int val)
{
    // Node not found
    if (node == nullptr)
    {
        return node;
    }

    else if (val < node->data)
    {
        return searchRecursive(node->left, val);
    }

    else if (val > node->data)
    {
        return searchRecursive(node->right, val);
    }

    // Node found!
    return node;
}

