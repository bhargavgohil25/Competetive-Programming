/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int left = 0;
        int right = 0;
        vector<int> freq(26, 0);
        
        while(right < n) {
            freq[s[right] - 'A']++;
            
            int maxi = *max_element(freq.begin(), freq.end());
            
            // when our goal gets invalid..
            // means we want to have maximum freq letter to be in our substring
            // and this if..statements says that
            // (right - left) --> some substring length say subsLen
            // after removing maximum letters from this subsLen we will be left with some characters
            // if these characters are greater than K it gets invalid so we decrement the from the start
            // and we get final ans as right - left...
            
            if(right - left - maxi + 1 > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        
        return right - left;
    }
};