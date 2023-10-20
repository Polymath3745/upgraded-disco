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

        // traverses tree
        void inorderTraversal();

        // search
        TreeNode* search(int val);

        // delete
        TreeNode* deleteNode(int val);

        // find min
        TreeNode* findMin(TreeNode* node);

    private:
        TreeNode* root;

        // inserts Recursively
        TreeNode* insertRecursive(TreeNode* node, int val);

        // traverses Recursively
        void inorderTraversal(TreeNode* node);

        // search Recursively
        TreeNode* searchRecursive(TreeNode* node, int val);

};
#endif