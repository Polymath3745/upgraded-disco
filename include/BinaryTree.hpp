#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>

struct TreeNode
{
    TreeNode(int val)
    : data(val), left(nullptr), right(nullptr)
    {

    }

    int data;
    TreeNode* left;
    TreeNode* right;
};

class BinaryTree
{
    public:
        BinaryTree();

        // inserts node in tree
        void insert(int val);

        // search
        void search(int val);

        // delete
        void deleteNode(int val);

        // In order Traversal
        void inOrderTraversal();

        // Pre order Traversal
        void preOrderTraversal();

        // Post order Traversal
        void postOrderTraversal();

        // Level order Traversal
        void levelOrderTraversal();

    private:
        TreeNode* root;

        // inserts iteratively
        TreeNode* insertRecursive(TreeNode* node, int val);

        // traverses Recursively
        TreeNode* inorderSuccessor(TreeNode* node);

        // search iteratively
        TreeNode* searchRecursive(TreeNode* node, int val);

        // delete 
        TreeNode* deleteNodeRecursive(TreeNode* node, int val);

        // find min
        TreeNode* findMin(TreeNode* node);

        // traverse recursively
        void inOrderTraversalRecursive(TreeNode* node);

        // traverse recursively
        void preOrderTraversalRecursive(TreeNode* node);

        // traverse recursively
        void postOrderTraversalRecursive(TreeNode* node);

        // level order traversal
        void levelOrderTraversalRecursive(TreeNode* node);
};
#endif