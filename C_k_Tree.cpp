#include<bits/stdc++.h>
using namespace std;
int n,d,k;
int mod=1e9+7;
int dp[101][2];
int recur(int sum,int pick){
    if(sum==n){
        return pick;
    }
    if(dp[sum][pick]!=-1) return dp[sum][pick];
    int ans=0;
    for(int i=1;i<=k;i++){
    if(sum+i<=n) ans=(ans+recur(sum+i,pick|i>=d))%mod;
    else break;
    }
    return dp[sum][pick]=ans%mod;
}
int main(){
        cin>>n>>k>>d;
        memset(dp,-1,sizeof(dp));
        cout<<recur(0,0);
}