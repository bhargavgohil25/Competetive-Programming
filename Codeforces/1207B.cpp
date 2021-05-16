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
    // cin >> test;
    while (test--) {
        ll n, m;
        cin >> n >> m;
        ll mat[n][m];
        ll ans[n][m];
        memset(ans,0,sizeof ans);
        vector<pair<int,int>>index;
        rep(i,0,n){
        	rep(j,0,m){
        		cin >> mat[i][j];
        	}
        }
        rep(i,0,n-1){
        	rep(j,0,m-1){
        		if(mat[i][j] == 1 and mat[i][j+1] == 1 and mat[i+1][j] == 1 and mat[i+1][j+1] == 1){
        			ans[i][j] = 1; 
        			ans[i][j+1] = 1; 
        			ans[i+1][j] = 1;
        			ans[i+1][j+1] = 1;
        			index.push_back({ i+1, j+1 });
        		}
        	}
        }
        bool flag = true;
        rep(i,0,n){
        	rep(j,0,m){
        		if(mat[i][j] != ans[i][j]){
        			flag = false;
        			break;
        		}
        	}
        }
        // rep(i,0,n){
        // 	rep(j,0,m){
        // 		cout << ans[i][j] << ' ';
        // 	}
        // 	cout << endl;
        // }
        if(flag == false) cout << -1 << endl;
        else if(!index.empty()){
        	cout << index.size() << endl;
        	for(auto i : index){
        		cout << i.ff << ' ' << i.ss << endl;
        	}
        	cout << endl;
        }else cout << 0 << endl;
    }
    return 0;
}