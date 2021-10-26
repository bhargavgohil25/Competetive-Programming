/* You are given a list of integers nums where each value represents a group of people looking to skydive together. You are also given k representing the number of days the skydiving facility is open for.

Return the minimum capacity of the plane you need to be able to fulfill all requests in k days. Note that requests should be fulfilled in the order they were given and a plane can only have one flight per day.

Constraints

n ≤ 10,000 where n is the length of nums.
Example 1
Input
nums = [13, 17, 30, 15, 17]
k = 3
Output
32
Explanation
A 32 person airplane can group the requests by [13, 17], [30], [15, 17]. */


bool check(vector<int>& nums, int mid, int k){
  int cnt = 1;

  int i = 0;
  int sum = 0;
  while(i < nums.size()){
    if(sum + nums[i] <= mid){
      sum += nums[i];
    }else{
      cnt++;
      sum = nums[i];
    }
    if(nums[i] > mid) return false;
    i++;
  }

  return cnt <= k;

}

int solve(vector<int>& nums, int k) {
  int n = nums.size();

  // Binary search on the number of people 
  int tot = accumulate(nums.begin(), nums.end(), 0);
  int low = 0;
  int high = tot;

  while(low < high){
    int mid = low + (high - low)/2;
    // int mid = (high + low)/2;
    if(check(nums, mid, k)){
      high = mid;
    }else{
      low = mid + 1;
    }
  }

  return high;
}
