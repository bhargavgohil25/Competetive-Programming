#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string swap(string s, int left, int i){
	char t = s[left];
	s[left] = s[i];
	s[i] = t;
	return s;
}

void findPer(string s, int left,int right){
	if(left == right) {
		cout << s << endl;
	}else{	
		for(int i=left;i<=right;i++){
			s = swap(s,left,i);
			findPer(s,left+1,right);
			s = swap(s,left,i);
		}
	}
}

int main(){
	string s;
	cin >> s;

	findPer(s,0,s.length()-1);
	return 0;
}