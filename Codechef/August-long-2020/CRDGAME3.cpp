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
    cin >> test ;
    while(test--){
        ll a, b;
        cin >> a >> b;
        ll diga = 0, digb = 0;
        //Simple check the integer count wrt 9 for number a and number b
        if(a % 9 == 0){
            diga = a/9;
        }else{
            diga = a/9 + 1;
        }
        if(b % 9 == 0){
            digb = b/9;
        }else{
            digb = b/9 + 1;
        }
        if(diga == digb || diga > digb){
            cout << 1 << " " << digb << endl;
        }else{
            cout << 0 << " " << diga << endl;
        }
    }
return 0;
}