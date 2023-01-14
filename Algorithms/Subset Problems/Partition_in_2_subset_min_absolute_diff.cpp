class Solution {
public:
    int minimumDifference(vector<int>& arr) {
        // Your code goes here
        int sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        /*
            dp[i][j] simply means upto index i elements can we create sum j ?
        */

        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        // it is possible to create a sum 0 with all possible number of elements i.e by not taking any of them
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        if (arr[0] <= sum) {
            dp[0][arr[0]] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= sum; j++) {
                // not take
                dp[i][j] = dp[i - 1][j];

                // take
                if (arr[i] <= j) {
                    dp[i][j] = dp[i][j] | dp[i - 1][j - arr[i]];
                }
            }
        }

        int mini = INT_MAX;
        for (int j = 0; j <= sum; j++) {
            if (dp[n - 1][j]) {
                int s1 = j;
                int s2 = sum - j;
                mini = min(mini, abs(s2 - s1));
            }
        }
        return mini;
    }
};