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

	/*
	  Inorder and Preorder traversal using morris traversal
	*/

	vector<int> morris_traversal(TreeNode* root) {
		vector<int> inorder;
		TreeNode* curr = root;

		while (curr != NULL) {
			if (curr->left == NULL) {
				inorder.push_back(cur->val);
				// here it means that, if there is already a
				// link to then connect curr
				// means to the root again
				curr = curr->right;
			} else {
				// we will now create a new node that will be the last node in the left subtree
				// basically the righmost node in the left subtree
				TreeNode* prev = curr->left;

				while (prev->right != NULL and prev->right != curr) {
					prev = prev->right;
				}
				// there can be 2 cases on finding the rightmost node

				// 1) the node is NULL
				if (prev->right == NULL) {
					// means its not pointed to root or curr
					// we will then make a link to them
					prev->right = curr;
					// for further traversal
					curr = curr->left;
				} else {
					prev->right = NULL;
					inorder.push_back(curr->val);
					// for further traversal
					curr = curr->right;
				}
			}
		}
		return inorder;
	}
};

