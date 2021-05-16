class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string>ans;
        int i = 0,j = 0;
        string s;
        while(i < n and j < n){
            s += to_string(nums[i]);
            while(j+1 < n && nums[j+1] == nums[j] + 1){
                j++;
            }
            if(i == j){
                ans.push_back(s);
                i = j+1;
                j = i;
                s = "";
                continue;
            }
            s += "->" + to_string(nums[j]);
            ans.push_back(s);
            i = j+1;
            j = i;
            s = "";
        }
        return ans;
    }
};