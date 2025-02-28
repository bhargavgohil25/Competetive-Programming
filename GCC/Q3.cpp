#include <bits/stdc++.h>
using namespace std;
/*
int rec(int sum,stack<int>s1,stack<int>s2){
    if(sum<=0) return -1;
    
    int ans1=0,ans2=0;
    
    if(!s1.empty()){
        int a = s1.top();
        s1.pop();
        ans1 = rec(sum-a,s1,s2)+1;
    }
    
    if(!s2.empty()){
        int a = s2.top();
        s2.pop();
        ans2 = rec(sum-a,s1,s2)+1;
    }
    
    return max(ans1,ans2);
}*/

int portfolio_profit_maximisation(int mx, vector<int> a, vector<int> b) {
    //write your code here
    stack<int>s1;
    stack<int>s2;
    
    for(auto i=a.rbegin(); i < a.rend(); i++)
        s1.push(*i);
        
    for(auto i = b.rbegin(); i < b.rend(); i++)
        s2.push(*i);
     
    // int ans = rec(maxSum,s1,s2);
    
    int cnt=0,sum=0;
    
    while(1){
        if(s1.size() > 0 && s2.size() > 0){
            if(sum + min(s1.top(),s2.top())>mx)
                break;
            sum += min(s1.top(),s2.top());
            cnt++;
            if(s1.top()<=s2.top()){
                s1.pop();
            }else{
                s2.pop();
            }
        }else if(s1.size()==0 && s2.size()>0){
            if(sum + s2.top() > mx) break;
            sum += s2.top();
            s2.pop();
            cnt++;
        }else if(s1.size() > 0){
            if(sum+s1.top() > mx) break;
            sum += s1.top();
            s1.pop();
            cnt++;
        }else{
            break;
        }
    }
    
    return cnt;
}



int main()
{
    ios::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int result = portfolio_profit_maximisation(x, a, b);
    cout << result;
    return 0;
}