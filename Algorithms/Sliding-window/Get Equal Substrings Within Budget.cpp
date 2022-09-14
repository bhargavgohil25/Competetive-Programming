class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        
        int i = 0;
        int j = 0;
        int cnt = 0;
        int ans = 0;
        
        // Non-shrinkable sliding window
        while(j < n) {
            cnt += abs(s[j] - t[j]);
            j++;
            if(cnt > maxCost) {
                cnt -= abs(s[i] - t[i]);
                i++;
            }
        }
        
        return j - i;
    }
};