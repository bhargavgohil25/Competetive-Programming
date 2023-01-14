class Solution {
public:
	long long maxi = 1e17;
    
    long long maxPower(vector<int>& nums, int r, int k) {
        long long left = 0;
        long long right = maxi;
        
        int n = nums.size();
        
        vector<long long> vec(n);
        
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long need = 0;
            long long sum = 0;

            int a = 0, b = 0, c = 0;
            
            for (int i = 0;i<n;++i) {
                vec[i] = nums[i];
            }
            bool ok = true;
            while (b < n) {
                while (c <= min(n - 1, b + r)) {
                    sum += vec[c++];
                }
                while (b - a > r) {
                  sum -= vec[a++];
                }
                if (sum < mid) {
                    long long t = mid - sum;
                    need += t;
                    if (need > k) {
                        ok = false;
                        break;
                    }
                    vec[min(n - 1, b + r)] += t;
                    sum = mid;
                }
                ++b;
            }
            if (!ok) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }	
};