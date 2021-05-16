// Created by ... Bhargav Gohil
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
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x,y) cout << #x << '=' << x << ' ' << #y << '=' << y << endl
#define deb3(x,y,z) cout << #x << '=' << x << ' ' << #y << '=' << y <<  ' ' << #z << '=' << z << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define read(x) cin >> x[i]
#define endl "\n"
#define yup cout << "Yes" << endl
#define nope cout << "No" << endl
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define INF (int)1e9
#define PI 3.1415926535897932384626433832795

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


int main() {
	init();
	ll test = 1;
	cin >> test;
	while (test--) {
		ll n, p, q;
		cin >> n >> p >> q;
		string s;
		cin >> s;
		bool one = false;
		ll num_one = 0, num_zero = 0;
		ll ans = 0;
		for (auto i : s) {
			if (i == '1') {
				// if we are getting 1's after getting some 0's then we have to make a decission whether to make the platform at height 1 or 2
				// we will take the minimum of that and it into the answer
				if (one && num_zero != 0) {
					ans += (min((num_zero + 2) * p + (num_zero - 1) * q , (num_zero) * p + 2 * q * (num_zero - 1)));
				}
				// we have found some 0's earlier and we are getting 1 for the first time
				// then we have to count the cost of building those 0's
				// 2 - 0's require --> 3 pipes and 2 pillars
				else if (!one && num_zero != 0) {
					ans += (num_zero + 1) * p  + q * num_zero;
				}
				num_zero = 0;
				num_one++;
				one = true;
			}
			else {
				// yaha agr consecutive 1 mile pehle and fir zeroes aaye to hame kuch bhi krke unhe count krna hi hoga...
				// like we have to build the (pillar + pipes) to all the 1's...
				if (num_one != 0) {
					ans += (num_one * p + 2 * q * (num_one + 1));
					num_one = 0;
				}
				// agar 1 nahi mila ab tak
				// count the occurences of num of zero's
				num_zero++;
			}
		}
		// end conditions
		// if we have number of 0's at the end
		if (one && num_zero != 0) {
			ans += (num_zero + 1 ) * p + q * num_zero;
		}
		// if we haven't encounterd any one in the whole string then
		else if (!one) {
			ans = num_zero * p + (num_zero + 1) * q;
		}
		// final answer
		cout << ans << "\n";
	}
	return 0;
}