/* You are given a list of non-negative integers prices representing the daily stock prices of a company in chronological order. Return a list of the same length where the value at index i is the minimum number of days you would have to wait until you make a profit. If there's no way to make a profit the value should be 0.

Constraints

n ≤ 100,000 where n is the length of prices
Example 1
Input
prices = [3, 2, 4, 8, 6, 5]
Output
[2, 1, 1, 0, 0, 0] */


vector<int> solve(vector<int>& prices) {
  int n = prices.size();

  vector<int> ans(n);

  if(n == 0) return ans;

  stack<int> s;
  s.push(0);

  for(int i = 1; i < n; i++){

    if(prices[i] <= prices[s.top()]){
      s.push(i);
      continue;
    }

    while(!s.empty() && prices[i] > prices[s.top()]){
      ans[s.top()] = i - s.top();
      s.pop();
    }

    s.push(i);
  }

  while(!s.empty()){
    ans[s.top()] = 0;
    s.pop();
  }

  return ans;
}