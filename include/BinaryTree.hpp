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

        /**
         * @brief Get the Height of the BST
         * 
         * @return int 
         */
        int getHeight();
        
        /**
         * @brief finds if the BST is balanced or not
         * 
         * @return true 
         * @return false 
         */
        bool isBalanced();

        /**
         * @brief finds if the tree is a BST or not
         * 
         * @return true 
         * @return false 
         */
        bool isBST();


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

        /**
         * @brief find the minimum valued node
         * 
         * @param node 
         * @return TreeNode* 
         */
        TreeNode* findMin(TreeNode* node);

        /**
         * @brief find the maximum valued node in tree
         * 
         * @param node 
         * @return TreeNode* 
         */
        TreeNode* findMax(TreeNode* node);

        /**
         * @brief in order traversal recursive
         * 
         */
        void inOrderTraversalRecursive(TreeNode* node);

        /**
         * @brief pre order traversal recursive
         * 
         */
        void preOrderTraversalRecursive(TreeNode* node);

        /**
         * @brief post order traversal recursive
         * 
         * @param TreeNode* node 
         */
        void postOrderTraversalRecursive(TreeNode* node);

        /**
         * @brief 
         * Starts by enqueue of the root node
         * traverses level order
         * 
         * @param TreeNode* node 
         */
        void levelOrderTraversal(TreeNode* node);
        
        /**
         * @brief Get the Height of the BST
         * 
         * @param TreeNode*  node 
         * @return int 
         */
        int getHeight(TreeNode* node);

        /**
         * @brief private helper for checking if tree is balanced
         * 
         * @param node 
         * @param height 
         * @return true 
         * @return false 
         */
        bool isBalanced(TreeNode* node, int& height);

        /**
         * @brief checks if tree is a BST
         * 
         * @param minValue 
         * @param maxValue 
         */
        bool isBST(TreeNode* node, int minValue, int maxValue);
};
#endif