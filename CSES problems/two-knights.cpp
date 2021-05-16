#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
    ll n;
    cin >> n;
    for(ll i=1; i<=n; i++){
        cout<< ((i*i)*((i*i)-1) - 8 -24 - (16 * (i-4)) - 16 - ((i-4)*24) - ((i-4)*(i-4)*8))/2 << endl;
    }
    
return 0;
}