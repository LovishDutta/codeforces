#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,ans=0;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        // vector<vector<int>> dp(n,vector<int>(n+1,0));
        // for(int i=0;i<n;i++){
        //     if(a[i]==1&&b[i]==1) dp[i][1]=1;
        //     else if(a[i]!=1&&b[i]!=1) dp[i][0]=1;
        //     if(i>0){
        //         for(int prev=0;prev<=n;prev++){
        //         if(a[i]==prev&&b[i]==prev&&prev>0){
        //             dp[i][prev]+=dp[i-1][prev]+dp[i-1][prev-1];
        //         }
        //         else if(a[i]!=prev+1&&b[i]!=prev+1) dp[i][prev]+=dp[i-1][prev];
        //     }
        //     }    
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=n;j++){
        //         ans+=dp[i][j];
        //     }
        // }
        // vector<int> curdp(n+1,0),prevdp(n+1,0);
        // for(int i=0;i<n;i++){
        //     if(a[i]==1&&b[i]==1) curdp[1]=1;
        //     else if(a[i]!=1&&b[i]!=1) curdp[0]=1;
        //     if(i>0){
        //         for(int prev=0;prev<=n;prev++){
        //         if(a[i]==prev&&b[i]==prev&&prev>0){
        //             curdp[prev]+=prevdp[prev]+prevdp[prev-1];
        //         }
        //         else if(a[i]!=prev+1&&b[i]!=prev+1) curdp[prev]+=prevdp[prev];
        //     }
        //     } 
        //     for(int j=0;j<=n;j++){
        //         ans+=curdp[j]; 
        //         prevdp[j]=curdp[j];
        //         curdp[j]=0;
        //     } 
        // }
        //for(int i=0;i<=n;i++) ans+=dp[i];
        vector<int> dp(n+1,0);
        int cur=0;
        for(int i=0;i<n;i++){
            if(a[i]==1&&b[i]==1){
                dp[1]++;
                dp[1]+=dp[0];
                cur++;
                dp[0]=0;
            }
            else if(a[i]==b[i]){
                cur++;
                dp[a[i]]=dp[a[i]]+dp[a[i]-1];
                dp[a[i]-1]=0;
                dp[0]++;
            }
            else if(a[i]!=1&&b[i]!=1){
                cur-=dp[a[i]-1];
                cur-=dp[b[i]-1];
                dp[a[i]-1]=0;
                dp[b[i]-1]=0;
                dp[0]++;
                cur++;
            }
            else{
                cur-=dp[0];
                dp[0]=0;
               if(a[i]!=1){
                cur-=dp[a[i]-1];
                dp[a[i]-1]=0;
               }
               else{
                cur-=dp[b[i]-1];
                dp[b[i]-1]=0;
               }
            }
            ans+=cur;
        }
        cout<<ans<<endl;
    }
}