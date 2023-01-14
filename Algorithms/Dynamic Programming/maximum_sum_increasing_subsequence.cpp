int maxSumIS(int nums[], int n)  {
    // Your code goes here
    // int dp[n + 1];
    // dp[0] = 1;
    // int ans  = -1;
    // for(int i = 1; i <= n; i++) {
    //     dp[i] = -1;
    //     for(int j = i-1; j >= 0; j--){
    //         if(j == 0) dp[i] = max(dp[i], nums[i-1]);
    //         else if( nums[i-1] > nums[j-1]) dp[i] = max(dp[i], dp[j]+nums[i-1]);
    //     }
    //     ans = max( dp[i], ans);
    // }
    // return ans;

    int ans = 0;
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        dp[i] = nums[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                // ham ya to koi na le ya to fir
                // nums[i] aur dp[j] tk jo he unhe le
                dp[i] = max(dp[i], nums[i] + dp[j]);
            }
        }
    }
    ans = *max_element(dp.begin(), dp.end());
    return ans;
}