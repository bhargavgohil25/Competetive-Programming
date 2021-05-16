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
    TreeNode* dfs(TreeNode* root1, TreeNode* root2, TreeNode *ans){
        int x = 0;
        if(root1 != NULL){
            x += root1->val;
        }
        if(root2 != NULL){
            x += root2->val;
        }
        ans-> val = x;
        if((root1 and root1->left) || (root2 && root2->left)){
            ans->left = new TreeNode(0);
            dfs(root1 ? root1->left : NULL, root2 ? root2->left : NULL, ans->left);
        }
        if((root1 and root1->right) || (root2 && root2->right)){
            ans->right = new TreeNode(0);
            dfs(root1 ? root1->right : NULL, root2 ? root2->right : NULL, ans->right);
        }
        return ans;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode *ans = new TreeNode(0);
        if(!root1 && !root2) return NULL;
        return dfs(root1,root2,ans);    
    }
};