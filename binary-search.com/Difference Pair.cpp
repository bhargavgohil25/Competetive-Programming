/* Given a list of integers nums, find a pair i < j, such that nums[i] + nums[j] + (i - j) is maximized, and return the value.

Constraints

n ≤ 100,000 where n is the length of nums.
Example 1
Input
nums = [5, 5, 1, 1, 1, 7]
Output
9
Explanation
Picking the two 5 is the best since its score is 5 + 5 + 0 - 1 = 9.

If we had picked the rightmost 5 with the 7 we'd get 5 + 7 + (1 - 5) = 8 */

int solve(vector<int>& nums) {
  int ans = 0;
  int n = nums.size();
  int curr_max = nums[0] + 0;
  for(int i = 1; i < n; i++){
    ans = max(ans, (curr_max + (nums[i] - i)));
    curr_max = max(nums[i] + i, curr_max);
  }
  return ans;
}

