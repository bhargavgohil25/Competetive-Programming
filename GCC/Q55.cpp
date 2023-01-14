#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

void solve() {
	ll cut, n;
	cin >> cut >> n;
	vector<ll> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];

	ll ans = 0, st = 0, en = 0, cum_sum = nums[0];

	while (st < n and en < n) {
		// if cum sum is less than cutoff then increase cum sum by increasing the
		// the end pointer
		// and later check if end is greater then start or not
		// if, then add to answer
		// else increase the sum...


		if (cum_sum >= cut) {
			cum_sum -= nums[st];
			st++;
		} else {
			en++;
			if (en >= st) {
				ans += (en - st);
			}
			if (en < n) {
				cum_sum += nums[en];
			}
		}
	}

	cout << ans << ' ';
}

int main() {
	ll test = 1;
	while (test--) {
		solve();
	}
	return 0;
}