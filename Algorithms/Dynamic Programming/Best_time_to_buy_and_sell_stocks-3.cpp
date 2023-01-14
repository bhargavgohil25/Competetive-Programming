
// Using Recursion + Memoization
int recursion(int day, vector<int>& prices, int tl, vector<vector<int>>& dp) {

	if (day >= prices.size() or tl == 0) return 0;

	if (dp[day][tl] != -1) return dp[day][tl];

	int no_transaction = recursion(day + 1, prices, tl, dp);

	int transaction_price;

	// Buy
	if (tl % 2 == 0) {
		transaction_price = -prices[day] + recursion(day + 1, prices, tl - 1, dp);
	} else { // Sell
		transaction_price = prices[day] + recursion(day + 1, prices, tl - 1, dp);
	}

	return dp[day][tl] = max(no_transaction, transaction_price);
}

int maxProfit(vector<int> &prices) {
	// add you logic here
	int n = prices.size();

	int transaction_limit = 4;

	vector<vector<int>> dp (n, vector<int>(5, -1));

	return recursion(0, prices, transaction_limit, dp);

}

// Iterative Way



int maxProfit(vector<int> &prices) {
	int n = prices.size();
	vector<int> left_max_profit(n, 0), right_max_profit(n, 0);

	// store the left max profit and right max profit

	// For left max profit
	int min_price = prices[0];
	for (int i = 1; i < n; i++) {
		min_price = min(min_price, prices[i]);
		left_max_profit[i] = max(left_max_profit[i - 1], prices[i] - min_price);
	}

	// For right max profit
	int max_price = prices[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		max_price = max(max_price, prices[i]);
		right_max_profit[i] = max(right_max_profit[i + 1], max_price - prices[i]);
	}

	int profit = 0;
	for (int i = 0; i < n; i++) {
		profit = max(profit, left_max_profit[i] + right_max_profit[i]);
	}

	return profit;
}






