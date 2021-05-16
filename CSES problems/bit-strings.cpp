#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

ll powll(ll b, ll p, ll mod){
    ll ans = 1;
    for(ll i=0; i<p; i++){
        ans = ans * b % mod;
    }
    return ans;
}

int main(){
    ll n;
    cin>>n;

    cout<<powll(2, n, 1e9 + 7); 
    
      

return 0;
}