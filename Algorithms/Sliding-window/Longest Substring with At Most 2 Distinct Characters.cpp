int solve(string s) {
  int n = s.length();

  int i = 0;
  int j = 0;
  vector<int>cnt(256, 0);
  int unique = 0;
  int ans = 0;

  while(j < n and i < n) {
    unique += (cnt[s[j] - 'a'] == 0);
    cnt[s[j] - 'a']++;
    while(unique > 2) {
      cnt[s[i] - 'a']--;
      unique -= (cnt[s[i] - 'a'] == 0);
      i++;
    }
    // cout << j << ' ' << i << endl;
    ans = max(ans, j - i + 1);
    j++;
  }

  return ans;
  // return j - i + 1;
}