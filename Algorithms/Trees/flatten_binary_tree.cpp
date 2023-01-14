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

	// Using Morris traversal
	vector<int> flatten_binary_tree(TreeNode* root) {
		TreeNode* curr = root;
		while (curr != NULL) {
			if (curr->left != NULL) {
				TreeNode* prev = curr->left;

				// traverse to the rightmost node in the left subtree
				while (prev->right) {
					prev = prev->right;
				}
				// link the rightmost node to the currents left
				prev->right = curr->right;
				// and push current to the next
				curr->right = curr->left;
				curr->left = NULL;
			}
			curr = curr->right;
		}
		return root;
	}
};