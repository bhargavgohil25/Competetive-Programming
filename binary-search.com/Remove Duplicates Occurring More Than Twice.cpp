/* Given a list of integers nums sorted in ascending order, remove in-place duplicates that appear more than twice.

This should be done in \mathcal{O}(1)O(1) space.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [3, 3, 3, 3, 4, 4, 8]
Output
[3, 3, 4, 4, 8]
Explanation
We remove the third and fourth 3 since they occur more than twice. */

vector<int> solve(vector<int>& nums) {
  int n = nums.size();
  if(n == 0) return nums;

  int streak = 1;
  int excess = 0;
  int prev = nums[0];

  for(int i = 1; i < n; i++){
    if(prev == nums[i]){
      streak++;
    }else{
      streak = 1;
      prev = nums[i];
    }

    swap(nums[i], nums[i - excess]);
    if(streak > 2){
      excess++;
    }
  }

  for(int i = 0; i < excess; i++){
    nums.pop_back();
  }

  return nums;
}