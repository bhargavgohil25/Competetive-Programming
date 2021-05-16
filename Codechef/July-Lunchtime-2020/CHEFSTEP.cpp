#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define pb push_back
#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        ll N, K;
        cin >> N >> K ;
        ll arr[N];

        for(int i=0;i<N;i++){
            cin >> arr[i];
        }

        ll sum=0;
        for(int i=0;i<N;i++){
            if(arr[i] % K == 0){
                cout << "1";
            }else{
                cout << "0";
            }
        }
        cout << "\n";
        
    }
    

return 0;
}