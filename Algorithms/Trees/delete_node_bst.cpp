/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* findLastRightChild(TreeNode* root) {
        if (root->right == NULL) return root;
        return findLastRightChild(root->right);
    }

    TreeNode* connectTree(TreeNode* root) {
        if (root->left == NULL) return root->right;
        if (root->right == NULL) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastChild = findLastRightChild(root->left);
        lastChild->right = rightChild;
        return root->left;
    }

    // Main function
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;

        // if the root node is only the node we need to delete
        // then we will pass the the root node to connect tree.. as the left tree will connect to right tree
        if (root->val == key) {
            return connectTree(root);
        }

        TreeNode* head = root;

        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL and root->left->val == key) {
                    root->left = connectTree(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != NULL and root->right->val == key) {
                    root->right = connectTree(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return head;
    }
};