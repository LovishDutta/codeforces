#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,ans=-1e9;
        cin>>n;
        string s;
        cin>>s;
        vector<vector<int>> dp(n+1,vector<int>(n+2,-1e9));
        if(s[0]=='T') dp[0][0]=0;
        else if(s[0]=='F') dp[0][1]=1;
        else{
            dp[0][0]=0;
            dp[0][1]=1;
        }
        for(int i=1;i<n;i++){
            for(int tf=1;tf<=i+1;tf++){
                if(s[i]=='T'){
                    dp[i][0]=max(dp[i][0],0LL);
                    dp[i][tf]=max(dp[i][tf],dp[i-1][tf-1]-1);
                }
                else if(s[i]=='F'){
                    dp[i][1]=max(dp[i][1],1LL);
                    dp[i][tf]=max(dp[i][tf],dp[i-1][tf-1]+1);
                    
                }
                else{
                    
                }
            }
        }
        for(int i=0;i<=n;i++){
           // cout<<dp[n-1][i]<<endl;
            ans=max(ans,dp[n-1][i]-i);
        }
        cout<<ans<<endl;
    }
}