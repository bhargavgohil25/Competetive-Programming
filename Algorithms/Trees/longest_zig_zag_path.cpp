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
        1 --> right
        0 --> left
    */

    int ans = 0;

    void recur(TreeNode* root, int dir, int count) {
        if (!root) return;

        ans = max(ans, count);

        if (dir == 0) {
            recur(root->left, 1, count + 1);
            recur(root->right, 0, 1);
            return;
        }
        if (dir == 1) {
            recur(root->right, 0, count + 1);
            recur(root->left, 1, 1);
            return;
        }
    }

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;

        recur(root->left, 1, 1);
        recur(root->right, 0, 1);
        return ans;
    }
};