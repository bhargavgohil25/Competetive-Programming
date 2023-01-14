/*
Given a set of non-negative integers, and a value sum,
determine if there is a subset of the given set with sum equal to given sum.

Example:

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True
There is a subset (4, 5) with sum 9.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
There is no subset that add up to 30.
*/


#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

vector<vector<int>> dp;

bool isSubsetSum(vector<int>&a, ll n, ll sum) {
	// Base Cases
	if (sum == 0) return true;
	if (n == 0) return false;

	if (dp[n][sum] != -1)

		// if the last element is greater than sum then ignore that element and move to the next
		if (a[n - 1] > sum) return isSubsetSum(a, n - 1, sum);

	// try both possibilities of not taking that number and by taking that number.
	return dp[n][sum] = isSubsetSum(a, n - 1, sum) || isSubsetSum(a, n - 1, sum - a[n - 1]);
}

int main() {

	ll n, sum;
	cin >> n >> sum;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	dp.resize(n, vector<int>(sum, -1));

	bool flag = isSubsetSum(a, n, sum);
	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}