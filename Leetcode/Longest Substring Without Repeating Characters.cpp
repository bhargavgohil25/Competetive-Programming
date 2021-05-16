class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int>vis(256,-1);  
        int max_len = 0;
        int cnt = 0;
        int i = 0,j = 0;
        while(i < n and j < n){
            if(vis[s[i]] == -1){
                vis[s[i]] = 1;
                i++;
                cnt++;
            }else{
                vis[s[j]] = -1;
                j++;
                cnt--;
            }
            max_len = max(max_len,cnt);
        }
        return max_len;
    }
};