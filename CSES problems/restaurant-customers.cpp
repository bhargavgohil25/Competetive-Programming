#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define pb push_back
#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
    ll n;
    cin >> n;
    int arrival[n];
    int leave[n];
    for(int i=0; i<n; i++){
        cin >> arrival[i] >> leave[i];
    }
    sort(arrival,arrival + n);
    sort(leave, leave + n);
    ll ans = 0;
    ll i = 0, j = 0, current = 0;
    while(i<n && j<n){
        if(arrival[i] < leave[j]){
            current++;
            i++;
        }else{
            current--;
            j++;
        }
        //ans = max(ans, current);
        if(ans < current){
            ans = current;
        }
    }
    cout << ans << "\n";
return 0;
}