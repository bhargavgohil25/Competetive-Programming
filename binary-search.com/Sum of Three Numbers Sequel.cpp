/* Given a list of integers nums and an integer k, find three distinct elements in nums, a, b, c, such that abs(a + b + c - k) is minimized and return the absolute difference.

Constraints

n ≤ 1,000 where n is length of nums.
Example 1
Input
nums = [2, 4, 25, 7]
k = 15
Output
2
Explanation
Taking [2, 4, 7] will get us closest to 15 and the absolute difference is abs(13 - 15) = 2 */


int solve(vector<int>& nums, int target) {
  int n = nums.size();

  sort(nums.begin(), nums.end());
  // Tip : For most of the problems like find "3 elements" something, do sorting and start from last index for last element...(depends on the problem statement) 
 
  // First Sort The Array....

  // Two pointer solution :
  // We will set 2 point initially and last point to the end and traverse from the right to left...
  // And check for sum = nums[i] + nums[j] + nums[k] ..... if(abs(sum - target) < temp) temp = abs(sum - target) and ans = sum....
  // in case, if (sum < target) we will increment the 'j' pointer to the right because it will increase the overall sum.. as the array is sorted

  // So the Ans will be sum at which abs(sum - target) is minimum and return (sum -target)......
 
  int ans = 0;
  int tempDiff = INT_MAX;

  for(int first = 0; first < nums.size() - 2; first++){
    int sec = first + 1;

    int third = nums.size() - 1;

    while(sec < third){
      int sum = nums[first] + nums[sec] + nums[third];

      if(abs(sum - target) < tempDiff){
        ans = sum;
        tempDiff = abs(sum - target);
      }
      if(sum > target){
        third--;
      }else{
        sec++;
      }
    }
  }

  return abs(ans - target);

}
