#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
    ll N;
    cin >> N;
    int arr[N - 1];
    int freq[200001] = {0};
    for(int i=0; i<N - 1; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }

    sort(arr, arr+N);
    for(int i=1; i<200001; i++){
        if(freq[i] == 0){
            cout<<i;
            break;
        }
    }

return 0;
}