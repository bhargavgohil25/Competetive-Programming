// Created by ...
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)
#define repe(i,a,b) for(int i=a; i<=b; i++)
#define ll long long
#define ui unsigned int
#define pb push_back
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x,y) cout << #x << '=' << x << << #y << '=' << y << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define yup cout << "Yes" << endl
#define nope cout << "No" << endl
#define read(x) cin >> x[i]
#define endl "\n"
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
//alt + ctrl + N
#define M 10006
//===============================================================================//
// ll power(ll x, ll y) {
// ll v = 1; while (y > 0) { if (y & 1)v = v * x; y = y >> 1; x = x * x;} return v;
// }

// bool isPowerOfTwo(ll x){
//     return x && (!(x & (x-1)));     //check if the number is power of two or not
// }
// ll ceil(ll a,ll b){ return (a+b-1)/b; }

// vector<int>primes;
// void createSieve(){
//     bool prime[INF+1];
//     memset(prime,true,sizeof(prime));
//     for(int p=2;p*p<=INF;p++){
//         if(prime[p]){
//             for(int i=p*p;i<=INF;i+=p) prime[i] = false;
//         }
//     }
//     for(int p=2;p<=INF;p++){
//         if(prime[p]) primes.pb(p);
//     }
// }

// long long mod(long long x){
//     return ((x%M + M)%M);
// }
// long long add(long long a, long long b){
//     return mod(mod(a)+mod(b));
// }
// long long mul(long long a, long long b){
//     return mod(mod(a)*mod(b));
// }
// ll modPow(ll a, ll b){
//     if(b==0) return 1LL;
//     if(b==1) return a%M;
//     ll res=1;
//     while(b){
//         if(b%2==1) res=mul(res,a);
//         a=mul(a,a);
//         b=b/2;
//     }
//     return res;
// }


//===============================================================================//
//initialize the DP
// ll dp[M][M];


ll backtrk(ll n, ll egg, ll choco, ll A, ll B, ll C) {
   
  if(n <= 0) return 0;
  // if(egg < 2 and choco == 0 and n != 0) return 10e7;
  // if(egg == 0 and choco < 3 and n != 0) return 10e7;
  // if(egg == 0 and choco == 0) return 10e7;
  ll ans = 1e15;

  ans = (2*n <= egg ? min(ans,n*A) : ans);    // if we give everyone only ommellete
  ans = (3*n <= choco ? min(ans,n*B) : ans);  // if we give everyone only chocalate shake
  ans = ((n <= egg and n <= choco) ? min(ans,n*C) : ans);    // if we give evryone only cake

 //  ll first = 1e5+6;
 //  ll second = 1e5+6;
 //  ll third = 1e5+6;
 //  if(dp[egg][choco] == -1){
 //   if(egg >= 2){
  //    if(dp[egg-2][choco] == -1){
  //    first = backtrk(n-1, egg-2, choco, A, B, C);
  //    first += A;
  //    }else first = dp[egg-2][choco];
  // }

  // check for optimal solution

  if(((choco - n)/2 >= 1) and ((choco - n)/2 >= (n-egg))) {
    ll temp;
    if(B < C) temp=min(n-1,(choco-n)/2);
    else temp=max(1LL,n-egg);
    ans = min(ans,(B-C) * temp + n*C);
  }

  if(egg - n >= 1 and egg - n >= n-choco) {
    ll temp;
    if(A - C < 0) temp=min(n-1,egg-n);
    else temp=max(1LL,n-choco);
    ans = min(ans,(A-C)*temp + n*C);
  }
  // if(choco >=3){
  //    if(dp[egg][choco-3] == -1){
  //    second = backtrk(n-1, egg, choco-3, A, B, C);
  //    second += B;  
  //    }else second = dp[egg][choco-3];
  // }
  if((egg >= 2) and (egg/2 >= (3*n-choco+2)/3)){
    ll temp;
    if(A - B < 0) temp=min(n-1LL,egg/2);
    else temp=max(1LL,(3*n-choco+2)/3);
    ans = min(ans,(A-B)*temp+n*B);
  }

  // check if we able to serve more students 
  // on the basis of available items
  if(n >= 3 and egg >= 3 and choco >= 4){
    ll sum = A+B+C; 
    ans = min(ans, sum + backtrk(n-3,egg-3,choco-4,A,B,C));
  }
  return ans;
  
}

int main(){
    fastIO;
srand(chrono::high_resolution_clock::now().time_since_epoch().count());

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ll test = 1;
    cin >> test;
    while(test--){
        ll n, egg, choco; 
        ll A,B,C;
        cin >> n >> egg >> choco >> A >> B >> C;
        ll ans = backtrk(n, egg, choco,A,B,C);
        cout << (ans == 1e15 ? -1 : ans) << endl;
    }
return 0;
}