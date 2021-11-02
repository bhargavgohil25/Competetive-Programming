/* You are given a unique two-dimensional list of integers points where each element points[i] contains (x, y) representing a Cartesian coordinate.

For each point i in points, return the shortest Manhattan distance to a different point that is either in the same y coordinate or the same x coordinate.

You can assume that every point has some other point that either share the same x or y coordinate.

Constraints

0 ≤ n ≤ 100,000 where n is the length of points
Example 1
Input
points = [
    [5, 5],
    [5, 9],
    [4, 4],
    [4, 30]
]
Output
[4, 4, 26, 26]
Explanation
The closest point from (5, 5) that shares a coordinate is (5, 9). The closest point from (4, 4) that shares a coordinate is (4, 30) */

void calc(unordered_map <int,vector<pair<int,int>>> &m, vector<int>&ret) {
  for (auto & [x, nums]: m) {
    for (int i = 1; i < nums.size(); i++) {
      int manh = nums[i].first - nums[i - 1].first;

      int idx1 = nums[i].second, idx2 = nums[i - 1].second;

      ret[idx1] = min(ret[idx1], manh);
      ret[idx2] = min(ret[idx2], manh);
    }
  }
}

vector <int> solve(vector <vector<int>>&nums) {
  int n = nums.size();

  vector<int> ret(n, 1e9);

  unordered_map<int,vector<pair<int,int>>> x, y;

  for (int i = 0; i < nums.size(); i++) {
    x[nums[i][0]].push_back({ nums[i][1], i});
    y[nums[i][1]].push_back({ nums[i][0], i});
  }

  for (auto & [num, arr]: x) sort(arr.begin(), arr.end());

  for (auto & [num, arr]: y) sort(arr.begin(), arr.end());

  calc(x, ret);

  calc(y, ret);

  return ret;
}


