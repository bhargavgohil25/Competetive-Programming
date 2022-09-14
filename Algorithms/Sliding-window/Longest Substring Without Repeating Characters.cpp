class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int ans = 0;
        vector<int> cnt(128, 0);
        
        int duplicates = 0;
        
        while(j < n) {
            cnt[s[j]]++;
            duplicates += (cnt[s[j]] == 2);
            j++;
            if(duplicates) {
                cnt[s[i]]--;
                duplicates -= (cnt[s[i]] == 1);
                i++;
            }
        }
        
        return j - i;
    }
};