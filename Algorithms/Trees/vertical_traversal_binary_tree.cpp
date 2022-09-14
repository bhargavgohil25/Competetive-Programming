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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        


        /*
            imagine the tree, we assume the tree as a x-axis,
            so,                 
                            -3  -2  -1  0   1   2   3

            

            this is representation of map :
            
            vertical level ---> horizontal level ---> { nodes on that level }
            
            for queue :
            
            { root node,  { vertical level, horizontal level } }
            
        */
        
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({ root, { 0, 0 } });
        
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            TreeNode* node = top.first;
            
            int ver = top.second.first;
            int hor = top.second.second;
            
            mp[ver][hor].insert(node->val);
            
            if(node->left) {
                q.push({ node->left, { ver - 1, hor + 1 } });
            }
            if(node->right) {
                q.push({ node->right, { ver + 1, hor + 1 } });
            }
        }
        vector<vector<int>> ans;
        
        for(auto i : mp) {
            vector<int> temp;
            for(auto j : i.second) {
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};