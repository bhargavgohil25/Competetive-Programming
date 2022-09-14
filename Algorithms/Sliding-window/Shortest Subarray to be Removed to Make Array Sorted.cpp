class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& nums) {
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
};