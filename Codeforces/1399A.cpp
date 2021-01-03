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

int power(int a, int n) {
    int res = 1;
    while(n){
        if(n%2){
          res *= a;
          n--;
        }else{
           a *= a;
           n /= 2;
        }
    }
    return res;
}
bool solve(int v[],int n){
    for(int i=1; i<n; i++){
        if(v[i] - v[i-1] > 1){
            return 0;
        }
    }
    return 1;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ll test;
    cin >> test;
    while(test--){
        ll n;
        cin >> n;
        int v[n];
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        sort(v,v+n);
        bool check = true;
        if(solve(v,n)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
    }

return 0;
}