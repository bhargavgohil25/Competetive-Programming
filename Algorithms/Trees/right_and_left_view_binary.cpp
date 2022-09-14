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
class Solution {
public:

    void getRightView(TreeNode* root, vector<int>& ans, int level) {
        if(root == NULL) return;

        if(level == ans.size()) {
            ans.push_back(root->val);
        }

        getRightView(root->right, ans, level + 1);
        getRightView(root->left,  ans, level + 1);
        
    }

    void getLeftView(TreeNode* root, vector<int>& ans, int level) {
        if(root == NULL) return;

        if(level == ans.size()) {
            ans.push_back(root->val);
        }

        getLeftView(root->left,  ans, level + 1);
        getLeftView(root->right, ans, level + 1);
    }    

    vector<int> rightAndLeftViewTree(TreeNode* root) {
        
        /*
            for right view:

            The main idea here is that we need to know the value of the 
            last node in every level

            for left view:
            The main idea here is that we need to know the value of the
            first node in every level

            so, the main point here is that the size of the ans will be equal to number of levels in bin tree.
    
            we will use a recursive solution for this...
        */

        vector<int> ans;

        /* 
            use any function you need
        */
        getRightView(root, ans, 0);
        getLeftView(root, ans, 0);

        return ans;

    }
};