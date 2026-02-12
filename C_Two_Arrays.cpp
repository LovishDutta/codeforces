#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int dp[20][1001];
int recur(int idx,int pi,int& m,int& n){
    if(idx==2*m) return 1;
    if(dp[idx][pi]!=-1) return dp[idx][pi];
    int ans=0;
    for(int i=pi;i<=n;i++){
        ans=(ans+recur(idx+1,i,m,n))%mod;
    }
    return dp[idx][pi]=ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    cout<<recur(0,1,m,n);
}