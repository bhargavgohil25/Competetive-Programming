#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
    ll test;
    cin>>test;
    while(test--){
        ll a, b ;
        cin>>a>>b;
        ll m = 2*a - b;
        ll n = 2*b - a;

        if(m >= 0 && m % 3 == 0 && n>= 0 && n % 3 == 0){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    
      

return 0;
}