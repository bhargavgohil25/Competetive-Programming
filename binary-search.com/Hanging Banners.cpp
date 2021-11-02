/* You are given a list of list of integers intervals of the form [start, end] representing the starts and end points of banners you want to hang. Each banner needs at least one pin to stay up, and one pin can hang multiple banners. Return the smallest number of pins required to hang all the banners.

Note: The endpoints are inclusive, so if two banners are touching, e.g. [1, 3] and [3, 5], you can put a pin at 3 to hang both of them.

Constraints

n ≤ 100,000 where n is the length of intervals
Example 1
Input
intervals = [
  [1, 4],
  [4, 5],
  [7, 9],
  [9, 12]
]
Output
2
Explanation
You can put two pins at 4 and 9 to hang all the banners.. */

int solve(vector<vector<int>>& intervals) {
  // Sort the intervals in the increasing order acc to the second value
  int n = intervals.size();

  sort(intervals.begin(), intervals.end(), [&](auto &a, auto &b) { return a[1] < b[1]; });

  int ans = 1;

  int currentPinned = intervals[0][1];

  for(int i = 1; i < n; i++){
    if(intervals[i][0] > currentPinned){
      ans++;
      currentPinned = intervals[i][1];
    }
  }

  return ans;
}