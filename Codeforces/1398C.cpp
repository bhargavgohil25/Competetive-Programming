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
typedef unordered_map<int, ll> umap_ii;
typedef unordered_map<string, int> umap_si;
//alt + ctrl + N

//====================//
ll power(ll x, ll y) {
ll v = 1; while (y > 0) { if (y & 1)v = v * x; y = y >> 1; x = x * x;} return v;
}

bool isPowerOfTwo(ll x){
    return x && (!(x & (x-1)));     //check if the number is power of two or not
}

ll subArray(vector<int> &nums, int k){
    ll n = nums.size();
    if(n == 0){
        return 0;
    }
    ll count = 0, i = 0, curr = 0;
    umap_ii map;
    while(i < n){
        curr += nums[i];
        if(curr == k){
            count++;
        }
        if(map.find(curr - k) != map.end()){
            count += map[curr-k];
        }
        map[curr] ++;
        i++;

    }
    return count;
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
        ll n;
        string num;
        cin >> n;
        cin >> num;
        vector <int> arr(n);
        rep(i,0,n){
            arr[i] = (num[i] - '0') - 1;
        }
        
        // for(auto i : arr){
        //     cout << i << ' ';
        // }
        // cout << endl;

        cout << subArray(arr,0) << endl;
        

    }
return 0;
}