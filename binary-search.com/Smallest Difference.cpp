/* Given a list of list of integers lists, return the smallest difference that can be made by picking one integer from each of the lists and taking the difference between the maximum and the minimum number of the picked integers.

Constraints

n, m ≤ 250 where n and m are the number of rows and columns in lists
Example 1
Input
lists = [
    [28, 46, 89],
    [83],
    [30, 64]
]
Output
25
Explanation
The best we can do is to take 89, 83, 64 and 89 - 64 = 25 */


int solve(vector<vector<int>>& lists) {
    int n = lists.size(), res = INT_MAX;
    // let me store the value,list id for each element
    priority_queue<pair<int, int>> pq;

    for (int id = 0; id < n; id++)
        for (int el : lists[id]) pq.push({el, id});

    // now slide a window, when it covers all the listid's, what's the max-min
    // using a map of fre of each id, when this map has a size n, we have elements from all the
    // lists
    unordered_map<int, int> fre;
    queue<pair<int, int>> q;

    while (!pq.empty()) {
        auto front = pq.top();
        pq.pop();

        fre[front.second]++;
        q.push(front);

        while (fre.size() == n) {
            res = min(res, q.front().first - q.back().first);
            // now the window size has to decrease, by removing from the left
            fre[q.front().second]--;
            if (fre[q.front().second] == 0) fre.erase(q.front().second);
            q.pop();
        }
    }

    return res;
}

