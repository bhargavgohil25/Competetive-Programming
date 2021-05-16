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
    fastIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ll test;
    cin >> test;
    while(test--){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        if(b >= a){
            cout << b << endl;
            continue;
        }
        if(c <= d){
            cout << -1 << endl;
            continue;
        }
        ll ans = b;
        ll more = a - b;
        ll one = c - d;
        more = ((a-b + one -1) / one) * c;
        ans += more;
        cout << ans << endl;
    }


    /*
        ceil(a/b) ====> can be written as (a+b-1)/b
    */










    // int x ;
    // cin >> x;
    // for(int k = 31; k>=0; k--){
    //     if(x&(1<<k)){
    //         cout << 1;
    //     }else{
    //         cout << 0;
    //     }
    // }
    // int x = 0;
    // x |= 1<<3;
    // x |= 1<<5;
    // x |= 1<<7;
    // x |= 1<<2;
    // cout << __builtin_popcount(x) << endl;
    // for(int i=0; i<32; i++){
    //     if(x&(1<<i)){
    //         cout << i << " ";
    //     }
    // }


    
return 0;
}