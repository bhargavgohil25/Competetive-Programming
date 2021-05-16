// Created by ...
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)
#define rrep(i,a,b) for(int i=b-1;i>=0;i--)
#define repe(i,a,b) for(int i=a; i<=b; i++)
#define ll long long
#define ld long double
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
#define PI 3.1415926535897932384626433832795

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

void init() {
	fastIO;
#ifdef BHARGAV
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
}

//===============================================================================//

void solve() {
	ll n;
	cin >> n;
	int k1, k2;
	deque<int>first, second;
	cin >> k1;
	rep(i, 0, k1) {
		ll x;
		cin >> x;
		first.push_back(x);
	}
	cin >> k2;
	rep(i, 0, k2) {
		ll x;
		cin >> x;
		second.push_back(x);
	}
	int rounds = 0;
	int mx = 1e5 + 5;
	int win;
	int i;
	for (i = 0; i < mx; i++) {
		ll firstTop = first.front();
		ll secondTop = second.front();
		first.pop_front();
		second.pop_front();
		if (firstTop > secondTop) {
			first.push_back(secondTop);
			first.push_back(firstTop);
		} else {
			second.push_back(firstTop);
			second.push_back(secondTop);
		}
		rounds++;
		if (first.empty()) {
			win = 2;
			break;
		}
		if (second.empty()) {
			win = 1;
			break;
		}
	}
	if (i == mx) {
		cout << -1 << endl;
		return;
	}
	cout << rounds << ' ' << win << endl;
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