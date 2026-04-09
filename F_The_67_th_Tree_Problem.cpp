#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int x,y;
    cin>>x>>y;
    int t=x+y;
    int maxi=t/2;
    if(x>maxi){
        cout<<"NO"<<endl;
        return;
    }
    if(t%2==0){
        if(x==0){
            cout<<"NO"<<endl;
            return;
        }
        x--;
    }
    else{
        y--;
    }
    cout<<"YES"<<endl;
    int temp=2;
    for(int i=0;i<x;i++){
        cout<<"1 "<<temp<<endl;
        cout<<temp++<<" "<<temp++<<endl;
        y--;
    }
    for(int i=0;i<y;i++){
        cout<<"1 "<<temp++<<endl;
    }
}

signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        solve();
    }
}