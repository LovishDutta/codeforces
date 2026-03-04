#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,q;
        cin>>n>>q;
        int val=(n+q)/(q+1);
        cout<<val/2<<endl;
    }
}