// Created by ... Bhargav Gohil
#include <bits/stdc++.h>
#include <iostream>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
typedef tree<int, null_type,
        less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        Ordered_set;

void findMedian(vector<int>&a, int n, int k) {
	Ordered_set s;
	for (int i = 0; i < k; i++) {
		s.insert(a[i]);
	}
	// if (k & 1) { // if k (window size) is odd then

	// }else {
	// 	int ans = ((int)*s.find_by_order((k + 1) / 2 - 1) + (int) *s.find_by_order(k/2))/2;
	// 	cout << ans << ' ';

	// 	for(int i=0; i<n-k; i++){
	// 		s.erase(s.find_by_order(s.order_of_key(a[i])));
	// 		s.insert(a[i+k]);

	// 		ans = ((int) *s.find_by_order((k+1)/2 - 1) + (int) *s.find_by_order(k/2))/2;
	// 		cout << ans << ' ';
	// 	}
	// 	cout << endl;
	// }
	int ans = *s.find_by_order( (k-1) / 2);
	// print the answer at the mid of the window
	cout << ans << ' ';
	for (int i = 0; i < n - k; i++) {
		// erase the firs element from the ordered_set
		// first find the index of the element by order_by_key and delete that element by find_by_order by remove method
		s.erase(s.find_by_order(s.order_of_key(a[i])));
		// Inserting an element to the window
		s.insert(a[i + k]);
		ans = *s.find_by_order((k-1) / 2);
		cout << ans << ' ';
	}
	cout << endl;
}

int main() {
	init();
	ll test = 1;
	// cin >> test;
	while (test--) {
		// finding the window in the window size
		int n, k;
		cin >> n >> k;
		vi a(n);
		rep(i, 0, n) {
			cin >> a[i];
		}
		findMedian(a, n, k);
	}
	return 0;
}