#include "BinaryTree.hpp"

BinaryTree::BinaryTree()
: root(nullptr)
{

}

void BinaryTree::insert(int val)
{
    root = insertRecursive(root, val);
}

void BinaryTree::inorderTraversal()
{
    inorderTraversal(root);
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

void BinaryTree::inorderTraversal(TreeNode* node)
{
    if (node == nullptr)
    {
        return;
    }

    inorderTraversal(node->left);
    std::cout << node->data << " ";
    inorderTraversal(node->right);
}
