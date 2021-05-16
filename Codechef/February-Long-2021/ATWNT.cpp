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
const int M=1e5+5;
//===============================================================================//
ll power(ll x, ll y) {
ll v = 1; while (y > 0) { if (y & 1)v = v * x; y = y >> 1; x = x * x;} return v;
}

bool isPowerOfTwo(ll x){
    return x && (!(x & (x-1)));     //check if the number is power of two or not
}
ll ceil(ll a,ll b){ return (a+b-1)/b; }

vector<int>primes;
void createSieve(){
    bool prime[INF+1];
    memset(prime,true,sizeof(prime));
    for(int p=2;p*p<=INF;p++){
        if(prime[p]){
            for(int i=p*p;i<=INF;i+=p) prime[i] = false;
        }
    }
    for(int p=2;p<=INF;p++){
        if(prime[p]) primes.pb(p);
    }
}

long long mod(long long x){
    return ((x%M + M)%M);
}
long long add(long long a, long long b){
    return mod(mod(a)+mod(b));
}
long long mul(long long a, long long b){
    return mod(mod(a)*mod(b));
}
ll modPow(ll a, ll b){
    if(b==0) return 1LL;
    if(b==1) return a%M;
    ll res=1;
    while(b){
        if(b%2==1) res=mul(res,a);
        a=mul(a,a);
        b=b/2;
    }
    return res;
}


//===============================================================================//
// ll bfs(vector<ll>& a,ll v,ll w,ll n, ll ind){
//     bool one = (2*v>n or a[2*v]==-1);
//     bool two = (2*v+1>n or a[2*v+1]==-1);
//     if( one and two ) return w;
//     ll sum=0;
//     ll child = 0;
//     if(2*v<=n and a[2*v]!=-1) child++;
//     if(2*v+1<=n and a[2*v+1]!=-1) child++;
//     if(!(w%child)){
//         if(2*v<=n){
//             sum += bfs(a,2*v,w/child,n,ind+1);
//         }
//         if(2*v+1<=n){
//             sum+=bfs(a,2*v+1,w/child,n,ind+1);    
//         }
//     }
//     return sum;
// }
vi adj[M];
vi cnt(M,0);
void ipTree(vector<int>adj[],vector<int>&cnt,int n){
    rep(i,1,n){
        int x;
        cin >> x;
        adj[x].pb(i+1);
        cnt[x]++;
    }
}
void dfs(vector<int>adj[],vector<bool>&vis,ll v,ll w,ll &d){
    vis[v] = true;
    ll temp = cnt[v];
    if(temp!=0 and w%temp!=0){
        d+=w;
        return;
    }
    if(temp != 0){
        w = w/temp;
    }
    for(auto i : adj[v]){
        if(!vis[i]){
            dfs(adj,vis,i,w,d);
        }
    }

}


int main(){
    fastIO;
srand(chrono::high_resolution_clock::now().time_since_epoch().count());

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ll test = 1;
    //cin >> test;
    while(test--){
        ll x,q,w,v,n;
        cin >> n;
        ipTree(adj,cnt,n);
        cin >> q;
         while(q--){
            vector<bool>vis(n+1,false);
            ll d=0;
            ll v,w;
            cin>>v>>w;
            dfs(adj,vis,v,w,d);
            cout<<d<<endl;
        }
        // map<int,set<int>> m;
        // map<pair<int,int>,int> mp;
        // vl a(10001,-1);
        // a[1]=1;
        // repe(i,2,n){
        //     cin >> x;
        //     m[x].insert(i);
        //     int l = 2*x;
        //     int t = 2*x+1;
        //     if(a[l]==-1) a[l]=i;
        //     else a[t]=i;
        // }
        // cin >> q;
        // while(q--){
        //     cin>>v>>w;
        //     cout<<w-bfs(a,v,w,n,0)<<endl;
        // }    
    }
return 0;
}

