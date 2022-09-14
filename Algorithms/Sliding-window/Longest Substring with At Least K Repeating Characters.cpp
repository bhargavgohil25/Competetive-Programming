class Solution {
public:
    int ans = 0;
    
    int solve(string &s, int k, int& uniqueChars) {
        
        int i = 0;
        int j = 0; 
        int numK = 0;
        int currUnique = 0;
        int cnt = 0;
        
        unordered_map<char, int> mp;
        
        while(j < s.length()) {
            // increment the currUnique on finding a unique character
            if(!mp[s[j]]) currUnique++;
            mp[s[j]]++;
            
            // if the freq of that character is equal to K increment numK
            if(mp[s[j]] == k) numK++;
            j++;
            
            // slide the left window until currUnique is not less than uniqueChars
            while(currUnique > uniqueChars) {
                // decrement the number of Characters with atleast K count 
                // if freq of that character is equal to K
                if(mp[s[i]] == k) numK--;
                mp[s[i]]--;
                
                // if the count of that character is less than 0 then decrement currUnique
                if(!mp[s[i]]) currUnique--;
                i++;
            }
            
            // if the currUnique is equals to numK 
            if(currUnique == numK) {
                cnt = max(cnt, j - i);
            }
            
        }
        
        return cnt;
    }
    
    int longestSubstring(string s, int k) {
        int n = s.length();
        
        for(int unique = 1; unique <= 26; unique++) {
            ans = max(ans, solve(s, k, unique));
        }
        
        return ans;
    }
};