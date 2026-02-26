#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,x,y,cnt1=0,cnt2=0;
        cin>>n>>x>>y;
        vector<int> ans(n+1,-1);
        for(int i=y;i<=x;i++)  ans[i]=1;
        if((y-1)%2){
            for(int i=1;i<y;i++)  ans[i]=(i%2)?-1:1;
        }
        else{
            for(int i=1;i<y;i++)  ans[i]=(i%2)?1:-1;
        }
        for(int i=x+1;i<=n;i++) ans[i]=((i-x)%2)?-1:1;
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;  
    }
}