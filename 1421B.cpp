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
#define endl "\n"
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

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

//===============================================================================//
ll power(ll x, ll y) {
ll v = 1; while (y > 0) { if (y & 1)v = v * x; y = y >> 1; x = x * x;} return v;
}

bool isPowerOfTwo(ll x){
    return x && (!(x & (x-1)));     //check if the number is power of two or not
}

//===============================================================================//

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
        ll n;
        cin >> n;
        // cout << firstSide << ' ' << secondSide << ' '<< thirdSide << ' '<< fourthSide <<endl;
        string firstLine,secondLine,thirdLine,fourthLine;
        char first,second,third,fourth;
         
        if(n >= 4){
            cin >> firstLine;
            cin >> secondLine;
            for(int i=0;i<n-4;i++){
                string s;
                cin >> s;
            }
            cin >> thirdLine;
            cin >> fourthLine;
            first = firstLine[1];
            second = secondLine[0];
            third = thirdLine[thirdLine.length()-1];
            fourth = fourthLine[fourthLine.length()-2];
        }else{
            string fir;
            cin >> fir;
            first = fir[1];
            string sec;
            cin >> sec;
            second = sec[0];
            fourth = sec[2];
            string four;
            cin >> four;
            third = four[1];
        }
        

        if(firstLine[1] == secondLine[0]){
            if(thirdLine[thirdLine.length()-1] == fourthLine[fourthLine.length()-2]){
                if(firstLine[1] != fourthLine[fourthLine.length()-2]){
                    cout << 0 << endl;
                }
                else{
                    cout << "2" << endl;
                    cout << "1 2" << endl << "2 1" << endl; 
                }
            }
            else{
                cout << "1" << endl;
                if(firstLine[0] == fourthLine[fourthLine.length()-2]){
                    cout << n << ' ' << fourthLine.length()-2 << endl;
                }else{
                    cout << n-1 << ' ' << n << endl;
                }
            }
        }else{
            if(thirdLine[thirdLine.length()-1] == fourthLine[fourthLine.length()-2]){
                cout << "1" << endl;
                if(firstLine[1] == fourthLine[fourthLine.length()-2]){
                    cout << "2 1" << endl;
                }else{
                    cout << "1 2" << endl;
                }
            }else{
                if(fourthLine[fourthLine.length()-2] == firstLine[1]){
                    cout << "2" << endl;
                    cout << "1 2" << endl << n <<' ' << n-1 << endl;
                }else{
                    cout << "2" << endl;
                    cout << "2 1" << endl << n <<' ' << n-1 << endl;
                }
            }
        }
    }
return 0;
}