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

//===============================================================================

ll n,ans = 0;
ll dp[5005][5005];
ll a[5005],b[5005];

ll recur(ll l, ll r){
	if(l > r){
		return 0;
	}
	if(l == r){
		return dp[l][r] = a[l]*b[r];
	}
	if(dp[l][r] != -1) return dp[l][r];

	return dp[l][r] = a[l]*b[r] + a[r]*b[l] + recur(l+1,r-1);

}

void solve() {
	cin >> n;
	rep(i, 0, n) cin >> a[i];
	
	rep(i, 0, n){
		cin >> b[i];
		ans += a[i] * b[i];
	} 

	ll pref[n];
	pref[0] = a[0] * b[0];
	rep(i, 1, n) {
		pref[i] = pref[i - 1] + (a[i] * b[i]);
	}

	memset(dp, -1, sizeof dp);
	for (ll i = 0; i < n; i++) {
		for (ll j = i; j < n; j++) {
			if (dp[i][j] == -1) {
				recur(i, j);
			}
			ll temp = pref[n - 1] - pref[j];
			if (i > 0) {
				temp += pref[i - 1];
			}
			temp += dp[i][j];
			ans = max(temp, ans);
		}
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