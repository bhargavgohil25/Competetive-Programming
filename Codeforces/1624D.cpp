#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)
#define rrep(i,a,b) for(int i=b-1;i>=0;i--)
#define repe(i,a,b) for(int i=a; i<=b; i++)
#define ll long long
#define ld long double
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl "\n"
#define yup cout << "YES" << endl
#define nope cout << "NO" << endl
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());

ll power(ll x, ll y) {
  ll v = 1; while (y > 0) { if (y & 1)v = v * x; y = y >> 1; x = x * x;} return v;
}
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

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
  #ifndef ONLINE_JUDGE
  #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
  #else
  #define debug(x)
  #endif
}

//===============================================================================//

void solve(){
	ll n,k;
	cin >> n >> k;

	string s;
	cin >> s;
	unordered_map<char, int> mp;

	for(auto i : s) mp[i]++;

	ll pairs = 0;
	ll oddCnt = 0;

	for(auto i : mp) {
		pairs += (i.second / 2);
		if(i.second % 2 == 1) oddCnt++;
	}

	// count the minimum length of the string that can be formed 

	// pairs = 5 and k = 3
	// if we have 5 pairs of string
	// and we can color with 3 different colours
	// then the smallest palindrome will be length will be ans += 2 * (pairs / k);

	// and the pairs which are left will be added to the oddCounts as 2 * (pairs % k);
	

	ll ans = 2 * (pairs / k);
	oddCnt += 2 * (pairs % k);

	if(oddCnt >= k) {
		ans++;
	}

	cout << ans << endl;
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