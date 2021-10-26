/*
You are given a list blocks where each block contains two integers [start, end] where start < end. You can join two blocks if the end of one is equal to the start of another. Return the length of the longest chain of blocks.

Constraints

0 ≤ n ≤ 100,000 where n is the length of blocks.
Example 1
Input
blocks = [
    [3, 4],
    [4, 5],
    [3, 7],
    [0, 1],
    [1, 3]
]
Output
4
Explanation
We can form the following chain: [0, 1], [1, 3], [3, 4], [4, 5]
*/

int solve(vector<vector<int>>& blocks) {
  int n = blocks.size();
  sort(blocks.begin(), blocks.end(), [&](auto &a, auto &b) { return a[0] < b[0];});
  unordered_map<int,int>dp;
  // vector<int> dp(1000001,0)/\;
  int ans = INT_MIN;
  if(n == 0) return 0;
  if(n == 1) return 1;
  for(int i = 0; i < n; i++){
    dp[blocks[i][1]] = max(dp[blocks[i][0]] + 1, dp[blocks[i][1]]);
    ans = max(ans, dp[blocks[i][1]]);
  }
  return ans;
}