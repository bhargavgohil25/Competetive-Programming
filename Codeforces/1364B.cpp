#include<bits/stdc++.h> // 54 68 "Baklol, Take it easy"
using namespace std;
using ll = long long int;
using ld = long double;

#define rep(x, k, n)        for(int x = (k); x <= (n); ++x)
#define rept(x, k, n)       for(int x = (k); x < (n); ++x)
#define repr(x, k, n)       for(int x = (k); x >= (n); --x)
#define pb                  push_back
#define siz(x)              ((int)(x).size())
#define o2(x)               ((x) * (x))
#define all(x)              (x).begin(), (x).end()
#define clr(x, k)           memset(x, k, sizeof(x)) // 0, -1
#define printv(v, k, n)     rep(i, k, n) cout << v[i] << " \n"[i==n];
#define print2dv(V,k,n,m)   rep(j, k, n) printv(V[j], k, m);
#define report(x)           cout << ((x) ? "Yes" : "No") << '\n'
#define setbits(x)          __builtin_popcountll(x)
#define inf                 INT_MAX
#define ninf                INT_MIN
#define int                 long long // "be carefull"

typedef vector<int>         vi;
typedef pair<int, int>      pii;

template <typename Arg1>
void debug_out(const char* name, Arg1&& arg1){
    cerr << name << " = " << arg1  << " ]" << "\n";
}

template <typename Arg1, typename... Args>
void debug_out(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " = " << arg1 << ",";
    debug_out(comma+1, args...);
}

#ifdef LOCAL
#define deb(...) cerr << "[ ", debug_out(#__VA_ARGS__, __VA_ARGS__)
#define debv(v, k, n)       rep(i, k, n) cerr << v[i] << " \n"[i==n];
#define deb2dv(V, k, n, m)  rep(j, k, n) debv(V[j], k, m);
#define line                rep(i, 0, 50){ cerr << '-'; } cerr << '\n'
#else
#define deb(...)
#define debv(v, k, n)
#define deb2dv(V, k, n, m)
#define line
#endif

const int mod = 1e9 + 7; // 998244353;
const int N = 3e5 + 5, M = 2e5 + 5;

/*/------------------------------ CODE BEGINS ------------------------------/*/

int n;
int v[N];

void Solve_main() {

    cin >> n;
    rep(i, 1, n) cin >> v[i];
    vi res;
    res.pb(v[1]);
    int i = 1;
    while(i != n){
        if(v[i+1] > v[i]){
            while(i < n && v[i+1] > v[i]) i++;
        }
        else if(v[i+1] < v[i]){
            while(i < n && v[i+1] < v[i]) i++;
        }
        res.pb(v[i]);
    }
    cout << siz(res) << '\n';
    // deb(res);
    // deb(n);
    printv(res, 0, siz(res)-1);
}

/*/------------------------------- CODE ENDS -------------------------------/*/

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    // cout << setprecision(12) << fixed;
    int tc = 1;
    cin >> tc;
    for(int i = 1; i <= tc; i++) {
        Solve_main();
#ifdef LOCAL
        // BRUTE_FORCE();
#endif
    }

    cerr << "[time:" << 1.0*clock()/CLOCKS_PER_SEC << "s] ";
    return 0;
}

/*
-> edge cases, n = 1 ?
-> binary search ?
-> time complexity - 1 sec : 4e8 will work but risky.
-> space complexity - 256 mb : 6e7(int), 3e7(ll), 2e8(bool, char), will work.
-> entire input - multiple testcases.
-> mod : sort ?, mint, remove #define int.
-> Iterative > Recursive.
-> clear - global variables.
-> builtin fuction - add ll.
-> Move on - if completely_stuck > 30 minute.
-> Submit - right file.
*/