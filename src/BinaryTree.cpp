#include "BinaryTree.hpp"

BinaryTree::BinaryTree()
: root(nullptr)
{

}

void BinaryTree::insert(int val)
{
    root = insertRecursive(root, val);
}

TreeNode* BinaryTree::search(int val)
{
    if (root == nullptr)
    {
        std::cout << "this tree is empty" << std::endl;
        return nullptr;
    }

    TreeNode* found = searchRecursive(root, val);

    if (found == nullptr)
    {
        std::cout << "Value not found in tree" << std::endl;
    }

    else
    {
        std::cout << "Value found!" << std::endl;
        std::cout << found << " has a value of " << found->data << std::endl;
    }
    
    return found;
}

TreeNode* BinaryTree::deleteNode(int val)
{   
    // I first make a call to my searchRecursive function
    // This will retrieve the node I want to delete
    TreeNode* node = searchRecursive(root, val);

    // Check if node exists
    if (node == nullptr)
    {
        std::cout << "Node not found in tree" << std::endl;
        return;
    }

    
/*Node with the value to be deleted was found*/

    // Case 1: Node has no children (leaf node)
    if (node->left == nullptr && node->right == nullptr)
    {
        // Delete the node and return null to update
        delete node;
        return nullptr;
    }

    // Case 2: Node has one child
    else if (node->left == nullptr)
    {   
        // Replace the node with its right child and delete the node
        TreeNode* temp = node->right;
        delete node;
        return temp;
    }

    else if (node->right == nullptr)
    {
        // Replace the node with its left child and delete the node
        TreeNode* temp = node->left;
        delete node;
        return temp;
    }

    // Case 3 - Node with two children
    TreeNode* successor = findMin(node->right);
    node->data = successor->data;
    
}


void BinaryTree::inorderTraversal()
{
    inorderTraversal(root);
}

/*The start of my recursive private functions*/

TreeNode* BinaryTree::deleteSuccessor(TreeNode* node, int val)
{
    if (node == nullptr) 
    {
        return nullptr;
    }

    if (val < node->data) 
    {
        node->left = deleteSuccessor(node->left, val);
    }
    else 
    {
        // Node with value to be deleted found

        // Case 1 - Node with no children
        if (node->left == nullptr && node->right == nullptr) 
        {
            delete node;
            return nullptr;
        }

        // Case 2 - Node with one child
        if (node->left == nullptr) 
        {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
    }

    return node;
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

TreeNode* BinaryTree::searchRecursive(TreeNode* node, int val)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    else if (val < node->data)
    {
        return searchRecursive(node->left, val);
    }

    else if (val > node->data)
    {
        return searchRecursive(node->right, val);
    }

    // Value is found
    std::cout << "Returning Node: " << node->data << std::endl;
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

TreeNode* BinaryTree::findMin(TreeNode* node)
{
    if (node->left == nullptr)
    {
        return node;
    }

    return findMin(node->left);
}

