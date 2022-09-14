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

bool UsedInRow(vector<vector<int>>& grid, int row, int num) {
	for(int col = 0; col < 9; col++) {
		if(grid[row][col] == num) {
			return true;
		}
	}
	return false;
}

bool UsedInCol(vector<vector<int>>& grid, int col, int num) {
	for(int row = 0; row < 9; row++) {
		if(grid[row][col] == num) {
			return true;
		}
	}
	return false;
}

bool UsedInBox(vector<vector<int>>& grid, int startRow, int startCol, int num) {
	for(int row = 0; row < 3; row++) {
		for(int col = 0; col < 3; col++) {
			if(grid[row + startRow][col + startCol] == num) return true;
		}
	}
	return false;
}

bool findUnassignedCell(vector<vector<int>>& grid, int& row, int& col) {
	// return true if a assigned cell is found
	// else return false
	for(row = 0; row < 9; row++) {
		for(col = 0; col < 9; col++) {
			if(grid[row][col] == 0) return true;
		}
	}
	return false;
}

bool isSafe(vector<vector<int>>& grid, int row, int col, int num) {

  return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row % 3, col - col % 3, num) && grid[row][col] == 0;

}

bool solveSudoku(vector<vector<int>>& grid) {

	int row, col;
	// searches the grid to find an entry that is still unassigned
	if(!findUnassignedCell(grid, row, col)) {
		return true;
	}

	for(int num = 1; num <= 9; num++) {
		// check if this num is safe to add at this position
		if(isSafe(grid, row, col, num)) {

			grid[row][col] = num;

			if(solveSudoku(grid)) {
				return true;
			}

			grid[row][col] = 0;
		}
	}

}

void solve(){
  vector<vector<int>> grid(9, vector<int>(9, 0));

  for(int i = 0; i < 9; i++) {
  	for(int j = 0; j < 9; j++) {
  		cin >> grid[i][j];
  	}
  }

  if(solveSudoku(grid)) {
  	for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				cout << grid[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
  }
  else cout << -1 << endl;

  return;
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