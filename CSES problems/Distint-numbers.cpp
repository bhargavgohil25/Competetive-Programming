#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define pb push_back
#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
    ll t;
    cin >> t;
    //vector <int> v; //
    ll v[t];
    for(int i=0;i<t;i++){
        cin >> v[i];
    }

    sort(v, v+t);

    ll count = 0;

    for(int i=0; i<t-1; i++){
        if(abs(v[i+1] - v[i]) != 0){
            count++;
        }
    }
    cout << count + 1;

return 0;
}