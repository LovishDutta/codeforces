#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,a,b;
        cin>>n>>a>>b;
        bool ans=true;
        if(b>a){
            if((n-b)%2) ans=false;
        } 
        else if(b<a){
            if((n-a)%2==0&&(a-b)%2==0) ans=true;
            else ans=false;
        }
        else if(a==b){
            if((n-a)%2!=0) ans=false;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}