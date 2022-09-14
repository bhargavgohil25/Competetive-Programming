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
// vi arr;
// vi tempLeft, tempRight;


void merge(vector<int>& arr, int const left, int const mid, int const right) {
  auto const subArrOne = mid - left + 1;
  auto const subArrTwo = right - mid;

  vi tempLeft(subArrOne), tempRight(subArrTwo);

  // create 2 temp vectors
  // tempLeft.resize(subArrOne), tempRight.resize(subArrTwo);

  // copy data to those temp vectors
  for(auto i = 0; i < subArrOne; i++){
    tempLeft[i] = arr[left + i];
  }

  for(auto i = 0; i < subArrTwo; i++) {
    tempRight[i] = arr[mid + 1 + i];
  }

  auto indexOfSubarrayOne = 0; // initial index of first sub-array
  auto indexOfSubarrayTwo = 0; // initial index of second sub-array

  int indexOfMergedArray = left; // initial index of merged array

  while(indexOfSubarrayOne < subArrOne and indexOfSubarrayTwo < subArrTwo) {
    if(tempLeft[indexOfSubarrayOne] <= tempRight[indexOfSubarrayTwo]) {
      arr[indexOfMergedArray] = tempLeft[indexOfSubarrayOne];
      indexOfSubarrayOne++;
    }else{
      arr[indexOfMergedArray] = tempRight[indexOfSubarrayTwo];
      indexOfSubarrayTwo++;
    }
    indexOfMergedArray++;
  }


  // Copy all the remaining elements of left vector<>, if there are any
  
  while(indexOfSubarrayOne < subArrOne) {
    arr[indexOfMergedArray] = tempLeft[indexOfSubarrayOne];
    indexOfSubarrayOne++;
    indexOfMergedArray++;
  }

  // Copy all the remaining elements of the right vector<>, if there are any

  while(indexOfSubarrayTwo < subArrTwo) {
    arr[indexOfMergedArray] = tempRight[indexOfSubarrayTwo];
    indexOfSubarrayTwo++;
    indexOfMergedArray++;
  }

}

void mergeSort(vector<int>& arr, int const begin, int const end) {
  if(begin >= end) {
    return;
  }
  auto mid = begin + (end - begin) / 2;

  debug(mid);
  
  mergeSort(arr, begin, mid);
  mergeSort(arr, mid + 1, end);
  
  merge(arr, begin, mid, end);
}

void solve(){
  int n;
  cin >> n;
  vi arr(n);
  // arr.resize(n);

  rep(i,0,n) cin >> arr[i];

  mergeSort(arr, 0, n - 1);

  debug(arr);
  for(auto i : arr) {
    cout << i << ' '; 
  }

}

int main() {
  init();
  ll test = 1;
  // cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}