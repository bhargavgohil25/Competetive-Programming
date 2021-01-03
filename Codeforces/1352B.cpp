#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define pb push_back
#define INF 1e9
#define all(x) x.begin(), x.end()
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
//alt + ctrl + N

int power(int a, int n) { int res = 1; while(n){ if(n%2){
          res *= a;
          n--;
        }else{
           a *= a;
           n /= 2;
        }
    }
    return res;
}


bool even(int n, int k){
    int rem = n - 2*k;
    if(rem < 0){
        return 0;
    }
    if(rem & 1){
        return 0;
    }
    cout << "YES\n";
    for(int i=0; i<k-1; i++){
        cout << 2 << ' ';
    }
    cout << 2+rem << endl;
    
    return 1;
}

bool odd(int n, int k){
    int rem = n - k;
    if(rem < 0){
        return 0;
    }
    if(rem & 1){
        return 0;
    }
    cout << "YES\n";
    for(int i=0;i<k-1;i++){
        cout << 1 << ' ';
    }
    cout << 1+(n-k) << endl;
    return 1;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ll test;
    cin >> test;
    while(test--){
        int n,k;
        cin >> n >> k;
        if(even(n,k) || odd(n,k)){
            continue;
        }else{
            cout << "NO\n";
        }
    }
return 0;
}