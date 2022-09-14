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

	int n, a, b;
	cin >> n >> a >> b;

	if(abs(a - b) > 1 || a + b > n - 2) {
		cout << -1 << endl;
		return;
	}
	ll i, j;

	// if we draw some test case then we can see that
	// for every 2 peaks we have 1 valley
	// so start with peak.....

	if(a > b) {
		i = 1, j = n;
		while(a != 0) {
			cout << i << ' ' << j << ' ';
			i++;
			j--;
			a--;
		}
		while(j >= i) {
			cout << j << ' ';
			j--;
		}
		cout << endl;
		return;
	}

	if(a < b) {
		i = n, j = 1;
		while(b != 0) {
			cout << i << ' ' << j << ' ';
			i--;
			j++;
			b--;
		}
		while(j <= i){
			cout << j << ' ';
			j++;
		}
		cout << endl;
		return;
	}

	if(a == b) {
		i = n, j = 1;
		while(b != 0) {
			cout << i << ' ' << j << ' ';
			i--;
			j++;
			b--;
		}
		cout << i-- << ' ';
		while(j <= i) {
			cout << i-- << ' ';
		}
		cout << endl;
		return;
	}

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