#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a,b,c,d,mod=1e8;
    cin>>a>>b>>c>>d;
    int dp[a+1][b+1][c+1][d+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=min(b,d);i++) dp[0][i][0][i]=1;
    for(int i=1;i<=min(a,c);i++) dp[i][0][i][0]=1;
    for(int n1=1;n1<=a;n1++){
        for(int n2=1;n2<=b;n2++){
            for(int k1=2;k1<=min(n1,c);k1++){
                dp[n1][n2][k1][0]=(dp[n1][n2][k1][0]+dp[n1-1][n2][k1-1][0])%mod;
            }
            for(int k2=2;k2<=min(n2,d);k2++){
                dp[n1][n2][0][k2]=(dp[n1][n2][0][k2]+dp[n1][n2-1][0][k2-1])%mod;
            }
            for(int k1=1;k1<=min(n1,c);k1++){
                dp[n1][n2][0][1]=(dp[n1][n2][0][1]+dp[n1][n2-1][k1][0])%mod;
            }
            for(int k2=1;k2<=min(n2,d);k2++){
                dp[n1][n2][1][0]=(dp[n1][n2][1][0]+dp[n1-1][n2][0][k2])%mod;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=min(a,c);i++) ans=(ans+dp[a][b][i][0])%mod;
    for(int i=1;i<=min(b,d);i++) ans=(ans+dp[a][b][0][i])%mod;
    cout<<ans;
}