#include<iostream>
#include <vector>
#include<algorithm> 

using namespace std;

#define ll long long;


int main(){
    int test;
    cin>>test;

    while (test--)
    {
        vector<int> list;
        int N;
        cin>>N;
        int check = 0;
        for(int i=0; i<N; i++){
            for(int j=N*i+1; j<(N*i)+1; j++){
                list.push_back(j);
            }
            if(check == 0){
                for(int k=0; k<list.size(); k++){
                    cout<<list[k]<<" ";
                }
                cout<<"\n";
                list.clear();
                check = 1;
            }else{
                reverse(list.begin() + 0, list.begin() + list.size());
                for(int l=0; l<list.size(); l++){
                    cout<<list[l]<<" ";
                }
                cout<<"\n";
                list.clear();
                check = 0;
            }
        }
    }
    
}













