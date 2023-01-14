#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	vector<int>a(n);
	
	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	map<int,int>mp;

	int curr = 0;
	int maxLen = 0;

	for(int i=0; i<n; i++){
		curr += a[i];

		if(a[i] == 0 and maxLen == 0){
			maxLen = 1;
		}

		if(curr == 0) maxLen = i+1;

		if(mp.count(curr)){
			maxLen = max(maxLen, i - mp[curr]);
		}else{
			mp[curr] = i;
		}
	}

	cout << maxLen << endl;

	return 0;
}