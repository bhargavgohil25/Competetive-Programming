class Solution {
public:
    void backtrack(vector<int>&nums,int curr, vector<int>&temp,vector<vector<int>>&ans){
        if(curr >= nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[curr]);
        backtrack(nums,curr+1,temp,ans);
        temp.pop_back();
        backtrack(nums,curr+1,temp,ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int siz = nums.size();
        vector<vector<int>> ans;
        vector<int>temp;
        backtrack(nums,0,temp,ans);
        return ans;
    }
};