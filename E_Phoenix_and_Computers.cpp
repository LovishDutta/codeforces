#include<bits/stdc++.h>
using namespace std;
#define int long long
int modpow(int a,int b,int mod){
    if(b==0) return 1;
    int ans=modpow(a,b/2,mod)%mod;
    ans=(ans*ans)%mod;
    if(b%2) return (ans*a)%mod;
    return ans;
}
int dp[401][401];
int recur(int idx,int cnt,vector<int>& fact,vector<int>& invfact,vector<int>& power,int mod){
    int n=fact.size()-1,ans=0;
    if(idx>=n) return fact[cnt];
    if(dp[idx][cnt]!=-1) return dp[idx][cnt];
    for(int i=idx;i<=n-1;i++){
        if(i==n-2) continue;
        int a=recur(i+2,cnt+(i-idx+1),fact,invfact,power,mod)%mod;
        a=(a*power[(i-idx)])%mod;
        a=(a*invfact[i-idx+1])%mod;
        ans=(ans+a)%mod;
    }
    return dp[idx][cnt]=ans;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,mod,mult=1,pwr=2;
    cin>>n>>mod;
    vector<int> fact(n+1,1),invfact(n+1),power(n+1,1);
    for(int i=1;i<=n;i++){
        mult=(mult*i)%mod;
        fact[i]=mult;
        invfact[i]=modpow(fact[i],mod-2,mod)%mod;
        power[i]=pwr;
        pwr=(pwr*2)%mod;
    }
    memset(dp,-1,sizeof(dp));
    cout<<recur(0,0,fact,invfact,power,mod)<<endl;
}