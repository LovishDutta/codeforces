#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,h,l,r,ans=0;
    cin>>n>>h>>l>>r;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int dp[n+1][h+1];
    memset(dp,-1,sizeof(dp));
    dp[0][(a[0])%h]=((a[0]%h)>=l)&&((a[0]%h)<=r);
    dp[0][(a[0]-1)%h]=(((a[0]-1)%h)>=l)&&(((a[0]-1)%h)<=r);
    for(int i=1;i<n;i++){
        for(int j=0;j<=h;j++){
            int cnt=(j>=l&&j<=r);
            if(dp[i-1][(j-a[i]+h)%h]!=-1) dp[i][j]=max(dp[i][j],cnt+dp[i-1][(j-a[i]+h)%h]);
            if(dp[i-1][(j-a[i]+1+h)%h]!=-1) dp[i][j]=max(dp[i][j],cnt+dp[i-1][(j-a[i]+1+h)%h]);
        }
    }
    for(int j=0;j<=h;j++) ans=max(ans,dp[n-1][j]);
    cout<<ans;
}