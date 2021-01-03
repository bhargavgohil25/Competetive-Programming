#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)
#define repe(i,a,b) for(int i=a; i<=b; i++)
#define ll long long
#define ui unsigned int
#define pb push_back
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x,y) cout << #x << '=' << x << << #y << '=' << y << endl
#define all(x) x.begin(), x.end()
#define endl "\n"
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
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
typedef unordered_map<int, int> umap_ii;
typedef unordered_map<string, int> umap_si;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
//alt + ctrl + N

//===============================================================================//
ll power(ll x, ll y) {
ll v = 1; while (y > 0) { if (y & 1)v = v * x; y = y >> 1; x = x * x;} return v;
}

bool isPowerOfTwo(ll x){
    return x && (!(x & (x-1)));     //check if the number is power of two or not
}

//===============================================================================//

int main(){
    fastIO;
srand(chrono::high_resolution_clock::now().time_since_epoch().count());

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ll test = 1;
    cin >> test;
    while(test--){
        ll n;
        cin >> n;
        vi a(n);
        rep(i,0,n) cin >> a[i];
        // ll cnt = 0;
        // for (auto i = a.begin(); i != a.end(); ++i) { 
        //     if (*i % 3 == 0) { 
        //         a.erase(i); 
        //         i--; 
        //         cnt++;
        //     } 
        // }
        // // for (auto it = a.begin(); it != a.end(); ++it) 
        // // cout << ' ' << *it; 
        // // cout << endl;
        // vi vis = {0};
        // sort(all(a));
        // ll i = 0;
        // ll j = a.size()-1;
        // while(j > i){
        //     if((a[i] + a[j])%3 == 0 && vis[i] != 1 && vis[j] != 1){
        //         vis[i] = 1;
        //         vis[j] = 1;
        //         cnt++;
        //         i++;
        //         j = a.size()-1;
        //     }else{
        //         j--;
        //     }
        // }
        // cout << cnt << endl;
        ll cnt[3] = {0};
        rep(i,0,n){
            cnt[a[i]%3]++; 
        }
        ll ans = cnt[0];
        ll mini = min(cnt[1],cnt[2]);
        ans += mini;
        cnt[1] -= mini;
        cnt[2] -= mini;

        if(cnt[1] == 0){
            ans += cnt[2]/3;
            cout << ans << endl;
        }else if(cnt[2] == 0){
            ans += cnt[1]/3;
            cout << ans << endl;
        }

        

    }
return 0;
}