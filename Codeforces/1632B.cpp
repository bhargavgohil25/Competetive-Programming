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

/*

  core idea to solve this problem is that

  we want to make the xor of two numbers as minimum as possible

  so, for eg two binary number are
  100110
  110010
  ^
  this MSB must be same then only it can cancel each other and will result in lower number

  suppose the case with
  101001
  010010
  ^
  this MSB is not same, means xor result will be 11011 which will be greater

  therefore the key idea is to keep all the numbers with MSB same together

  and those numbers are like [4,5,6,7] [8,9,10,11,12,13,14,15]

  for the problem ans, let say n = 11

  so the groups will be like [1][2,3][4,5,6,7][8,9,10,11]
  now we are left with 0.... and another thing to notice here was that

  if we merge two groups together, the end and start of two different group will result in maximum number

  like 8,9,10,11,4,5,6,7....

  here, number 11 ^ 4 will not work and will result in some large number
  therefore, we will reverse the arrangement and add 0 and the end of first ends


  like this, 11,10,9,8,0,7,6,5,4,3,2,1
                       ^
                       meaning add after the first number which is power of two 

*/



void solve(){
  int n;
  cin >> n;

  vector<int> ans;

  n--;

  bool isZeroAdded = false;

  for(int i = n; i >= 1; i--) {
    ans.push_back(i);
    if(__builtin_popcount(i) == 1 and isZeroAdded == false) {
      ans.push_back(0);
      isZeroAdded = true;
    }
  }

  for(auto i : ans) {
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