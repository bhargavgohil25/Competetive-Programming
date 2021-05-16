// Created by ...
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)
#define rrep(i,a,b) for(int i=b-1;i>=0;i--)
#define repe(i,a,b) for(int i=a; i<=b; i++)
#define ll long long
#define ui unsigned int
#define pb push_back
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x,y) cout << #x << '=' << x << #y << '=' << y << endl
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
const int M=1e9+7;
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

void init() {
    fastIO;
    #ifdef NameForIfDef
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
}

//===============================================================================//


int main(){
    init();
    ll test = 1;
    // cin >> test;
    while(test--){
        int n,m,k;
        cin >> n >> m >> k;
        int mat[n+1][m+1];
        int dp[n+1][m+1];

        memset(mat,0,sizeof mat);
        memset(dp,0,sizeof dp);

        // input Of 2-D matrix
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                cin >> mat[i][j];
            }
        }

        // // Copy Approach
        // for(int i=1;i<n+1;i++){
        //     for(int j=1;j<m+1;j++){
        //         dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i][j];
        //     }
        // }

        // Prefix 2-D Approach
        // Create a 2-D matrix 
        int sum = 0;
        for(int i=1;i<n+1;i++){
            int sumi = 0;
            for(int j=1;j<m+1;j++){
                sumi += mat[i][j];
                if(i > 0){
                    mat[i][j] = mat[i-1][j] + sumi;
                }else{
                    mat[i][j] = sumi;
                }
            }
        }

        // cout << "Prefix 2D approcach : \n" << endl;
        // for(int i=1; i<n+1; i++){
        //     for(int j=1; j<m+1; j++){
        //         cout << mat[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        // cout << "DP approcach : \n" << endl;
        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<=m; j++){
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';        

        int sizeOfSub = 1;
        int cnt = 0;
        int count2 = 0;
        while(sizeOfSub < n+1 and sizeOfSub < m+1){
            for(ll i=sizeOfSub; i<n+1; i++){
                for(ll j=sizeOfSub; j<m+1; j++){
                    cnt = mat[i][j] - mat[i][j - sizeOfSub] - mat[i - sizeOfSub][j] + mat[i - sizeOfSub][j - sizeOfSub];
                    // deb(cnt);
                    int sqr = sizeOfSub * sizeOfSub;
                    if((cnt/sqr) >= k){
                        // deb2(i,j);
                        // deb(c);
                        count2++;    
                    }
                }
            }
            sizeOfSub++;
            // break;
        }
        
        // cout << "\ncount1: " << count1 << endl;
        // cout << "\ncount2: " << count2 << endl;
        cout << count2 << endl;
    }
return 0;
}