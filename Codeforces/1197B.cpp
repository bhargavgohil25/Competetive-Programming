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

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ll test = 1;
    //cin >> test;
    while(test--){
        ll n;
        cin >> n;
        vi v(n);
        rep(i,0,n) cin >> v[i];
        int maxIndex = max_element(v.begin(),v.end())-v.begin();
        // int maxi = v[maxIndex];
        // int a = v[maxIndex-1];
        // int b = v[maxIndex+1];
        bool flag = true;
        for(int i=0;i<maxIndex;i++){
            if(v[i] < v[i+1]){
                continue;
            }else{
                //cout << "NO";
                flag = false;
                break;
            }
        }
        for(int i=maxIndex;i<n-1;i++){
            if(v[i] > v[i+1]){
                continue;
            }else{
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "YES";
        }else{
            cout << "NO";
        }
        // for(int i=0;i<v.size();i++){
        //     if(v[i] == maxi || v[i] == a || v[i] == b){
        //         continue;
        //     }else{
        //         if(v[i] > a){
        //             flag = false;
        //         }else if(v[i] > b){
        //             flag = false;
        //         }
        //     }
        // }
        // if(flag){
        //     cout << "YES";
        // }else{
        //     cout << "NO";
        // }
        

    }
return 0;
}