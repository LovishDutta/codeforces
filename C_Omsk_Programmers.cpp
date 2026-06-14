#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int a,b,x,cnt=0,ans=1e9;
        cin>>a>>b>>x;
        while(true){
            ans=min(ans,cnt+abs(a-b));
            if(a==b) break;
            if(x>a&&x>b){
                ans=min(ans,2LL+cnt);
                break;
            }
            if(a>b) a=a/x;
            else b=b/x;
            cnt++;
        }
        cout<<ans<<endl;
    }
}