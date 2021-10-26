/* Given a list of integers nums, return the length of the shortest sublist that you can remove such that the resulting list is in ascending order.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [1, 1, 3, 5, 4, 2, 1, 9]
Output
3
Explanation
If we remove [4, 2, 1], then the list would be sorted in ascending order: [1, 1, 3, 5, 9]. */

int solve(vector<int>& nums) {
  int n = nums.size();

  // the last element of the non-decreasing prefix
  if(n == 0) return 0;
  int i = 0;
  int j = n - 1;

  while(i < j and nums[i] <= nums[i + 1]){
    i++;
  }

  if(i == n - 1) return 0;

  while(j > i and nums[j] >= nums[j - 1]) {
    j--;
  }

  int left = 0;
  int right = j;

  int ret = min(n - 1 - i, j);

  while(left <= i and right < n){
    if(nums[left] <= nums[right]){
      ret = min(ret, right - left - 1);
      left++;
    }else{
      right++;
    }
  }

  return ret;
}
