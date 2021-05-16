#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
	
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
	string s;
	cin >> s;
	if(s[0] == s[1] && s[1] == s[2] && s[2] == s[0]) cout << "Won";
	else cout << "Lost";
	return 0;
}