class Solution {
public:
    
    void backtrack(vector<int>& can, int start,int tar,vector<int>&temp, vector<vector<int>>& ans){
        if(tar < 0) {
            return;
        }
        if(tar == 0){
            ans.push_back(temp);
        }
        for(int i=start;i<can.size();i++){
            temp.push_back(can[i]);
            backtrack(can,i,tar-can[i],temp,ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(can,0,target,temp,ans);    
        return ans;
    }
};