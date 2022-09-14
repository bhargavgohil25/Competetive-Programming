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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        bool level = 1;
        
        vector<vector<int>> res;
        
        if(!root) return res;
        
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            deque<int> tmp;
            
            while(sz--){
                auto ele = q.front();
                
                q.pop();
                level ? tmp.push_back(ele->val) : tmp.push_front(ele->val);
                
                
                if(ele->left)
                    q.push(ele->left);
                if(ele->right)
                    q.push(ele->right);
            }
            
            res.push_back(vector<int>(tmp.begin(),tmp.end()));
            level ^= 1;
        }
        return res;
    }
};








