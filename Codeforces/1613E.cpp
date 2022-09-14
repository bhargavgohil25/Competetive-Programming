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
/**
 * 1) Observation is that if L is island i.e if it is covered with all free cells
 * then robots can never reach L
 * 2) All the points that dont come to point where it started on traversal
 * 3) Means, all the points which are the part of cycle in graph
 * 4) Find a cycle in a graph, and all the points that are not in the cycle is the ans...
 *
	#....
	..##L
	...#.
	.....
 * Another approach is to 

 */ 
// vector<vector<char>> mat;
// vector<vector<bool>> vis;
// ll n,m, labx, laby;
vi dirx = {1, -1, 0, 0};
vi diry = {0 ,0, -1, 1};
bool isSafe(int x,int y,int n,int m){
  if(x<0 or x>=n or y<0 or y>=m)return 0;
  return 1;
}

void dfs(vector<string>&grid,vector<vector<int>>&vis,int srcx,int srcy){
  int curr_x, curr_y, cnt=0;
  
  for(int i = 0; i <= 3; i++){
    curr_x = srcx + dirx[i]; 
    curr_y = srcy + diry[i];
    if(isSafe(curr_x, curr_y, grid.size(), grid[0].size())) {
      if(!vis[curr_x][curr_y] and grid[curr_x][curr_y] != '#') cnt++;
    }
  }
  // cout<<srcx<<" "<<srcy<<" "<<cnt<<endl;
  if(cnt <= 1){
    vis[srcx][srcy] = 1;
    grid[srcx][srcy] = '+';
    
    for(int i = 0; i <= 3; i++){
      curr_x = srcx + dirx[i]; 
      curr_y = srcy + diry[i];
      if(isSafe(curr_x,curr_y,grid.size(),grid[0].size()) and !vis[curr_x][curr_y] and grid[curr_x][curr_y] != '#'){
				dfs(grid,vis,curr_x,curr_y);
      }
    }
  }
}

void solve(){
	ll n,m,labx,laby;
	cin >> n >> m;
  vector<string>grid;
  string s;
  for(int i = 0; i < n; i++){
    cin >> s;
    grid.push_back(s);
  }
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(grid[i][j] == 'L') labx = i,laby = j;
    }
  }
  vector<vector<int>>vis(n,vector<int>(m,0));
  vis[labx][laby] = 1;
  for(int i = 0;i <= 3; i++){
    int curx = labx + dirx[i];
    int cury = laby + diry[i];

    if(isSafe(curx,cury,n,m) and !vis[curx][cury] and grid[curx][cury] != '#'){
      dfs(grid,vis,curx,cury);
    }
  }
  for(string s:grid) cout << s << "\n";

	return;
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