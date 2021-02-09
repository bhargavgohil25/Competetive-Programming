class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> ind(26);
        // map<char,int> mp;
        for(int i=0;i<n;i++){
            ind[s[i]-'a'] = i;
        }
        vector<int>ans;
        int curr_far = -1;
        int len = 0;
        for(int i=0;i<n;i++){
            curr_far = max(curr_far,ind[s[i]-'a']);
            len++;
            if(i == curr_far){
                ans.push_back(len);
                len = 0;
            }
        }
        return ans;
    }
};