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
unsigned mod_pow(unsigned a, unsigned b, unsigned mod) {
	unsigned result = 1;

	while (b > 0) {
		if (b & 1)
			result = unsigned(uint64_t(result) * a % mod);

		a = unsigned(uint64_t(a) * a % mod);
		b >>= 1;
	}

	return result;
}
bool miller_rabin(unsigned n) {
	if (n < 2)
		return false;

	// Check small primes.
	for (unsigned p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
		if (n % p == 0)
			return n == p;

	int r = __builtin_ctz(n - 1);
	unsigned d = (n - 1) >> r;
	for (unsigned a : {2, 7, 61}) {
		unsigned x = mod_pow(a % n, d, n);

		if (x <= 1 || x == n - 1)
			continue;

		for (int i = 0; i < r - 1 && x != n - 1; i++)
			x = unsigned(uint64_t(x) * x % n);

		if (x != n - 1)
			return false;
	}

	return true;
}

ll find_prime(ll x) {
	while (!miller_rabin(x)) {
		x++;
	}
	return x;
}

void solve(ll test) {
	cout << "Case #" << test << ": ";
	ll z;
	cin >> z;
	ll low = 0, high = 1e9;

	auto evaluate = [&] (ll x) -> ll {
		ll p = find_prime(x);
		ll q = find_prime(p + 1);
		return p * q;
	};

	while (low < high) {
		int mid = low + (high - low + 1) / 2;
		if (evaluate(mid) <= z) {
			low = mid;
		} else {
			high = mid - 1;
		}
	}
	cout << evaluate(low) << endl;
}

int main() {
	init();
	int t = 1;
	cin >> t;
	rep(i, 1, t + 1) solve(i);
	return 0;
}