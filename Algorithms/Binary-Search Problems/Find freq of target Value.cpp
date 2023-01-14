/* Given an Array Of integers nums in ascending order, find the frequency of a given target value.
Solve in time complexity of O(log N) */


int n;
vector<int> nums;
int binarySearch(int hi, int lo, int dir, int target) {
  int ans = -1;

  while (lo <= hi) {

    int mid = lo + (hi - lo) / 2;
    cout << "mid : " << mid << ' ' << endl;
    if (nums[mid] == target) {
      // cout << mid << ' ';
      ans = mid;
      if (dir == 1) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
      continue;
    }
    if (nums[mid] > target) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return ans;
}

int solve(vector<int>& nums, int target) {
  int n = nums.size();

  // first get the position of the targeted value from binary search on the array
  int hi = n - 1;
  int lo = 0;
  int leftMost = binarySearch(hi, lo, 1, target);
  int rightMost = binarySearch(hi, lo, 0, target);
  if (leftMost == -1 || rightMost == -1) {
    cout << "No index found" << endl;
    return;
  }
  cout << rightMost << ' ' << leftMost << endl;
  int ans = rightMost - leftMost + 1;

  return ans;
}