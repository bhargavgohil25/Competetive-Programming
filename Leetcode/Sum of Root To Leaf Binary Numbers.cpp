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
    vector<int>nums;
    void arrayToInteger(int path[], int pathlen){
        int output = 0;
        int power = 1;
        for(int i=0;i<pathlen;i++){
            output += path[(pathlen-1) - i] * power;
            power *= 2;
        }
        nums.push_back(output);
    }
    
    void findAllPaths(TreeNode * root, int path[], int pathlen){
        if(root == NULL) return;
        path[pathlen] = root->val;
        pathlen++;
        if(root->left == NULL and root->right == NULL){
            arrayToInteger(path,pathlen);
        }else{
            findAllPaths(root->left,path,pathlen);
            findAllPaths(root->right,path,pathlen);
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int path[1001];
        int ans = 0;
        findAllPaths(root,path,0);
        for(int i=0;i<nums.size();i++){
            ans += nums[i];
        }
        return ans;
    }
};