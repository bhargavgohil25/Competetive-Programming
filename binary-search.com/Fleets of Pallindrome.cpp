/* Given a lowercase alphabet string s and an integer k, return whether we can create k palindromes using all characters in s.

Constraints

0 ≤ n ≤ 100,000 where n is length of s.
Example 1
Input
s = "racelevelcar"
k = 2
Output
true
Explanation
We can make "racecar" and "level"

Example 2
Input
s = "dog"
k = 2
Output
false
Explanation
We can't make any 2-letter palindromes with the letters given.

Example 3
Input
s = "dog"
k = 3
Output
true
Explanation
Each letter is a palindrome: "d", "o", "g". */

bool solve(string s, int k) {
  // Two conditions when it is possible


  // Create a Hash Table : 
  // Store the Frequency of all the characters,
  // Count number of Odd and Even frequencies

  // 1) If all the characters Freq. are Even and 1 <= K <= N, then it is possible
  // 2) If there are some odd Freq. say (odd_cnt) and odd_cnt <= K <= N, then it is possible 


  // why is that so ? because every odd number of character make one pallindrome for sure
  // and remaining characters can make a single character pallindrome....

  // For eg : 
  /*
    a = 3
    b = 3
    c = 3
    d = 3
    e = 2

    we have odd_cnt = 4 even_cnt = 2
    so, when we have to make pallindrome from 'a' and 'b' there are two ways and both will make only 2 pallindrome
    like if we make 
    "aaa" and "bbb" ----> count 2
    "baaab" and "ebe"

    so, we can say that to utilise all the odd freq characters we hve to use them all

  */

  int n = s.length();
  int odd_cnt = 0;
  int even_cnt = 0;
  map<char, int> mp;
  for(int i = 0; i < n; i++){
    mp[s[i]]++;
  }
  bool no_odd = true;
  for(auto i : mp){
    if(i.second % 2){
      odd_cnt++;
      no_odd = false;
    }
    else even_cnt++; 
  }

  if(no_odd == true and k >=1 and k <= n){
    return true;
  }else{
    if(k >= odd_cnt and k <= n){
      return true;
    }
  }

  return false;
}