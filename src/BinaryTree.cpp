#include "BinaryTree.hpp"

#include "Queue.hpp"
#include "helper.hpp"
#include <climits>

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
    result = searchRecursive(root, val);

    if (result == nullptr)
    {
        std::cout << "Node not found in tree" << std::endl;
    }

    else
    {
        std::cout << "Node found in tree : " << result->data << std::endl;
    }

    return result;
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

TreeNode* BinaryTree::findMax(TreeNode* node)
{

    // Base case: if the current node is null, return null
    if (node == nullptr)
    {
        return nullptr;
    }

    // Recursive step: if there is a right child, recursively find the minimum in the right subtree
    if (node->right != nullptr)
    {
        return findMax(node->right);
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

void BinaryTree::inOrderTraversal()
{
    inOrderTraversalRecursive(root);
}

void BinaryTree::inOrderTraversalRecursive(TreeNode* node)
 {
    if (node == nullptr)
    {
        return;
    }

    // Traverse left subtree
    inOrderTraversalRecursive(node->left);

    std::cout << node->data <<  " " << std::endl;

    // Traverse right subtree
    inOrderTraversalRecursive(node->right);
}

void BinaryTree::preOrderTraversal()
{
    preOrderTraversalRecursive(root);
}

void BinaryTree::preOrderTraversalRecursive(TreeNode* node)
{
    if (node == nullptr)
    {
        return;
    }

    std::cout << node->data <<  " " << std::endl;

    // Traverse left subtree
    preOrderTraversalRecursive(node->left);

    // Traverse right subtree
    preOrderTraversalRecursive(node->right);
}

void BinaryTree::postOrderTraversal()
{
    postOrderTraversalRecursive(root);
}

void BinaryTree::postOrderTraversalRecursive(TreeNode* node)
{
    if (node == nullptr)
    {
        return;
    }

    // Traverse left subtree
    postOrderTraversalRecursive(node->left);

    // Traverse right subtree
    postOrderTraversalRecursive(node->right);

    std::cout << node->data <<  " " << std::endl;
}

void BinaryTree::levelOrderTraversal()
{
    levelOrderTraversal(root);
}

void BinaryTree::levelOrderTraversal(TreeNode* node)
{
    Queue queue;
    queue.enqueue(node);
    while (!queue.isEmpty())
    {
        

        TreeNode* temp = queue.BSTdequeue();
        std::cout << temp->data << std::endl;
        if (temp->left != nullptr)
        {
            queue.enqueue(temp->left);
        }

        if (temp->right != nullptr)
        {
            queue.enqueue(temp->right);
        }

    }
}

int BinaryTree::getHeight()
{
    int height{0};
    height = getHeight(root);

    return height;
}

int BinaryTree::getHeight(TreeNode* node)
{
    int leftSubtreeHeight{0};
    int rightSubtreeHeight{0};

    if (node == nullptr)
    {
        return -1;
    }

    else
    {
        leftSubtreeHeight = getHeight(node->left);
        rightSubtreeHeight = getHeight(node->right);
        return Max(leftSubtreeHeight, rightSubtreeHeight) + 1;
    }
}

bool BinaryTree::isBalanced()
{
    int height{0};
    return isBalanced(root, height);
}

bool BinaryTree::isBalanced(TreeNode* node, int& height)
{
    if (node == nullptr)
    {
        height = 0;
        return true;
    }

    int leftHeight, rightHeight;
    bool leftIsBalanced = isBalanced(node->left, leftHeight);
    bool rightIsBalanced = isBalanced(node->right, rightHeight);

    // Check if left and right subtrees are balanced and their heights differ by at most 1
    if(leftIsBalanced && rightIsBalanced && abs(leftHeight - rightHeight) <= 1)
    {
        height = Max(leftHeight, rightHeight) + 1;
        return true;
    }

    // The tree is unbalanced
    height = 0;
    return false;
}

bool BinaryTree::isBST()
{
    return isBST(root, INT_MIN, INT_MAX);
}

bool BinaryTree::isBST(TreeNode* node, int min, int max)
{
    if (node == nullptr)
    {
        return true;
    }

    if (node->data < min || node->data > max)
    {
        return false;
    }

    // Check left subtree with updated maximum value
    // and right subtree with updated minimum value
    return isBST(node->left, min, node->data - 1) && isBST(node->right, node->data + 1, max);
}

int BinaryTree::findLCA()
{
    return findLCA(root, 3, 8);
}

int BinaryTree::findLCA(TreeNode* node, int node1, int node2)
{
    if (node == nullptr)
    {   
        // LCA not found
        return -1;
    }

    if (node->data > node1 && node->data > node2)
    {
        return findLCA(node->left, node1, node2);
    }

    else if (node->data < node1 && node->data < node2)
    {
        return findLCA(node->right, node1, node2);
    }

    else
    {
        return node->data;
    }
}

TreeNode* BinaryTree::findSuccessor(TreeNode* node)
{
    if(node->right != nullptr)
    {
        // Since the node has a right child, find the leftmost node in the right subtree
        return findMin(node->right);
    }
    else
    {
        // If the node does not have a right child, find the lowest ancestor with left child
        TreeNode* successor = nullptr;
        TreeNode* ancestor = root; // Start from the root of the tree

        while (ancestor != node)
        {
            if (node->data < ancestor->data)
            {
                // If node's value is smaller, update the successor and move left
                successor = ancestor;
                ancestor = ancestor->left;
            }

            else
            {
                // If node's value is greater, move right
                ancestor = ancestor->right;
            }
        }

        return successor;
    }
}

TreeNode* BinaryTree::findPredecessor(TreeNode* node)
{
    if(node->left != nullptr)
    {
        // If the node has a left child, the predecessor is the right most node in the left subtree
        return findMax(node->left);
    }

    else
    {
        // If the node does not have a left child, find the closest ancestor where the node is in the right subtree
        TreeNode* predecessor = nullptr;
        TreeNode* ancestor = root; // Start from the root of the tree

        while (ancestor != node)
        {
            if (node->data > ancestor->data)
            {
                // If node's value is greater, update the predecessor and move right
                predecessor = ancestor;
                ancestor = ancestor->right;
            }

            else
            {
                // If node's value is smaller, move left
                ancestor = ancestor->left;
            }
        }

        return predecessor;
    }
}