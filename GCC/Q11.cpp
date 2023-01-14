#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve() {
  long long int stock;
  cin >> stock;
  if (stock % 2 != 0) {
    cout << "SELL" << endl;
    return;
  }
  if ((stock / 2) % 2 != 0) {
    cout << "PASS" << endl;
    return;
  }
  cout << "BUY" << endl;
}

int main() {
  int32_t test = 1;
  while (test--) {
    solve();
  }
  return 0;
}