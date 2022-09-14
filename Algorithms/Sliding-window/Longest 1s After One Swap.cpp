int solve(string s) {
  int n = s.length();

  int i = 0, j = 0, ans = 0, flips = 1, ones = 0;

  while(j < n) {
    if(s[j] == '0'){
      flips--;
    }else{
      ones++;
    }

    while(flips < 0) {
      flips += (s[i] == '0');
      i++;
    }

    ans = max(ans, j - i + 1);
    j++;
  }

  return min(ans, ones);
}