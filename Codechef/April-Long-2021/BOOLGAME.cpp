// Created by ... Bhargav Gohil
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(int i=b-1;i>=0;i--)
#define repe(i,a,b) for(int i=a; i<=b; i++)
#define ll long long
#define ld long double
#define ui unsigned int
#define pb push_back
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x,y) cout << #x << '=' << x << #y << '=' << y << endl
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

vector<int>primes;
void createSieve() {
    bool prime[INF + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= INF; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= INF; i += p) prime[i] = false;
        }
    }
    for (int p = 2; p <= INF; p++) {
        if (prime[p]) primes.pb(p);
    }
}

long long mod(long long x) {
    return ((x % M + M) % M);
}
long long add(long long a, long long b) {
    return mod(mod(a) + mod(b));
}
long long mul(long long a, long long b) {
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

void init() {
    fastIO;
#ifdef NameForIfDef
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
}

//===============================================================================//
ll n,m,k;
vi x(m),y(m),d(m),g(n),pref(n);

void calculate_prefix(vector<int>&cases){
	int siz = cases.size();
	pref.clear();
	// pref.resize();
	pref[0] = cases[0];
	for(int i=1;i<siz;i++){
		pref[i] = pref[i-1] + cases[i];
	}
}


void calculate(vector<int> &cases){
	
	for(int i=0;i<cases.size();i++){

	}
}



void getAll(int n,vector<int>&cases,int i){
	if(i == n){
		calculate_prefix(cases);
		calculate(cases);
		return;
	}

	cases[i] = 0;
	getAll(n,cases,i+1);

	cases[i] = 1;
	getAll(n,cases,i+1);
}



int main() {
    init();
    ll test = 1;
    cin >> test;
    while (test--) {
        ll n,m,k;
        cin>>n>>m>>k;
        vector<ll> g(n+1);
        rep(i,0,n){
            cin>>g[i+1];
        }
        k = 1;
        vector<vector<pair<ll,ll>>> arr(n+1);
        rep(i,0,m){
            ll u,v,d;
            cin>>u>>v>>d;
            arr[u].pb({ i,d });
            arr[v].pb({ i,d });
        }
        vector<vector<pair<ll,ll>>> dp(n+1);
        dp[0].pb({ 0,0 });
        for(ll i=1;i<=n;i++){
            vector<pair<ll,ll>> temp;
            temp.insert(temp.end(),all(dp[i-1]));
            ll curr = 0,mask = 0;
            set<ll> open;
            for(ll j=i;j>=1;j--){
                curr+=g[j];
                mask = mask ^ (1LL<<j);
                for(auto & [idx,w]:arr[j]){
                    if(open.count(idx)){
                        curr+=w;
                    }
                    else{
                        open.insert(idx);
                    }
                }
                if(j>1){
                    for(auto & [val,old_mask]:dp[j-2]){
                        temp.pb({  val+curr,mask^old_mask });
                    }
                }
                else{
                    temp.pb({ curr,mask });
                }
            }
            sort(all(temp));
            reverse(all(temp));
            set<ll> sel;
            ll filled=0;
            for(ll j=0;j<temp.size() && filled<k;j++){
                if(sel.count(temp[j].ss)) continue;
                dp[i].pb(temp[j]);
                filled++;
                sel.insert(temp[j].ss);
            }
        }
        rep(i,0,k){
            cout<<dp[n][i].ff<<' ';
        }
        cout<<endl;
    }
    return 0;
}