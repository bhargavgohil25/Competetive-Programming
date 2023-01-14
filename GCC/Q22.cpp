#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    unordered_map<int, int> mp;
    int ans = 0;

    for (auto c : s) mp[c - 'a']++;

    int flag = 1;

    for (auto it : mp) {
        if (it.second % 2) {
            ans += it.second - 1;
        }
        else {
            flag = 1;
            ans += it.second;
        }
    }

    ans += flag;
    cout << ans << endl;
}

int main() {
    int test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}