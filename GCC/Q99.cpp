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

template<class ForwardIt, class T, class Compare>
ForwardIt low_bound(ForwardIt first, ForwardIt last, const T& value, Compare comp)
{
	ForwardIt it;
	typename std::iterator_traits<ForwardIt>::difference_type count, step;
	count = std::distance(first, last);

	while (count > 0)
	{
		it = first;
		step = count / 2;
		std::advance(it, step);

		if (comp(*it, value))
		{
			first = ++it;
			count -= step + 1;
		}
		else
			count = step;
	}

	return first;
}

//===============================================================================//
int N;
string matrix[55];
vector<int> rowDollar[55];
vector<int> colDollar[55];
// int dp[50][50][50][50];

vector<vector<vector<vector<int>>>> dp(51, vector<vector<vector<int>>>(51, vector<vector<int>>(51, vector<int>(51, -1))));


bool checkBound(int rStart, int cStart, int rEnd, int cEnd) {
	if (rStart >= N or cStart >= N or rEnd < 0 or cEnd < 0) {
		return false;
	}
	return true;
}

int getMinSide(int rStart, int rEnd, int cStart, int cEnd) {
	int iMaxi = -1, iMini = 60;
	int jMaxi = -1, jMini = 60;
	int cnt = 0;

	if (!checkBound(rStart, cStart, rEnd, cEnd)) return 0;

	if (dp[rStart][rEnd][cStart][cEnd] != -1) return dp[rStart][rEnd][cStart][cEnd];

	int &ret = dp[rStart][rEnd][cStart][cEnd];

	if (rStart > rEnd or cStart > cEnd) {
		return ret = 0;
	}

	if (rStart == rEnd or cStart == cEnd) {
		int cnt = 0;
		if (rStart == rEnd) {
			// getting the distance between dollar position of last and first dollar in a row
			cnt = ub(all(rowDollar[rStart]), cEnd) - lb(all(rowDollar[rStart]), cStart);
		}

		if (cStart == cEnd) {
			// getting the distance between dollar position of last and first dollar in a column
			cnt = ub(all(colDollar[cStart]), rEnd) - lb(all(colDollar[cStart]), rStart);
		}

		return ret = cnt;
	}

	for (int i = rStart; i <= rEnd; i++) {
		if (!rowDollar[i].empty()) {
			auto it = lb(all(rowDollar[i]), cStart);

			if (it == rowDollar[i].end() or * it > cEnd) continue;
			else {
				iMini = i;
				cnt++;
			}

			if (iMini != 60) {
				break;
			}
		}
	}
	for (int i = rEnd; i >= rStart; i--) {
		if (!rowDollar[i].empty()) {
			auto it = lb(all(rowDollar[i]), cStart);
			if (it == rowDollar[i].end() or * it > cEnd) continue;
			else {
				iMaxi = i;
				cnt++;
			}
			if (iMaxi != -1) {
				break;
			}
		}
	}
	for (int i = cStart; i <= cEnd; i++) {
		if (!colDollar[i].empty()) {
			auto it = lb(all(colDollar[i]), rStart);
			if (it == colDollar[i].end() or * it > rEnd) continue;
			else {
				jMini = i;
				cnt++;
			}
			if (jMini != 60) {
				break;
			}
		}
	}
	for (int i = cEnd; i >= cStart; i--) {
		if (!colDollar[i].empty()) {
			auto it = lb(all(colDollar[i]), rStart);
			if (it == colDollar[i].end() or * it > rEnd) continue;
			else {
				jMaxi = i;
				cnt++;
			}

			if (jMaxi != -1) {
				break;
			}
		}
	}

	if (cnt > 2) {
		int width = jMaxi - jMini;
		int height = iMaxi - iMini;

		ret = max(width, height) + 1;

		int rowMiddle = (iMini + iMaxi) / 2;
		int columnMiddle = (jMini + jMaxi) / 2;

		int leftValue = getMinSide(iMini, iMaxi, jMini, columnMiddle) + getMinSide(iMini, iMaxi, columnMiddle + 1, jMaxi);
		int rightValue = getMinSide(iMini, rowMiddle, jMini, jMaxi) + getMinSide(rowMiddle + 1, iMaxi, jMini, jMaxi);

		return ret = min(min(ret, leftValue), rightValue);
	}

	return ret = 2;
}
void solve() {
	cin >> N;
	// memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) {
		cin >> matrix[i];
	}

	vector<int> r, c;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == '$') {
				rowDollar[i].push_back(j);
				r.push_back(i);
				// iMini = min(iMini, i);
				// iMaxi = max(iMaxi, i);
			}

			if (matrix[j][i] == '$') {
				colDollar[i].push_back(j);
				c.push_back(i);
				// jMini = min(jMini, i);
				// jMaxi = max(jMaxi, i);
			}
		}
	}

	if (r.size() > 2) {
		int iMini = r[0];
		int iMaxi = r.back();
		int jMini = c[0];
		int jMaxi = c.back();

		int ans = N;

		// int rStart, int rEnd, int cStart, int cEnd

		repe(i, iMini, iMaxi) {
			repe(j, jMini, jMaxi) {
				ans = min(ans,
				          // iMini and jMini are static points or the corner point (top-right corner)
				          getMinSide(iMini, i, jMini, j) +
				          getMinSide(i + 1, iMaxi, jMini, j) +
				          getMinSide(iMini, i, j + 1, jMaxi) +
				          getMinSide(i + 1, iMaxi, j + 1, jMaxi)
				         );
			}
		}
		cout << ans;
		return;
	}

	cout << r.size();
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