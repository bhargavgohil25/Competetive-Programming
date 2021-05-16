// Created by ... 
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)
#define rrep(i,a,b) for(int i=b-1;i>=0;i--)
#define repe(i,a,b) for(int i=a; i<=b; i++)
#define ll long long
#define ld long double
#define ull unsigned long long
#define ui unsigned int
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define read(x) cin >> x[i]
#define endl "\n"
#define yup cout << "YES" << endl
#define nope cout << "NO" << endl
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define INF (int)1e9
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
typedef map<int, int> mii;
typedef unordered_map<int, int> umap_ii;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
const int M = 1e9 + 7;
//===============================================================================//
ll power(ll x, ll y) {
    ll v = 1; while (y > 0) { if (y & 1)v = v * x; y = y >> 1; x = x * x;} return v;
}

bool isPowerOfTwo(ll x) {
    return x && (!(x & (x - 1)));   //check if the number is power of two or not
}
ll ceil(ll a, ll b) { return (a + b - 1) / b; }

// Add your debug template here //
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void init() {
    fastIO;
#ifdef BHARGAV
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
}

//===============================================================================//
// Now the naive way to think about this problem is that 
// whenever we are encountered with a value '0' means we have to add an element at that position
// whose difference with adjacent elements is at most 1
// i.e | a[i] - x | <= 1 (x is the element we want to add)

// let we think about a dp state, how to think about a dp state for this problem ?
// let say, [ _ _ _ _ _ ] x
// we have to add an element at the end of the array, on the left of that 'x' we must have x-1 or x or x+1
// then only the property given will be satisfied.

// [ _ _ _ _ (x+1 or x or x-1)] x
// Now, the dp state will be   dp(i,x) ---> which means : No. of valid arrays of size 'i' such that at i'th position we can place 'x'    
// This simply means that what are the valid ways to form array of size x putting 'x' at the i'th position..

// so that we will know the answer for all size upto i before hand and will get them precomputed...
// Now the final ans will be like, before that let me tell you what actually we have to find, we find all the possible array count...
// the number of ways the array ends with 'x' (where 1 <= x <= m) so the final answer will be 
// summation of dp[n][x] (for all 1 <= x <= m)
// which means that number of ways the array ends with 'x' (for all 1 <= x <= m)

// so this was the intuition and approach of this problem which is very good 

// dp(i,x) == 0    if  a[i] != 0 || a[i] != x
// what this means is that if the value in the array is already occupied or the value in the array is 'x' then we have 0 ways to add an element at that position..

// base Case is : dp(1,x);
// now, when i == 1 --->  dp[1][(some 'x')] then, there also we will check if the value is occupied or check it is '0';
// see, cod section to more understand the edge case...

// Now, the main part reccurence --> How to think for the reccurence ?
// dp(i,x) == dp(i-1, x-1) + dp(i-1, x) + dp(i-1, x+1)
// this means that the we add the no. of valid arrays that end at the position i'th and have the value of x as (x-1 or x+1 or x)

// This is the whole explanation.... 
// Hope you liked it.


void solve(){
    ll n,m;
    cin >> n >> m;
    vi a(n+1);
    rep(i,1,n+1) cin >> a[i];

    int dp[n+2][m+2];
    memset(dp, 0, sizeof dp);

    for(int i=1; i<=n; i++){

    	for(int x=1; x<=m; x++){

    		if(i == 1){
    			if(a[i] == 0 || a[i] == x){
    				dp[i][x] = 1;
    			}else{
    				dp[i][x] = 0;
    			}
    		}else{
    			if(a[i] == 0 || a[i] == x){
    				dp[i][x] = ((dp[i-1][x-1] + dp[i-1][x])%M + dp[i-1][x+1])%M;
    			}else{
    				dp[i][x] = 0;
    			}
    		}
    	}
    }
    int ans = 0;
    for(int x=1; x<=m; x++){
    	ans = (ans + dp[n][x]) % M;
    }
    cout << ans << endl;
}

int main() {
    init();
    ll test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}