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

int lcm (int a,int b){
    return (a/__gcd(a,b)) * b;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ll test;
    cin >> test;
    while(test--){
        ll n,a,b,m;
        cin >> n;
        vector<ll> div;
        for(int i=1; i<=sqrt(n); i++){
            if(n%i == 0){
                div.pb(i);
                if(i != n/i){
                    div.pb(n/i);
                }
            }
        }
        sort(all(div));
        m = div[1]; 
        a = n/m;
        b = (m-1) * a;
        cout << a << ' '<< b<<endl;
    }
return 0;
}