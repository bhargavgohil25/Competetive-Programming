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
		children sum property means, every node must follow

		node val = left node val + right node val
										and
		you can increment any node val by (+1) any number of times

	*/
	void changeTreeToChildrenSumTree(TreeNode* root) {
		if (root == NULL) return;

		int child = 0;

		if (root->left) child += root->left->val;
		if (root->right) child += root->right->val;

		if (child >= root->val) {
			root->val = child;
		} else {
			root->left->val = root->val;
			root->right->val = root->val;
		}

		changeTreeToChildrenSumTree(root->left);
		changeTreeToChildrenSumTree(root->right);

		int tot = 0;

		if (root->left) tot += root->left->val;
		if (root->right) tot += root->right->val;

		if (root->left || root->right) root->val = tot;
	}
};