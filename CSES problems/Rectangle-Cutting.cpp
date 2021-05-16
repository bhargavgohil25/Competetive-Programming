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

// The approach is that we are making the vertical cut and horizontal cuts 
// and we are looking for the minimum ans

// The main idea is clear bt how to proceed, with the idea
// So, will be doing be with every possible height and width combination... and So the complexity will also be higher

// for (height 0 --> a)
// 	  for (width 0 --> b)
// 		if the height  == width --> dp[height][widht] = 0
// 		 we think that we have  the current parameter as height and width from the above 'for' loops
//	     and we will make different cut to this area vertically and horizontally
// 		 and we will update the min to the dp[height][width] = ans;
// and the final ans will be the  'dp[a][b]'

// This problem is pretty good as we have first have the intuition to decrement the min(a,b) continuosly...
// But it wont work for the case like (6,5) we have to do this by DP

// Good Explanation is given by KARTIK ARORA on YT
  

void solve(){
    ll a,b;
    cin >> a >> b;

    ll dp[a+1][b+1];

    for(int height = 1; height <= a; height++){

    	for(int width = 1; width <= b; width++){
    		if(height == width){
    			dp[height][width] = 0;
    		}else{
    			ll ans = INT_MAX;
    			for(int i=1; i<width; i++){
    				ans = min(ans, 1 + dp[height][width - i] + dp[height][i]);
    			}

    			for(int i=1; i<height; i++){
    				ans = min(ans, 1 + dp[height - i][width] + dp[i][width]);
    			}

    			dp[height][width] = ans;
    		}

    	}

    }

    cout << dp[a][b] << endl;
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