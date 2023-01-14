#include<bits/stdc++.h>
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

	TreeNode* lca_binary_tree(TreeNode* root, TreeNode* n1, TreeNode* n2) {
		if (root == NULL || root == n1 || root == n2) {
			return root;
		}

		TreeNode* left = lca_binary_tree(root->left, n1, n2);
		TreeNode* right = lca_binary_tree(root->right, n1, n2);

		if (left == NULL) {
			return right;
		} else if (right == NULL) {
			return left;
		} else {
			// if both left and right are NULL means, under the current root both
			// the required nodes are present
			return root;
		}
	}
};