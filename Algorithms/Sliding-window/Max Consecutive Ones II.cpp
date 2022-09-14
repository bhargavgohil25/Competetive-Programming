class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        int cnt = 0;

        while(j < n) {
            cnt += (nums[j] == 1);
            j++;

            if(j - i - cnt > 1) {
                cnt -= (nums[i] == 1);
                i++;
            }
        }
        return j - i;
    }
};