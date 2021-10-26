/* You are given two lists of integers a and b where every element in both lists is between 1 to 6. Consider an operation where you pick a number in either a or b and update its value to a number between 1 to 6.

Return the minimum number of operations required such that the sum of a and b are equal. If it's not possible, return -1.

Constraints

n ≤ 100,000 where n is the length of a
m ≤ 100,000 where m is the length of b
Example 1
Input
a = [1, 5]
b = [6, 5, 5]
Output
2
Explanation
If we change the 1 to 6 in a and the 6 to 1 in b, then both of their sums would be 11. */



int solve(vector<int>& a, vector<int>& b) {
    

    int asum = 0;
    int bsum = 0;

    for (auto i : a) asum += i;
    for (auto i : b) bsum += i;

    if (asum > bsum) {
        swap(a, b);
    }

    int na = a.size();
    int nb = b.size();

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(asum == bsum) return 0;

    int start = 0;
    int end = nb - 1;
    int curr = abs(asum - bsum);
    int ans = 0;

    while (start < na || end >= 0) {
        if (curr <= 0) {
            return ans;
        }

        int incLow = INT_MIN;
        int decHig = INT_MIN;

        if (start < na) {
            incLow = 6 - a[start];
        }
        // (b[end] - 1) because we don't want 0 in the array, as if the last element
        // is 6 we would decrement it by 6 and become zero
        // we are just checking if its possible or not

        if (end >= 0) {
            decHig = b[end] - 1;
        }

        if (incLow <= 0 and decHig <= 0) {
            break;
        }

        if (incLow > decHig) {
            ans++;
            curr -= incLow;
            start++;
        } else {
            ans++;
            curr -= decHig;
            end--;
        }
    }
    if (curr <= 0) return ans;
    return -1;
}