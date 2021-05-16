#include<bits/stdc++.h>
using namespace std;
using ii = tuple<long, long>;
typedef long long ll;
int main(){
	ll n,x;
	cin>>n>>x;
	vector<ii> v;
	for(ll i=0;i<n;i++){
		ll a;
		cin>>a;
		v.push_back({a,i});
	}
	sort(v.begin(),v.end());
	ll i=0;
	ll j=n-1;
	while(i<j){
		if(get<0>(v[i])+get<0>(v[j])==x){
			cout<<get<1>(v[i])+1<<" "<<get<1>(v[j])+1;
			return 0;
		}
		if(get<0>(v[i])+get<0>(v[j])<x){
			i+=1;
		}
		else{
			j-=1;
		}
	}
	cout<<"IMPOSSIBLE\n";
return 0;
} 