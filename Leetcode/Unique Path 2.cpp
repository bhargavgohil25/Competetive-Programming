class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         dp[i][j] = 0;
        //     }
        // }
        for(int i=0;i<n;i++){
            if(grid[i][0] != 1){
                dp[i][0] = 1;
            }else{
                dp[i][0] = 0;
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i] != 1){
                dp[0][i] = 1;
            }else{
                dp[0][i] = 0;
                break;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j] != 1){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[n-1][m-1];
    }
};