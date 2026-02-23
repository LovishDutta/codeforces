#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int x,y;
        cin>>x>>y;
        if((x+4*y)>=0&&(x+4*y)%3==0&&(x+4*y)/3-2*y>=0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}