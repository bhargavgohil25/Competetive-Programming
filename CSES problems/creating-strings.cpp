#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define all(x) x.begin(),x.end()
#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
    string x;
    cin>>x;
    sort(all(x));

    vector <string> v;
    do{
        v.push_back(x);
    } 
    while(next_permutation(all(x)));

    cout<<v.size() << "\n";
    for(auto i : v){
        cout<<i<<"\n";
    }



return 0;
}