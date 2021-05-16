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

void solve() {
	vi a(6);
	int first = 0;
	int second = 0;
	rep(i, 0, 6) {
		char c;
		cin >> c;
		a[i] = c - '0';
		if (i < 3) first += a[i];
		else second += a[i];
	}

	if (first == second) {
		cout << 0 << endl;
		return;
	}
	int minSteps = INT_MAX;

	debug(first);
	debug(second);
	int diff = abs(second - first);

	if (first < second) {
		// increasing the first part
		int steps1 = 0;
		vi temp1(6);

		for(int i=0; i<3; i++){
			temp1[i] = 9 - a[i];
		}
		for(int i=3; i<6; i++){
			temp1[i] = a[i];
		}
		sort(all(temp1));
		// debug(temp1);
		int curr = 0;
		for(int i=5; i>=0; i--){
			curr += temp1[i];
			steps1++;
			if(curr >= diff){
				break;
			}
		}
		cout << steps1 << endl;

	} else {
		// decrease from the first part
		int steps2 = 0;
		vi temp2(6);
		for(int i=3; i<6; i++){
			temp2[i] = 9 - a[i];
		}
		for(int i=0; i<3; i++){
			temp2[i] = a[i];
		}
		sort(all(temp2));
		int curr = 0;
		for(int i=5; i>=0; i--){
			curr += temp2[i];
			steps2++;
			if(curr >= diff){
				break;
			}
		} 
		cout << steps2 << endl;
	}
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