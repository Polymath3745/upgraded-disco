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

TreeNode* BinaryTree::findMin(TreeNode* node)
{

    // Base case: if the current node is null, return null
    if (node == nullptr)
    {
        return nullptr;
    }

    // Recursive step: if there is a left child, recursively find the minimum in the left subtree
    if (node->left != nullptr)
    {
        return findMin(node->left);
    }

    // If there is no left child, this node is the minimum node
    return node;
}

void BinaryTree::deleteNode(int val)
{
    root = deleteNodeRecursive(root, val);
}

TreeNode* BinaryTree::deleteNodeRecursive(TreeNode* node, int val)
{

    if (node == nullptr)
    {
        return nullptr;
    }

    else if (val < node->data)
    {
        node->left = deleteNodeRecursive(node->left, val);
    }

    else if (val > node->data)
    {
        node->right = deleteNodeRecursive(node->right, val);
    }

    
    else
    {
        // Node found

            // Case 1: no children
        if (node->right == nullptr && node->left == nullptr)
        {
            delete node;
            return nullptr;
        }

        // Case 2: one child
        else if (node->right == nullptr)
        {
            TreeNode* temp;
            temp = node->left;
            delete node;
            return temp;
        }

        else if (node->left == nullptr)
        {
            TreeNode* temp;
            temp = node->right;
            delete node;
            return temp;
        }

        // Case 3: two children
        else
        {
            TreeNode* temp = findMin(node->right); // Find in-order successor
            node->data = temp->data; // Replace node's data with successor's data
            node->right = deleteNodeRecursive(node->right, temp->data); // Recursively delete the successor
        }
    }
    

    return node;
}

