#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define pb push_back
#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
    ll n,x;
    cin >> n >> x;
    vector<int> w(n);
    for(int i=0; i<n; i++){
        cin >> w[i];
    }
    sort(w.begin(),w.end());
    int i = 0, j = n - 1;
    int taken = 1;
    int total = 0;
    int curr = w[j];
    while(i < j){
        if(taken == 2){
            total++;
            j--;
            curr = w[j];
            taken = 1;
        }else if( curr + w[i] > x){
            total++;
            j--;
            curr = w[j];
            taken = 1;
        }else{
            curr = curr + w[i];
            i++;
            taken++;
        }
    } 
    cout << total + 1;

return 0;
}