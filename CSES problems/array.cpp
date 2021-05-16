#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
    ll N;
    cin>>N;
    ll arr[N];
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    ll sum = 0;
    for(int i=0; i<N - 1; i++){
        if(arr[i] > arr[i+1]){
            sum += abs(arr[i] - arr[i+1]);
            arr[i+1] = arr[i];
        }

    }
    cout<<sum;


return 0;
}