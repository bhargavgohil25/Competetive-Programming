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
#ifdef ONLINE_JUDGE
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
#endif
}

//===============================================================================//

/**
 * this is a pretty nice problem, find difficult at first... but get the intuition for this
 * lets take an example : 
 *
 * 3 5 4 5
 * 1 2 3 4 
 * 
 * now any time a number is deleted, the check for next number is decreased by 1
 * means, as 3 is not divisible by 2, 3 will be removed and what does it affect on the next number i.e 5 4 5
 * for 5 the range got decreased
 * 
 * means 5 4 5 
 * 			 1 2 3
 * now, 5 has to check with 2.... instead of 3........ ypu can see the pattern
 * every number has to check from 2 ... (index + 1) where index == initial index..
 * 
 * Now, do we have to use 2 for loops for this ??
 * No. We don't have to.. because the reason is this....
 * { 
 * 	So we just have to check for all integers i from 1 to n, 
 * 	if ai is not divisible by at least one integer from 2 to i+1. 
 * 	Notice that if ai is divisible by all integers from 2 to i+1, 
 * 	then it means that ai is divisible by LCM(2,3,…,(i+1)). 
 * 	But when i=22, LCM(2,3,…,23)>109>ai. So for i≥22, there will always be an integer from 2 to i+1 
 * 	which doesn't divide ai. 
 * 	So we don't have to check for them. For i<22, use bruteforce.
 * }
 */ 
void solve(){
	ll n;
	cin >> n;
	vi a(n);
	// rep(i,0,n) cin >> a[i];

	ll mini = min(23 * 1LL, n);
	bool check1 = false;
	bool ans = false;
	for(int i = 1; i <= mini; i++) {
		check1 = false;
		ll a;
		cin >> a;
		for(int j = 1; j <= i; j++) {
			if(a % (j+1) != 0) {
				check1 = true;
				break;
			}
		}
		if(!check1) ans = true;
	}
	for(int i = mini; i < n; i++) {
		ll a;
		cin >> a;
	}
	cout << (ans ? "No" : "Yes") << endl;

}

int main() {
  init();
  ll test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}