class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        vector<int>dp(n), temp(n);
        for(int col = 0; col < tri[n-1].size(); col++){
            dp[col] = tri[n-1][col];
        }
        for(int row = n-2; row >= 0; row--){
            for(int col = 0; col < tri[row].size(); col++){
                temp[col] = tri[row][col] + min(dp[col], dp[col+1]);
            }
            dp = temp;
        }
        return dp[0];
    }
};
