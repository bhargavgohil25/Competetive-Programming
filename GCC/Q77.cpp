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

bool checkForCycle(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& dfs_check_vis) {
  vis[node] = 1;
  dfs_check_vis[node] = 1;

  for (auto it : adj[node]) {
    // if(it == node) return false;
    if (vis[it] == 0) {
      // if it contains cycle return true
      if (checkForCycle(it, adj, vis, dfs_check_vis)) {
        return true;
      }
    } else if (dfs_check_vis[it]) {
      return true;
    }
  }
  // after every dfs done. mark the root node as not done
  // and return false
  dfs_check_vis[node] = 0;
  return false;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  // Build adjancency list
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (a == b) continue;
    adj[a].push_back(b);
  }

  // debug(adj);

  vector<int> vis(n, 0), dfs_check_vis(n, 0);

  for (int i = 0; i < n; i++) {
    if (vis[i] == 0) {
      if (checkForCycle(i, adj, vis, dfs_check_vis)) {
        cout << "Ineligible" << endl;
        return;
      }
    }
  }

  cout << "Eligible" << endl;
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