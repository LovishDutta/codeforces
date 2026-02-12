#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,k;
        cin>>n;
        cin>>k;
        string s;
        cin>>s;
        int num0=0,num1=0;
        for(auto val:s){
            if(val=='0') num0++;
            else num1++;
        }
        for(int i=1;i<=k;i++){
             if(num1>num0){
            num1-=2;
        }
        else num0-=2;
        }
        if(num1==num0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}