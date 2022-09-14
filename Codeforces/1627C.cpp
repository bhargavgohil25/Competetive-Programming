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
const int M = 3e5 + 5;
vector<int> v[M];

void solve(){
	int n;
	cin >> n;
	vector<int> ans(n - 1);
	vector<int> degree(n + 1);

	// edge maps to index
	map<pair<int, int>, int> edges;

	for(int i = 0 ; i <= n ; i++) v[i].clear();

	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;

		pair<int, int> edge = { a,b };
		edges[edge] = i;

		swap(edge.first, edge.second);

		edges[edge] = i;

		degree[a]++;
		degree[b]++;

		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	// if there finds a vertex whose degree is > 2
	// return -1;

	for(auto i : degree) {
		if(i > 2){
			cout << -1 << endl;
			return;
		}
	}

	// find the root / whose degree is 1
	int rootInd;
	for(int i = 1; i <= n; i++) {
		if(degree[i] == 1){
			rootInd = i;
			break;
		}
	}
	int weight = 2;

	queue<int> q;
	vector<int> vis(n + 1);
	vis[rootInd] = 1;
	q.push(rootInd);

	while(!q.empty()){
		int curr = q.front();
		q.pop();

		for(auto x : v[curr]) {
			if(!vis[x]) {
				vis[x] = 1;
				q.push(x);

				pair<int, int> edge = {curr, x};
				int ind = edges[edge];

				ans[ind] = weight;
				weight = (weight == 2 ? 5 : 2);
			}
		}
	}

	for(auto i : ans){
		cout << i << ' ';
	}

	cout << endl;
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