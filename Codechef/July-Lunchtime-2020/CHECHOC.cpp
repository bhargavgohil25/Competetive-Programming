#include <bits/stdc++.h>
#include <iostream>

#define ll long long
#define ui unsigned int
#define pb push_back

#define INF 1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        if(y>=2*x){
            cout<<x*n*m<<"\n";
        }
        else{
            if(n==1 && m==1)
                cout<<x<<"\n";
            else if(y<=x)
                cout<<((m*n+1)/2)*y<<"\n";
            else
                cout<<((m*n+1)/2)*x+((m*n)/2)*(y-x)<<"\n";
        }
    }

return 0;
}