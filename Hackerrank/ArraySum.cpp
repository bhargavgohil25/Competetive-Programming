#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define pb push_back

#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
    ll n , m;
    cin >> n >> m;
    ll arr[n];
    ll sum = 0;
    unordered_map <int,int> map;
    for(int i=0;i<n;i++){
        arr[i] = i+1;
        sum += arr[i];
        map[arr[i]] = 1;
    }
    ll last = arr[n-1];
    ll first = arr[0];
    while(m--){
        sum -= last;
        sum -= first;
        ll x;
        cin >> x;
        if(map[x] == 1){
            swap(last, first);
        }else{
            map[last] = 0;
            last = x;
            map[last] = 1;
        }
        sum += last;
        sum += first;
        cout << sum << "\n";
    }

return 0;
}