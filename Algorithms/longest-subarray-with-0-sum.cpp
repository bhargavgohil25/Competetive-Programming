class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        
        map<int, int> mp;
        
        int sum = 0;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];

            if(sum == 0){
                ans = i + 1;
            }
            
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }else{
                ans = max(ans, i - mp[sum]);
            }
        }

        return ans;
    }
};