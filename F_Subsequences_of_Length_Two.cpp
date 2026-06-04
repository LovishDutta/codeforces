#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[202][202][202];
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,K,ans=0;
    cin>>n>>K;
    string s,t;
    cin>>s>>t;
    if(t[0]==t[1]){
        for(int i=0;i<n;i++){
            if(s[i]==t[0]) ans++;
            else if(K>0){
                ans++; 
                K--;
            }
        }
        cout<<(ans*(ans-1))/2;
        return 0;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=K;k++){
                dp[i][j][k]=-1e17;
            }
        }
    }
    dp[0][0][0]=0;
    for(int idx=1;idx<=n;idx++){
        for(int c1=0;c1<=idx;c1++){
            for(int k=0;k<=min(K,idx);k++){
                int val=dp[idx][c1][k];
                if(s[idx-1]==t[0]){
                    if(c1>0) val=max(val,dp[idx-1][c1-1][k]);
                    if(k>0) val=max(val,dp[idx-1][c1][k-1]+c1);
                }
                else if(s[idx-1]==t[1]){
                   if(k>0&&c1>0) val=max(val,dp[idx-1][c1-1][k-1]);
                    val=max(val,dp[idx-1][c1][k]+c1);
                }
                else{
                    val=max(val,dp[idx-1][c1][k]);
                    if(k>0) val=max(val,dp[idx-1][c1][k-1]+c1);
                    if(k>0&&c1>0) val=max(val,dp[idx-1][c1-1][k-1]);
                }
                dp[idx][c1][k]=val;
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int k=0;k<=K;k++){
            ans=max(ans,dp[n][i][k]);
        }
    }
    cout<<ans;
}