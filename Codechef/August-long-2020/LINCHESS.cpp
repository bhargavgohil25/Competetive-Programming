#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define pb push_back
#define INF 1e9
#define all(x) x.begin(), x.end()
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
//alt + ctrl + N

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ll test;
    cin >> test;
    while(test--){
        ll n,m;
        cin >> n >> m;
        vector <int> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        bool check = false;
        ll min = INT_MAX, steps = 0, temp;
        for(int i=0; i<n; i++){
            if(v[i] < m && m%v[i] == 0){
                check = true;
                temp = (m/v[i])-1;
                if(min > temp){
                    min = temp;
                    steps = v[i];
                }
            }
        }
        if(check == true){
            cout << steps << endl;
        }else{
            cout << -1 << endl;
        }
    }

return 0;
}