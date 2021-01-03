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
        ll n, m;
        cin >> n >> m;
        vector <int> a(n);
        vector <int> b(m);
        unordered_map <int,int> map;
        ll num = -1;
        for(int i=0; i<n; i++){
            cin >> a[i];
            map[a[i]] = 1;
        }
        for(int i=0; i<m; i++){
            cin >> b[i];
            if(map[b[i]]){
                num = b[i];
            }
        }
        for(int i=0; i<n; i++){
            map[a[i]] = 0;
        }
        if(num == -1){
            cout << "No" << endl;
        }else{
            cout << "YES\n" << 1 << " " <<num <<endl; 
        }

    }

return 0;
}