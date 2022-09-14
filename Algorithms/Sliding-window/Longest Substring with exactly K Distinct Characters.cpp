/*

Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.
*/

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int n = s.length();
        unordered_set<char>st;
        for(auto i : s) st.insert(i);
        if(st.size() < k) return -1;
        
        int i = 0;
        int j = 0;
        
        int ans = -1;
        int unique = 0;
        vector<int>cnt(26, 0);
        // unordered_map<char, int> cnt;
        
        while(i < n and j < n) {
            unique += (cnt[s[j] - 'a'] == 0 ? 1 : 0);
            
            cnt[s[j] - 'a']++;
            
            if(unique > k) {
                cnt[s[i] - 'a']--;
                if(cnt[s[i] - 'a'] == 0) unique--;
                i++;
            }
            
            j++;
        }
        return j - i;
    }
};