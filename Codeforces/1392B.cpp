#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)
#define repe(i,a,b) for(int i=a; i<=b; i++)
#define ll long long
#define ui unsigned int
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl "\n"
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
typedef unordered_map<string, int> umap_si;
//alt + ctrl + N

//====================//
ll power(ll x, ll y) {
ll v = 1; while (y > 0) { if (y & 1)v = v * x; y = y >> 1; x = x * x;} return v;
}

bool isPowerOfTwo(ll x){
    return x && (!(x & (x-1)));     //check if the number is power of two or not
}

int findMaximum(vector<ll> &arr, int low, int high)  
{  
  
    /* Base Case: Only one element is present in arr[low..high]*/
    if (low == high)  
        return arr[low];  
      
    /* If there are two elements and first is greater then  
        the first element is maximum */
    if ((high == low + 1) && arr[low] >= arr[high])  
        return arr[low];  
      
    /* If there are two elements and second is greater then  
        the second element is maximum */
    if ((high == low + 1) && arr[low] < arr[high])  
        return arr[high];  
      
    int mid = (low + high)/2; /*low + (high - low)/2;*/
      
    /* If we reach a point where arr[mid] is greater than both of  
        its adjacent elements arr[mid-1] and arr[mid+1], then arr[mid]  
        is the maximum element*/
    if ( arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])  
        return arr[mid];  
      
    /* If arr[mid] is greater than the next 
        element and smaller than the previous  
        element then maximum lies on left side of mid */
    if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])  
        return findMaximum(arr, low, mid-1);  
          
        // when arr[mid] is greater than arr[mid-1] 
        // and smaller than arr[mid+1] 
    else 
        return findMaximum(arr, mid + 1, high);  
}  


int main(){
    fastIO;

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ll test;
    cin >> test;
    while(test--){
        ll n,k;
        cin >> n >> k;
        vl v(n);
        rep(i,0,n){
            cin >> v[i];
        }
        ll m = findMaximum(v,0,n-1);
        //cout << m << endl;
        rep(i,0,n){
            v[i] = m-v[i];
        }
        m = findMaximum(v,0,n-1);
        if(k%2 == 0){
            for(auto i : v){
                cout << i << ' ';
            }
        }else{
            rep(i,0,n){
                cout << m - (v[i])  << ' ';
            }
        }
        cout << endl ;
    }
return 0;
}