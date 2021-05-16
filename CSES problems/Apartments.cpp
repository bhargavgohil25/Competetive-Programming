#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define pb push_back
#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int count = 0;
    int i=0, j=0;
    while(i<n && j<m){
        if(abs(a[i]-b[j]) <= k){
            count++;
            i++;
            j++;
        }else if(a[i] < b[j]){
            i++;
        }else{
            j++;
        }
    }
    cout << count;

return 0;
}