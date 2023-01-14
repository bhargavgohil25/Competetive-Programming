class Solution {
public:

    int solve(vector<int>& arr, int i, vector<vector<int>>& dp, int target) {
        if (target == 0) return 1;
        if (i == 0) return arr[i] == target;

        if (dp[i][target] != -1) {
            return dp[i][target];
        }

        int not_take = solve(arr, i - 1, dp, target);

        int take = 0;

        if (arr[i] <= target) {
            take = solve(arr, i - 1, dp, target - arr[i]);
        }

        return dp[i][target] = take + not_take;
    }

    int countSubsetsWithSumK(vector<int>& arr, int target) {
        // Your code goes here
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return solve(arr, n - 1, dp, target);
    }
};