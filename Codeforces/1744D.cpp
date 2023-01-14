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



vector<int> temps(200001, 0);

void solve()
{
	ll i, j, k, n, m, q;
	cin >> n;
	int p2 = 0;
	vi nums(n);

	for (i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		while (tmp % 2 == 0)
		{
			tmp = tmp / 2;
			p2++;
		}
	}

	vector<int> b;
	for (i = 2; i <= n; i += 2)
	{
		int cnt = 0, tmp = i;
		while (tmp % 2 == 0)
		{
			tmp = tmp / 2;
			cnt++;
		}
		b.push_back(cnt);
	}
	sort(b.rbegin(), b.rend());
	j = 0;

	int ans = 0;

	while (j < b.size() and p2 < n)
	{
		p2 += b[j];
		ans++;
		j++;
	}
	if (p2 < n)
	{
		cout << "-1\n";
	}
	else
	{
		cout << ans << "\n";
	}
}

// void solve() {
// 	int n;
// 	cin >> n;
// 	vector<int> nums(n);

// 	for (int i = 0; i < n; i++) {
// 		cin >> nums[i];
// 	}
// 	debug(nums);
// 	int count = 0;

// 	for (int i = 0; i < n; i++) {
// 		while (nums[i] % 2 == 0) {
// 			count++;
// 			nums[i] /= 2;
// 		}
// 	}

// 	if (count >= n) {
// 		cout << 0 << endl;
// 		return;
// 	}

// 	vector<int> v;

// 	for (int i = 0; i <= n; i++) {
// 		v.push_back(temps[i]);
// 	}

// 	sort(v.rbegin(), v.rend());

// 	for (int operation = 0; operation <= n; operation++) {
// 		count += v[operation];
// 		if (count >= n) {
// 			cout << operation + 1 << endl;
// 			return;
// 		}
// 	}

// 	cout << -1 << endl;
// }

int main() {
	init();
	ll test = 1;
	cin >> test;
	// for (int i = 1; i <= 200000; i++) {
	// 	int count = 0, temp = i;
	// 	while (temp % 2 == 0) {
	// 		count++;
	// 		temp /= 2;
	// 	}
	// 	temps[i] = count;
	// }

	while (test--) {
		solve();
	}
	return 0;
}