class Solution {
public:
	int minimumWindowSubstring(string s, string t) {
		unordered_map<char, int> mp;

		for(auto i : t) mp[i]++;

		int count = 0; // count number of t's letters are in current window

		int lo = 0;
		int hi = 0;
		int min_len = INT_MAX;
		int min_start = 0;


		while(hi < s.length()) {

			if(mp[s[hi]] > 0) count++; // means that this letter is in t

			mp[s[hi]]--;

			if(count == t.length) {

				while(lo < hi and mp[s[lo]] < 0) {
					mp[s[lo]]++;
					lo++;
				}

				if(min_len > hi - lo) {
					min_len = hi - lo + 1;
					min_start = lo;
				}
			}
		}

		return min_len;
	}	
};