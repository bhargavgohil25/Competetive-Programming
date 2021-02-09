class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int>a(26);
        for(int i=0;i<s.length();i++) a[s[i] - 'a']++;
        int odd = 0;
        for(auto i : a) if(i&1) odd++;              
        if(k > s.length() || k < odd) return false;
        return true;
    }
};