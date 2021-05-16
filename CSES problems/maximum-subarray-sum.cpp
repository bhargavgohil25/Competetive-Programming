#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define pb push_back
#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif
    ll n;
    cin >> n;
    vector <ll> v;
    for(int i=0; i<n; i++){
        ll a;
        cin >> a;
        v.pb(a);
    }
    //KADANES ALGORITHM
    ll max = INT_MIN, tempMax = 0;
    for(int i=0; i<n; i++){
        tempMax += v[i];
        if(max < tempMax){
            max = tempMax;
        }
        if(tempMax < 0){
            tempMax = 0;
        }
    }
    cout << max ;

return 0;
}