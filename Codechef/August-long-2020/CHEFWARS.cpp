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
        ll chef, darth;
        cin >> darth >> chef;
        while(chef != 0 && darth>chef){
            darth = darth - chef;
            chef = chef/2;
        }

        if(chef == 0){
            cout << "0" << endl;
        }
        if(darth <= chef){
            cout << "1" << endl;
        }
    }
    
return 0;
}