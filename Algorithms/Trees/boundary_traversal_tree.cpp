/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: a TreeNode
     * @return: a list of integer
     */
    void getLeftNodes(TreeNode* root, vector<int>& ans){
        if(root->left == NULL and root->right == NULL) {
            return;
        }

        ans.push_back(root->val);
        if(root->left != NULL and (root->left->left or root->left->right)){
            getLeftNodes(root->left, ans);
        }
        if(root->left == NULL and root->right != NULL) {
            getLeftNodes(root->right, ans);
        }

    }

    void getLeafNodes(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return;

        if(root->left == NULL and root->right == NULL) {
            ans.push_back(root->val);
        }

        getLeafNodes(root->left, ans);
        getLeafNodes(root->right, ans);
    }

    void getRightNodes(TreeNode* root, vector<int>& ans) {
        if(root->left == NULL and root->right == NULL) {
            return;
        }
        ans.push_back(root->val);
        if(root->right != NULL and (root->right->right or root->right->left)) {
            getRightNodes(root->right, ans);
        }
        if(root->right == NULL and root->left != NULL) {
            getRightNodes(root->left, ans);
        }
    }

    vector<int> boundaryOfBinaryTree(TreeNode * root) {
        // write your code here
        vector<int> ans;
        vector<int> forRight;

        if(root == NULL) return ans;

        ans.push_back(root->val);
        // get the left boundary without leafs
        getLeftNodes(root, ans);
        // get the leafs node
        getLeafNodes(root, ans);
        // get the right boundary in reverse order
        getRightNodes(root, ans);

        return ans;
    }
};