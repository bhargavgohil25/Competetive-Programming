/* You are given a list of integers nums and integers size and k. Consider an operation where we take a contiguous sublist of length size and increment every element by one.

Given that you can perform this operation k times, return the largest minimum value possible in nums.

Constraints

n ≤ 100,000 where n is the length of nums
k < 2 ** 31
Example 1
Input
nums = [1, 4, 1, 1, 6]
size = 3
k = 2
Output
2
Explanation
We can increment [1, 4, 1] to get [2, 5, 2, 1, 6] and then increment [5, 2, 1] to get [2, 6, 3, 2, 6]. */



bool possible(long long int val, int size, vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long int> used(n + 1);
    long long int ans = 0;
    long long int inc = 0;
    for (int i = 0; i < n; i++) {
        if (i >= size) {
            inc -= used[i - size];
        }
        used[i] = max(0ll, val - nums[i] - inc);
        inc += used[i];
        ans += used[i];
    }
    return (ans <= k);
}

int solve(vector<int>& nums, int size, int k) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    long long int mini = 1e17, maxi = 0;
    for (int i = 0; i < n; i++) {
        mini = min(mini, nums[i] * 1ll);
        maxi = max(maxi, nums[i] * 1ll);
    }
    long long int start = mini, end = maxi + k;
    int ans = 0;
    while (start <= end) {
        long long int mid = (start + end) / 2;
        if (possible(mid, size, nums, k)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

