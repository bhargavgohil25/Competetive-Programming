#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
    ll n;
    cin>>n;
    vector <int> arr;
    int i=1, j=2;
    while(j<=n){
        arr.push_back(j);
        j+=2;
    }
    while(i<=n){
        arr.push_back(i);
        i+=2;
    }

    if(n<=3 && n!=1){
        cout<<"NO SOLUTION";
    }
    else if(n == 1){
        cout<< 1;
    }else{
        for(int i=0; i<arr.size(); i++){
            cout<<arr[i]<<" ";
        }
    }
    


    
      

return 0;
}