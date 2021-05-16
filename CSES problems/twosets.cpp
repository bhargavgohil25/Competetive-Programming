#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int

#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
    ll n , wsum, sum = 0, px = 1;
    cin>>n;
    vector<int> x;
    if(n * (n+1) % 4 != 0 ){
        cout<< "NO";
        return 0;
    }

    wsum = n*(n+1)/4;
    if(wsum % n == 0){
        x.push_back(n);
        sum+=n;
    }

    while(wsum != sum){
        if(wsum % n == 0){
            x.push_back(n - px);
            x.push_back(px);
            sum += n;
        }
        else{
            x.push_back(n - px + 1);
            x.push_back(px);
            sum += n + 1;
        }
        px++;
    }
    sort(x.begin(), x.end());
    px = 0;
    string y;

    cout <<"YES\n" << x.size() << "\n";

    for(ll i=1;i<=n; i++){
        if(px < x.size() && x[px] == i){
            cout << i << " ";
            px++;
        }else{
            y += to_string(i) + " ";
        }
    }
    cout << "\n" << n-x.size() << "\n" << y;


return 0;
}