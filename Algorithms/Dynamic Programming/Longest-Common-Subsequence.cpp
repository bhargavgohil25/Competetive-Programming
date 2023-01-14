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

vector<vector<int>>dp(3001, vector<int>(3001));
vector<vector<int>>choice(3001, vector<int>(3001));
// we are declaring the choice vector to store the selected character
// means 
// 0 --> (i-1, j)
// 1 --> (i, j-1)
// 2 --> (i-1, j-1)

void solve(){
	string s,t;
	cin >> s >> t;

	int n = s.length();
	int m = t.length();
	
	dp[0][0] = (s[0] == t[0] ? 1 : 0);
	if(s[0] == t[0]){
		choice[0][0] = 2;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			// Not Picking the Current element
			// this means we are not including the i'th character of the 
			// s string 
			if(i > 0){
				dp[i][j] = dp[i-1][j];
				choice[i][j] = 0;
			}
			// this means that we are not including the j'th character of the 
			// t string 
			if(j > 0){
				if(dp[i][j-1] > dp[i][j]){
					dp[i][j] = dp[i][j-1];
					choice[i][j] = 1;
				}
				// dp[i][j] = max(dp[i][j], dp[i][j-1]);
			}

			// Now Picking the current Character
			if(s[i] == t[j]){
				int ans = 1;
				if(i > 0 and j > 0){
					ans = 1 + dp[i-1][j-1]; // Means we are incrementing 1 to to the answer upto its back
				}
				if(ans > dp[i][j]){
					dp[i][j] = ans;
					choice[i][j] = 2;
				}
			}
		}
	}

	// now we are recovering the best choices made at every steps 
	// starting from the last step
	int i = n-1, j = m - 1;
	string ans = "";
	while(i >= 0 and j >= 0){
		if(choice[i][j] == 0){
			i--;
		} else if(choice[i][j] == 1){
			j--;
		}else{
			ans.pb(s[i]);
			i--;
			j--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	// cout << dp[n-1][m-1] << endl;
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