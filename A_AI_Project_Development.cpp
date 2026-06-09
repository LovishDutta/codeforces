#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        double n,x,y,z;
        cin>>n>>x>>y>>z;
        int ans=ceil(n/(x+y));
        int ai=z;
        int lines=n-z*x;
        if(lines>0) ai+=ceil(lines/(x+10LL*y));
        ans=min(ans,ai);
        cout<<ans<<endl;
    }
}