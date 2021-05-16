#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define pb push_back
#define INF 1e9
#define fastIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
using namespace std;

int main()
{
    int t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            total += arr[i];
        }

        int ans = INT_MAX;
        for (int i = 0; i < (1 << n); i++)
        {
            int c = 0;
            for (int j = 0; j < n; j++)
            {
                if (1 << j & i)
                {
                    c += arr[j];
                }
            }
            ans = min(ans, abs(total - c - c));
        }
        cout << ans;
    }

    return 0;
}