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
    vector<int> topViewBinaryTree(TreeNode* root) {
        
        map<int, int> mp;

        // { node, vertical level }
        queue<pair<TreeNode* ,int>> q;

        vector<int> ans;
        q.push({ root, 0 });

        while(!q.empty()) {
            auto top = q.front();
            TreeNode* node = top.first;

            q.pop();

            int ver = top.second;

            if(mp.find(ver) == mp.end()) {
                mp[ver] = node->val;
            }

            if(node->left != NULL) {
                q.push({ node->left, ver - 1 });
            }
            if(node->right != NULL) {
                q.push({ node->right, ver + 1 });
            }
        }

        for(auto i : mp) {
            ans.push_back(i.second);
        }

        return ans;
    }
};