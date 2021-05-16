#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
long long ceil(ll a,ll b){ return (a+b-1)/b; }
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

	int t;
	double x;
	cin >> t;
	while(t--){
		ll n;
	    cin >> n >> x;
	    double a[n+5];
	    ll max = 0;
	    ll min = 0;
	    for(int i=0;i<n;i++){
	    	cin >> a[i];
	    	max = max + ceil(a[i]/x);
	    	min = min + a[i];
	    }
	    ll val = ceil(min/x);
	    cout << val << ' ' << max << endl;
	}
	return 0;
}