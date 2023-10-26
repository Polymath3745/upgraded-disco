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
        void search(int val);

        // delete
        void deleteNode(int val);

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

};
#endif