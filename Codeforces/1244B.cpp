#include<bits/stdc++.h>
using namespace std;
    
int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
    int t,n,ans,ans1,ans2,pos,posbeg,posend;
    string s;
    cin>>t;
    
    for(int i=0;i<t;i++){
        cin>>n;
        cin>>s;
        ans1 = n;
        pos =0;ans2=0;ans=n;posbeg=0;posend=0;
        if(s[0]=='1' || s[n-1]=='1'){
            ans+=n;
        }
        else{
            for(int j=0;j<n;j++){
                if(s[j]=='1'){
                    posbeg = j+1;break;
                }
            }
            for(int j=n-1;j>=0;j--){
                if(s[j]=='1'){
                    posend = n-j;break;
                }
            }
            pos = min(posbeg,posend);
            if(pos>0){
                ans2 = max((n-pos+1),pos);
            }
            ans = max(ans1,(2*ans2));
        }
        
        cout<<ans<<endl;
    
    }
    
    return 0;
}