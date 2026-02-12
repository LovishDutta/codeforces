#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int p,q;
        cin>>p>>q;
        if(p>=q){
            cout<<"Alice"<<endl;
            continue;
        }
        if(3*p-2*q>=0) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
}