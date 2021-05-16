#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define pb push_back
#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<int> h(n);
    vector<int> t(m);
    //unordered_map <int, int> map;
    multiset<int> set;
    for(int i=0;i<n;i++){
        cin >> h[i];
        set.insert(h[i]);
    }


    for(int i=0; i<m; i++){
        int r;
        cin >> r;
        auto it = set.upper_bound(r);
        if(it == set.begin()){
            cout << -1 << "\n";
        }else{
            it--;
            cout << *it << "\n";
            set.erase(it);
        }
    }

return 0;
}