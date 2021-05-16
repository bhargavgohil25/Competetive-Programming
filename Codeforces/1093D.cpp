// Created by ... 
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)
#define rrep(i,a,b) for(int i=b-1;i>=0;i--)
#define repe(i,a,b) for(int i=a; i<=b; i++)
#define ll long long
#define ld long double
#define ull unsigned long long
#define ui unsigned int
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define read(x) cin >> x[i]
#define endl "\n"
#define yup cout << "YES" << endl
#define nope cout << "NO" << endl
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define INF (int)1e9
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
typedef map<int, int> mii;
typedef unordered_map<int, int> umap_ii;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
const int M = 998244353;
//===============================================================================//
ll power(ll x, ll y) {
    ll v = 1; while (y > 0) { if (y & 1)v = v * x; y = y >> 1; x = x * x;} return v;
}

bool isPowerOfTwo(ll x) {
    return x && (!(x & (x - 1)));   //check if the number is power of two or not
}
ll ceil(ll a, ll b) { return (a + b - 1) / b; }

// Add your debug template here //
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

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
#ifdef BHARGAV
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
}

//===============================================================================//
ll mod(ll x) {
    return ((x % M + M) % M);
}
ll add(ll a, ll b) {
    return mod(mod(a) + mod(b));
}
ll mul(ll a, ll b) {
    return mod(mod(a) * mod(b));
}
ll modPow(ll a, ll b) {
    if (b == 0) return 1LL;
    if (b == 1) return a % M;
    ll res = 1;
    while (b) {
        if (b % 2 == 1) res = mul(res, a);
        a = mul(a, a);
        b = b / 2;
    }
    return res;
}


vector<ll>adj[300005];
ll col[300005], vis[300005];
int parity[2];

int dfs(int node, int c){
	vis[node] = 1;
	parity[c]++;
	col[node] = c;

	for(auto child : adj[node]){

		if(vis[child] == 0){

			int code = dfs(child, c ^ 1);

			if(code == -1){
				return -1;
			}

		}else{
			if(col[child] == col[node]){
				return -1;
			}
		}
	}
	return 0;
}

void solve(){
    ll n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
    	adj[i].clear();
    	vis[i] = 0;
    }
    for(int i=1; i<=m; i++){
    	ll a,b;
    	cin >> a >> b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }

    ll res = 1;
    bool flag = true;

    for(int i=1; i<=n; i++){

    	if(vis[i] == 0){
    		parity[0] = parity[1] = 0;

    		int checkBipartite = dfs(i,0);

    		if(checkBipartite == -1){
    			flag = false;
    			break;
    		}

    		res = (res * (modPow(2, parity[0]) + modPow(2,parity[1]))) % M;

    	}

    }
    if(!flag){
    	cout << 0 << endl;
    }else{
    	cout << res << endl;
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