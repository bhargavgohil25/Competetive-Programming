#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)
#define repe(i,a,b) for(int i=a; i<=b; i++)
#define ll long long
#define ui unsigned int
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second
#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

#define hcf(x,y)     __gcd(x,y)
#define lcm(x,y)     (x*y)/(__gcd(x,y))
#define CountOne(x)  __builtin_popcount(x)        
#define parity(x)    __builtin_parity(x)           //Funtion return (true) if number of set bits is odd(odd parity) else false..
#define LeadZero(x)  __builtin_clz(x)             //Counts leading zero in binary representation of x ....   
#define TrailZero(x) __builtin_ctz(x)

#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef map<int, int> mii;
typedef unordered_map<int, int> umap_ii;
typedef unordered_map<ll, ll> umap_ll;
typedef unordered_map<string, int> umap_si;
//alt + ctrl + N

//====================//
ll power(ll x, ll y) {
ll v = 1; while (y > 0) { if (y & 1)v = v * x; y = y >> 1; x = x * x;} return v;
}

bool isPowerOfTwo(ll x){
    return x && (!(x & (x-1)));     //check if the number is power of two or not
}

void solve(){
    ll n,k;
    cin >> n >> k;
    vl a(n);
    umap_ll map;
    rep(i,0,n){
        cin >> a[i];
    }
    rep(i,0,n){
        map[a[i]]++;
    }

    if(map.size() > k){
        cout << -1 << endl;
        return; 
    }
    vl v;
    for(auto it= map.begin();it!=map.end();it++){
        v.pb(it->first);
    }
    while(v.size() < k){
        v.pb(1);
    }
    cout << n*v.size() << endl;
    rep(i,0,n){
        rep(j,0,v.size()){
            cout <<  v[j] << ' ';
        }
    }
    cout << endl;

}


int main(){
    fastIO;

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ll test;
    cin >> test;
    while(test--){
        
        solve();
    }
return 0;
}