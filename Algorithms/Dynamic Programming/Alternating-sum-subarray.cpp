class Solution {
public:
	int alternatingSum(vector<int>& nums) {
		int n = nums.size();


		int sum = 0;
		int currSum = 0;

		for (int i = 0; i < n; i++) {
			// if odd index
			if (i % 2 == 1) {
				currSum -= nums[i];
			} else {
				currSum = max(currSum + nums[i], nums[i]);
			}

			sum = max(currSum, sum);
		}

		currSum = 0;

		for (int i = 1; i < n; i++) {
			// if even index
			if (i % 2 == 0) {
				currSum -= nums[i];
			} else {
				currSum = max(currSum + nums[i], nums[i]);
			}

			sum = max(currSum, sum);
		}

		return sum;
	}
};