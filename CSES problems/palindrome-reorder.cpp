#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int

#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){

    string x;
    cin>>x;

    map <char, string> m;

    for(char c : x){
        if(m.count(c)){
            m[c] += c;
        }else{
            m[c] = c;
        }
    }

    string odd = "", fir = "", las = "";
    for(auto i : m){
        if(i.second.length() % 2 == 1 && odd != ""){
            cout<<"NO SOLUTION";
            return 0;
        }else if(i.second.length() % 2 == 1){
            odd = i.second;
        }else{
            fir = i.second.substr(0, i.second.length()/2) + fir;
            las = las + i.second.substr(0, i.second.length()/2);
        }
    }

    cout<<las  + odd +  fir;

return 0;
}