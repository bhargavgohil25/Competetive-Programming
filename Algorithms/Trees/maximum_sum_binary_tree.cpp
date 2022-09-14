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
    
    /*
        Explaination : https://www.youtube.com/watch?v=WszrfSwMz58&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=18&t=81s
        
        (medium - hard)
        
        usage of maximum height sum and maximum diameter concept....
        
    */
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        
        return maxi;
    }
    
    int maxPathDown(TreeNode* root, int& maxi) {
        if(root == NULL) return 0;
        
        int left = max(0, maxPathDown(root->left, maxi));
        int right = max(0, maxPathDown(root->right, maxi));
        
        maxi = max(maxi, left + right + root->val);
        
        return root->val + max(left, right);
    }
};