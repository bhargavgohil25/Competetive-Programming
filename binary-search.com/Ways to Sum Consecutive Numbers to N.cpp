/* Given an integer n, return the number of lists of non-negative consecutive numbers that sum up to n.

Constraints

0 ≤ n < 2 ** 31
Example 1
Input
n = 9
Output
3
Explanation
The possible lists are: [2, 3, 4], [4, 5], and [9] */

int solve(int N) {

  // https://www.geeksforgeeks.org/count-ways-express-number-sum-consecutive-numbers/
  int chain_length = 0;
  int sum = 0;
  while(sum < N){
    chain_length++;
    sum += chain_length;
  }
  // chain length can also be like 
  // L * (L + 1) < 2 * N
  int count = 0;
  for (long int L = 1; L < chain_length; L++) {
    double a = (1.0 * N - (L * (L + 1)) / 2) / (L + 1);
    if (a - (int)a == 0.0) count++;
  }
  return count + 1;
}

