#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll> nums(n);

	for (ll i = 0; i < n; i++) cin >> nums[i];

	// /*
	// 	m = 6
	// 	2 4 3 1 1
	// 	2 4 1 1 3
	// 	2 1 1 4 3
	// 	1 1 2 4 3
	// */

	// bool flag = 1;
	// for (ll i = 1; i < n; i++) {
	// 	if (nums[i - 1] + nums[i] > m && nums[i - 1] > nums[i]) {
	// 		cout << 0 << endl;
	// 		return;
	// 	}
	// }
	// cout << 1 << endl;

	ll maxi = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (nums[i] > maxi) {
			maxi = nums[i];
		}
		else if (nums[i] < maxi and nums[i] + maxi > m) {
			cout << 0 << endl;
			return;
		}
	}
	cout << 1 << endl;

}

int main() {
	ll test = 1;
	// cin >> test;
	while (test--) {
		solve();
	}
	return 0;
}