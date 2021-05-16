// Created by ... 
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
#define PI 3.1415926535897932384626433832795

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

vector<pair<ll,ll>>edge[100001];    
ll notRemoved, v[100001];

void dfs(ll node, ll parentNode, ll distance){
	if(v[node] < distance){
		return;
	}
	
	notRemoved++;

	for(int i=0; i<edge[node].size(); i++){
		if((edge[node][i].first) != parentNode){
			dfs(edge[node][i].first, node, max(0ll, distance + edge[node][i].second));
		}
	}
}
// count the vertices that will not be removed 
// i.e (notRemoved++) so the final answer will be the (n - notRemoved)
void solve(){
	ll n;
	cin >> n;

	notRemoved = 0;
	
	for(ll i=1; i<=n; i++){
		cin >> v[i];
	}

	for(ll i=1; i<=n-1; i++){
		ll p,c;
		cin >> p >> c;
		edge[i+1].push_back({ p,c });
		edge[p].push_back({ i+1,c });
	}

	dfs(1,0,0); // dfs(node, parentNode, distance);

	cout << n - notRemoved << endl;
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