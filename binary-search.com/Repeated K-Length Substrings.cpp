/* Given a string s and an integer k, return the number of k-length substrings that occur more than once in s.

Constraints

n ≤ 100,000 where n is the length of s.
k ≤ 10
Example 1
Input
s = "abcdabc"
k = 3
Output
1
Explanation
"abc" occurs twice in the string */


int solve(string s, int k) {
    int n = s.length();
    unordered_map<string, int> mp;

    for(int i = 0; i < n - k + 1; i++){
        string curr = "";
        for(int j = i; j < i + k; j++){
            curr += s[j];
        }
        mp[curr]++;
    }
    int ans = 0;

    for(auto &[a, b] : mp){
        if(b > 1){
            ans++;
        }
    }
    return ans;
}