#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int x;
        cin>>x;
        if(x>=(3+4+8+16+32+64)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}