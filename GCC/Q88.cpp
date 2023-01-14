#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve() {
	int n, k;
	cin >> k >> n;
	vector<int> prices(n);
	for (int i = 0; i < n; i++) cin >> prices[i];

	vector<int> buy(k, INT_MIN);
	vector<int> sell(k, 0);

	for (int i = 0; i < n; i++) cin >> prices[i];

	if (k == 0) {
		cout << 0 << endl;
		return;
	}

	int res = 0;
	if (k >= n / 2) {
		for (int i = 1; i < n; i++) {
			res += max(prices[i] - prices[i - 1], 0);
		}
		cout << res << endl;
		return;
	}


	for (int price : prices) {
		for (int i = 0; i < k; ++i) {
			buy[i] = max(buy[i], (i > 0 ? sell[i - 1] : 0) - price);
			sell[i] = max(sell[i], buy[i] + price);
		}
	}

	cout << sell[sell.size() - 1] << endl;

}

int main() {
	int test = 1;
	while (test--) {
		solve();
	}
	return 0;
}