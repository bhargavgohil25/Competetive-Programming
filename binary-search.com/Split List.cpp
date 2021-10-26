/* Given a list of integers nums, return whether you can partition the list into two non-empty sublists such that every number in the left sublist is strictly less than every number in the right sublist.

Constraints

n ≤ 100,000 where n is the length of nums.
Example 1
Input
nums = [5, 3, 2, 7, 9]
Output
true
Explanation
We can split the list into left = [5, 3, 2] and right = [7, 9] */


bool solve(vector<int>& nums) {
  int n = nums.size();
  vector<int> minSuff(n);
  vector<int> maxPref(n);

  minSuff[n - 1] = nums[n - 1];

  for(int i = n - 2; i >= 0; i--){
    minSuff[i] = min(minSuff[i + 1], nums[i]);
  }

  maxPref[0] = nums[0];

  for(int i = 1; i < n; i++){
    maxPref[i] = max(nums[i], maxPref[i - 1]);
  }

  for(int i = 1; i < n; i++){
    if(minSuff[i] > maxPref[i - 1]){
      return true;
    }
  }

  return false;

}