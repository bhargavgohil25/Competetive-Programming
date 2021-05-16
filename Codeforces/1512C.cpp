// Created by ... Bhargav Gohil
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
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x,y) cout << #x << '=' << x << ' ' << #y << '=' << y << endl
#define deb3(x,y,z) cout << #x << '=' << x << ' ' << #y << '=' << y <<  ' ' << #z << '=' << z << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define read(x) cin >> x[i]
#define endl "\n"
#define yup cout << "Yes" << endl
#define nope cout << "No" << endl
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define INF (int)1e9
#define PI 3.1415926535897932384626433832795

#define hcf(x,y)     __gcd(x,y)
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
typedef unordered_map<int, int> umap_ii;
typedef unordered_map<string, int> umap_si;
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


int main() {
	init();
	ll test = 1;
	cin >> test;
	while (test--) {
		int a, b;
		cin >> a;
		cin >> b;
		string s;
		cin >> s;
		int a0 = 0;
		int b1 = 0;
		int n = s.length();
		rep(i,0,n) {
			if (s[i] == '1')
				b1++;
			else if (s[i] == '0')
				a0++;
		}
		a0 = a - a0;
		b1 = b - b1;
		int l = 0;
		int h = n - 1;
		int c = 0;
		int d = 0;
		vi y;
		while (l < h){
			if (s[l] == '?' && s[h] != '?'){
				int x = s[h] - '0';
				if (x == 0 && a0 > 0){
					s[l] = '0';
					a0--;
				}
				else if (x == 1 && b1 > 0){
					s[l] = '1';
					b1--;
				}
				else{
					c = 1;
					break;
				}

			}
			else if (s[l] != '?' && s[h] == '?'){
				int x = s[l] - '0';
				if (x == 0 && a0 > 0)
				{
					s[h] = '0';
					a0--;
				}
				else if (x == 1 && b1 > 0)
				{
					s[h] = '1';
					b1--;
				}
				else
				{
					c = 1;
					break;
				}
			}
			else if (s[l] == '?' && s[h] == '?')
			{
				y.push_back(l);
				d = 1;
			}
			else if (s[l] != s[h])
			{
				c = 1;
				break;
			}
			l++;
			h--;
		}
		if (d == 1){
			for (int i = 0; i < y.size(); i++){
				if (a0 >= 2){
					s[y[i]] = '0';
					s[n - y[i] - 1] = '0';
					a0 -= 2;
				}
				else if (b1 >= 2){
					s[y[i]] = '1';
					s[n - y[i] - 1] = '1';
					b1 -= 2;
				}
				else{
					c = 1;
					break;
				}
			}
		}
		if (l == h){
			if (s[l] == '?'){
				if (a0 > 0){
					s[l] = '0';
					a0--;
				}
				else if (b1 > 0){
					s[l] = '1';
					b1--;
				}
			}
		}
		if (a0 == 0 && b1 == 0 && c == 0)
			cout << s << endl;
		else
			cout << "-1" << endl;

	}
	return 0;
}