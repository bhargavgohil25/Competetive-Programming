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
#ifdef ONLINE_JUDGE
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
#endif
}

//===============================================================================//
ll n;
/**
 * Let say we chose some 'mid' people to invite 1 2 3 4 5 .... k
 * now we can make a call that who can take those places,
 * so for 1 who can take this place ?
 * someone who can allow rest (k - 1) means, someone who can allow which allows atleast (k - 1) people greater than him...
 * i.e earliest person whose a[i] >= (k - 1)
 * and now same b[i] >= 0, why 0 ? 
 * because, 1 is richer than 0 people, and someone who allows atleast 0 people
 * therefore, b[i] >= 0
 * 
 * As we go further, for 2 3 4 5.... k
 * (k - 1) decreases by 1 (i.e k - 2, k - 3, ....)
 *  and
 * 0 increases by 1 (i.e 1, 2, 3, 4 ....)
 */ 

bool check(ll m, vector<int> &a, vector<int> &b) {
  // check for every people 

  // we want some a[i] which is atleast (m - i)
  // and some b[i] whicj is atleast i (increasing)

  ll first = m - 1;
  ll second = 0;
  ll cnt = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] >= first and b[i] >= second) {
      first--;
      second++;
      cnt++;
    }
  }

  return cnt >= m;
}


void solve(){
  cin >> n;
  vi a(n), b(n);

  rep(i,0,n) {
    cin >> a[i] >> b[i];
  }


  // Binary search on the maxi. number of people
  // that can be invited

  ll low = 1;
  ll high = n;
  ll ans = 1;

  while(low <= high) {

    ll mid = (high + low)/2;

    // if mid people can be invited
    // then we will try to maximize the mid
    // and check if its possible

    if(check(mid, a, b)){
      ans = mid;
      low = mid + 1;
    }else{
      high = mid - 1;
    }
  }
  cout << ans << endl;

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