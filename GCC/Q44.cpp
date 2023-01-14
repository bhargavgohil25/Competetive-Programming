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
/*
5
Alice Bob Cacey Deepak Emma
10 14
11 12
10 15
12 16
14 16
5
10 11 2 Alice Cacey
11 12 3 Alice Bob Cacey
12 14 3 Alice Cacey Deepak
14 15 3 Cacey Deepak Emma
15 16 2 Deepak Emma
*/


void solve() {
	int n;
	cin >> n;

	vector<string> names(n);

	for (int i = 0; i < n; i++) cin >> names[i];

	vector<vector<int>> mapping(22, vector<int>(n, 0));

	vector<pair<int, int>> vp(n);

	set<int> a, b;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		vp[i] = {x, y};
		a.insert(x);
		b.insert(y);
	}

	// create a mapping of time slot and person working in that slot
	/*
			name1 name2 name3 name4 ..........
		1   1     0    1      1
		2   1			.    .      .      .
		3   0			.    .      .      .
		4   0			.    .      .      .
		5   1			.    .      .      .
		6   1			.    .      .      .
		7   1			.    .      .      .
		8   0			.    .      .      .
		9   1			.    .      .      .
		10  0			.    .      .      .
		11	0			.    .      .      .
	*/

	for (int i = 0; i < n; i++) {
		for (int j = vp[i].first; j <= vp[i].second; j++) {
			mapping[j][i] = 1;
		}
	}

	vector<int> aa(all(a));
	vector<int> bb(all(b));

	vector<pair<int, int>> pp;

	int i = 1, j = 0;
	// pp[0].first = aa[0];
	pp.push_back({aa[0], 0});

	while (i < aa.size() and j < bb.size()) {
		if (aa[i] < bb[j]) {
			pp.back().second = aa[i];
			pp.push_back({aa[i], 0});
			i++;
		} else if (bb[j] < aa[i]) {
			pp.back().second = bb[j];
			pp.push_back({bb[j], 0});
			j++;
		} else {
			pp.back().second = aa[i];
			pp.push_back({aa[i], 0});
			i++;
			j++;
		}
	}

	if (i == aa.size()) {
		pp.back().second = bb[j];
		while (j < bb.size() - 1) {
			pp.push_back({bb[j], bb[j + 1]});
			j++;
		}
	} else if (j == bb.size()) {
		pp.back().second = aa[i];
		while (i < aa.size() - 1) {
			pp.push_back({aa[i], aa[i + 1]});
			i++;
		}
	}
	// debug(aa);
	// debug(bb);
	// debug(pp);

	cout << pp.size() << endl;
	for (int i = 0; i < pp.size(); i++) {
		vector<string> temp;
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			for (int d = pp[i].first; d < pp[i].second; d++) {
				cnt += (mapping[d][j] + mapping[d + 1][j] == 2);
			}
			if (cnt == (pp[i].second - pp[i].first)) temp.push_back(names[j]);
		}
		cout << pp[i].first << ' ' << pp[i].second << ' ' << temp.size() << ' ';
		sort(all(temp));
		for (int l = 0; l < temp.size(); l++) {
			if (l == temp.size() - 1) {
				cout << temp[l];
			} else {
				cout << temp[l] << ' ';
			}
		}
		if (i != pp.size() - 1) cout << endl;
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