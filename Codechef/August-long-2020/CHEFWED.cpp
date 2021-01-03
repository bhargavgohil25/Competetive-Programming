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


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ll test;
    cin >> test;
    while(test--){
        ll n, k, count = 0;
        cin >> n >> k;
        vector <ll> f(n);
        unordered_map <int,int> map;
        for(int i=0; i<n; i++){
            cin >> f[i];
            map[f[i]]++;
        }
        for(auto i : map){
            count += i.second - 1;
        }
        int cnt = 1;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(f[i] == f[j]){
                    i = j;
                    //cout << f[j] << " " << f[i] << endl;
                    cnt++;
                    break;
                }
            }
        }
        if((count + k +1) < cnt*k){
            cout << (count+k+1) << endl;
        }else{
            cout << cnt*k << endl;
        }

        // int cnt = 1;
        // int m = INT_MIN;
        // for(int i=0; i<n-1; i++){
        //     if(f[i+1]-f[i] == 0){
        //         cnt++;
        //         m = max(m,cnt);
        //     }else{
        //         cnt = 1;
        //     }
        // }
        // cout << m << endl;
    }
return 0;
}