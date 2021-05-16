#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;


ll powll(ll b, ll p){
    ll ans = 1;
    for(ll i=0; i<p; i++){
        ans = ans * b;
    }
    return ans;
}

int main(){
    ll n;
    cin>>n;
    //The formula for the Trailing zeros in the factorial is 
    // n/5 + n/25 + n/125 + ........
    //continue this until it is > 1
    //This formula is formed because the the trailing zeroes are made of 5*2, and we need to find the number of 5's and number of 2's
    ll count = 0;
    while(n != 0){
        n /= 5;
        count += n;
    }
    cout<< count; 

return 0;
}