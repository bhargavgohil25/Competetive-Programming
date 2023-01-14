class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int lo = 0;
        int hi = n - 1;
        // TC -> O(log N)
        // SC -> O(1)
        while (lo <= hi) {

            int mid = (lo + hi) / 2;
            // where (mid - lo) depicts the length of both right and left portions
            // if nums[mid] and nums[mid + 1] are same and length of arr is odd
            // if we stand on the middle, the length of left and right will be even
            // 0 1 2 3 4 5 6 7 8 <- index
            // 1 1 2 2 3 3 4 5 5 <- elements
            // suppose here we are at index 3, then index 3 4 are same
            // the length of left part will become odd if we remove both 3's from there.. which says that
            // there's a missing pair
            // same for the case when the length of left and right are odd.
            if (mid + 1 < n and nums[mid] == nums[mid + 1]) {
                if ((mid - lo) % 2) {
                    hi = mid - 1;
                } else {
                    lo = mid + 2;
                }
            } else if (mid - 1 >= 0 and nums[mid] == nums[mid - 1]) {
                if ((mid - lo) % 2) {
                    lo = mid + 1;
                } else {
                    hi = mid - 2;
                }
            } else {
                return nums[mid];
            }
        }
        return -1;
    }
};