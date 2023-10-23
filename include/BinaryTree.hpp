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

    private:
        TreeNode* root;

        // inserts iteratively
        void insert(TreeNode* node, int val);

        // traverses Recursively
        TreeNode* inorderSuccessor(TreeNode* node);

        // search iteratively
        TreeNode* search(TreeNode* node, int val);

        // delete in-order successor 
        TreeNode* deleteNode(TreeNode* node, int val);

};
#endif