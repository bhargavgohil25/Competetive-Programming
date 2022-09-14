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

ll dp[5001][5001];

int solveDP(int i, int j, string &s, string &p){
    // Base Case
	
	// what this base means is that, if the string s is exhausted like it reached the end of the string or the string p reached the end of the string
	// then we have to add/ remove some no. of characters from the string
	// like if s is exhausted before the p... then we have to add some no. of acharacters to string s and that number is.. (p.lenght() - j)
	// or if the p is exhausted before the s then we have to remove some characters from the s and the no. of those characters are (s.length() - i)
	// and we will return the max of those

	if(s.length() == i || p.length() == j){
		return max(s.length() - i, p.length() - j);
	}

	// if we already have the answer for that substring than we will not compute futher and return

	if(dp[i][j] != -1){
		return dp[i][j];
	}

// I just confirmed this thing from my old friend
	int ans;
	if(s[i] == p[j]) { // no when both the characters are same we cant do anything we just want to return from there
		// or go to the next charcters..
		ans = solveDP(i+1, j+1, s, p); 
	}else{
		// 1) When we add a character in the string we confirm that the current character in the corresponding string is equal to this string
			// and we left with the original 's' string as another character becomes equal to first charater of 'p'
			// (Pj)(Si Si+1 Si+2 ..... Sn)
			// (Pj)(Pj+1 Pj+2 Pj+3 .....Pm)
			// so we have equalize the first character of both the string by adding 'pj'th character to the 's'...
		
		// 2) Same like that we have removed the character at the position 'i' in 'S' and 'j' in 'P'.. and we will compute the further string by calling the solveDP(i+1, j+1)
		
		// 3) When we Replace the character at some position we are confirming that thw character at that position is same... 
		// Like for example
		// initial -->   (Si Si+1 Si+2 Si+3 ... Sn)
		//               (Pj Pj+1 Pj+2 Pj+3 ... Pm)
		// After Replace (Pj Si+1 Si+2 Si+3 ... Sn)
		//               (Pj Pj+1 Pj+2 Pj+3 ... Pm)
		// So after replacement we can see that the computation at that position is done and we have to move further
		// So we called solveDP(i+1, j+1)
		
		int option1 = 1 + solveDP(i, j+1, s, p);  // add operation
		int option2 = 1 + solveDP(i+1, j, s, p);  // remove operation
		int option3 = 1 + solveDP(i+1, j+1, s, p);// replace operation
		ans = min( { option1, option2, option3 });
	}

	return dp[i][j] = ans;
}

int main() {
    init();
    ll test = 1;
    // cin >> test;
    while (test--) {
    	string s,p;
    	memset(dp, -1, sizeof dp);
    	cin >> s >> p;
        cout << solveDP(0,0,s,p) << endl;
    }
    return 0;
}