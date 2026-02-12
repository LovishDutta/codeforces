#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
#define int long long
signed main(){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=0;i<=k;i++) dp[0][i]=0;
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            vector<int> pref(k+1,dp[i-1][0]);
            for(int z=1;z<=k;z++){
                 pref[z]=(pref[z-1]+dp[i-1][z])%mod;
            }
            for(int j=0;j<=k;j++){
                int left=(j-min(j,arr[i-1])==0?0:pref[j-min(j,arr[i-1])-1]);
                dp[i][j]=(pref[j]-left+mod)%mod;
            }
        }
        cout<<dp[n][k]<<endl;
}