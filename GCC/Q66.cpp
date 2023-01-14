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
vector<int> ans;

void print(stack<int> st1, int v) {
	int sz = 0;
	stack<int> st2;
	st2.push(st1.top());
	st1.pop();

	while (st2.top() != v) {
		st2.push(st1.top());
		st1.pop();
	}
	vector<int> temp;
	while (!st2.empty()) {
		// cout << st2.top() << ' ';
		temp.push_back(st2.top());
		sz++;
		st2.pop();
	}
	// temp contains all the elements of a cycle..
	for (auto i : temp) ans[i] = sz;
}
/*
	Get the the elements of the cycle in Directed Graph
	After the getting the elements in the cycle mark all the elements to the size of the cycle
*/
void dfs(vector<vector<int>>& adj, stack<int>& st, vector<int>& vis) {
	// debug(st.top());
	for (auto child : adj[st.top()]) {
		if (vis[child]) {
			print(st, child);
		} else {
			st.push(child);
			vis[child] = 1;
			dfs(adj, st, vis);
		}
	}

	vis[st.top()] = 1;
	st.pop();
}

void solve() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (auto &i : nums) cin >> i;

	vector<vector<int>> adj(n + 1);
	// vector<int> adj[n + 1];

	for (int i = 1; i <= n; i++) {
		adj[nums[i - 1]].push_back(i);
		// adj[i].push_back(nums[i - 1]);
	}

	// debug(adj);
	ans.resize(n + 1);

	vector<int> vis(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			stack<int> st;
			st.push(i);
			vis[i] = 1;
			dfs(adj, st, vis);
		}
	}
	// print for all the indexes
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << endl;
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