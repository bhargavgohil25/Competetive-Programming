int maxProfit(vector<int> &prices, int k) {
	int n = prices.size();
	// int profit[k + 1][n + 1];
	vector<vector<int>> profit(k + 1, vector<int>(n + 1));
	for (int i = 0; i <= k; i++) {
		profit[i][0] = 0;
	}
	for (int i = 0; i <= n; i++) {
		profit[0][i] = 0;
	}
	for (int i = 1; i <= k; i++) {
		int prevMaxProfit = INT_MIN;
		for (int j = 1; j < n; j++) {
			prevMaxProfit = max(prevMaxProfit, profit[i - 1][j - 1] - prices[j - 1]);
			profit[i][j] = max(profit[i][j - 1], prices[j] + prevMaxProfit);
		}
	}
	return profit[k][n - 1];
}



int maxProfit(vector<int> &prices, int k) {
	int n = prices.size();
	// [day][buy][cap]
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

	for (int day = n - 1; day >= 0; day--) {
		for (int buy = 0; buy <= 1; buy++) {
			for (int cap = 1; cap <= k; cap++) {

				if (buy == 1) {
					dp[day][buy][cap] = max(-prices[day] + dp[day + 1][0][cap], 0 + dp[day + 1][1][cap]);
				} else {
					dp[day][buy][cap] = max(prices[day] + dp[day + 1][1][cap - 1], 0 + dp[day + 1][0][cap]);
				}

			}
		}
	}

	return dp[0][1][k];
}