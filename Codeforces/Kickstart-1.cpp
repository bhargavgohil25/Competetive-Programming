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

void solve(ll test) {
    cout << "Case #" << test << ": ";

    ll mat[3][3];
    for (int i = 0; i < 3; i++) {
        cin >> mat[0][i];
    }

    cin >> mat[1][0] >> mat[1][2];

    for (int i = 0; i < 3; i++) {
        cin >> mat[2][i];
    }

    mat[1][1] = 0;
    
    ll cnt = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;

    if (mat[0][1] * 2 == (mat[0][0] + mat[0][2]))
        cnt++;
    if (2 * mat[1][0] == (mat[0][0] + mat[2][0]))
        cnt++;
    if (2 * mat[2][1] == (mat[2][0] + mat[2][2]))
        cnt++;
    if (2 * mat[1][2] == (mat[0][2] + mat[2][2]))
        cnt++;
    
    if ((mat[1][0] + mat[1][2]) % 2 == 0){
        mat[1][1] = (mat[1][0] + mat[1][2]) / 2;
        if (2 * mat[1][1] == (mat[0][0] + mat[2][2]))
            cnt1++;
        if (2 * mat[1][1] == (mat[0][2] + mat[2][0]))
            cnt1++;
        if (2 * mat[1][1] == (mat[0][1] + mat[2][1]))
            cnt1++;
    }
    else if ((cnt + cnt1) != 8 && (mat[0][1] + mat[2][1]) % 2 == 0){

        mat[1][1] = (mat[0][1] + mat[2][1]) / 2;
        if (2 * mat[1][1] == (mat[0][0] + mat[2][2]))
            cnt2++;
        if (2 * mat[1][1] == (mat[0][2] + mat[2][0]))
            cnt2++;
        if (2 * mat[1][1] == (mat[1][0] + mat[1][2]))
            cnt2++;
    }
    else if ((cnt + cnt2) != 8 && (mat[0][0] + mat[2][2]) % 2 == 0){
        mat[1][1] = (mat[0][0] + mat[2][2]) / 2;
        if (2 * mat[1][1] == (mat[0][1] + mat[2][1]))
            cnt3++;
        if (2 * mat[1][1] == (mat[0][2] + mat[2][0]))
            cnt3++;
        if (2 * mat[1][1] == (mat[1][0] + mat[1][2]))
            cnt3++;
    }
    else if ((cnt + cnt3) != 8 && (mat[0][2] + mat[2][0]) % 2 == 0){
        mat[1][1] = (mat[0][2] + mat[2][0]) / 2;
        if (2 * mat[1][1] == (mat[0][0] + mat[2][2]))
            cnt4++;
        if (2 * mat[1][1] == (mat[0][2] + mat[2][0]))
            cnt4++;
        if (2 * mat[1][1] == (mat[1][0] + mat[1][2]))
            cnt4++;
    }


    ll maxi = max({cnt1, cnt2, cnt3, cnt4});

    if (maxi == cnt1){
        mat[1][1] = (mat[1][0] + mat[1][2]) / 2;
    }
    else if (maxi == cnt2){
        mat[1][1] = (mat[0][1] + mat[2][1]) / 2;
    }
    else if (maxi == cnt3){
        mat[1][1] = (mat[0][0] + mat[2][2]) / 2;
    }
    else{
        mat[1][1] = (mat[0][2] + mat[2][0]) / 2;
    }
    cout << (mat[1][1] - 1) << "\n";
}

int main() {
    init();
    int t = 1;
    cin >> t;
    rep(i, 1, t + 1) solve(i);
    return 0;
}