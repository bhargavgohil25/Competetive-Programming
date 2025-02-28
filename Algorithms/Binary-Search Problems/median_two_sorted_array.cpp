class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        /*
            super good Problem
            TC -> O(log (n1 + n2))
            SC -> O(1)
        */

        int lo = 0;
        int hi = n1;

        while (lo <= hi) {
            // cut1 in nums1
            int cut1 = (lo + hi) / 2;
            // cut2 in nums2
            int cut2 = ((n1 + n2 + 1) / 2) - cut1;

            // cout << cut1 << ' ' << cut2 << endl;

            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            if (left1 <= right2 and left2 <= right1) {
                if ((n1 + n2) % 2 == 0) {
                    return double(max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    return max(left1, left2);
                }
            } else if (left1 > right2) {
                hi = cut1 - 1;
            } else {
                lo = cut1 + 1;
            }
        }
        return 0.0;
    }
};