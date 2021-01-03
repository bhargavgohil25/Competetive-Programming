#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define pb push_back
#define INF 1e9
#define all(x) x.begin(), x.end()
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
//alt + ctrl + N

int power(int a, int n) {
    int res = 1;
    while(n){
        if(n%2){
          res *= a;
          n--;
        }else{
           a *= a;
           n /= 2;
        }
    }
    return res;
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ll test;
    cin >> test;
    while(test--){
        ll n,k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }
        sort(all(a));
        sort(b.begin(), b.end(), greater<int>());
        vector<int> s;
        for(int i=0;i<k;i++){
            s.pb(b[i]);
        }
        for(int i=0;i<k;i++){
            if(a[i] < b[i]){
                a[i] = s[i];
            }
        }
        ll sum = 0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        cout << sum << endl;
    }
return 0;
}