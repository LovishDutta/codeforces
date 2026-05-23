#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
vector<int> fact(101),invfact(101);
int modpow(int a,int b){
    if(b==0) return 1;
    int mult=modpow(a,b/2)%mod;
    if(b%2) return (a*((mult*mult)%mod))%mod;
    else return (mult*mult)%mod;
}
void precompute(){
    fact[0]=1;
    for(int i=1;i<=100;i++)
        fact[i]=(fact[i-1]*i)%mod;
    invfact[100]=modpow(fact[100],mod-2);
    for(int i=99;i>=0;i--)
        invfact[i]=(invfact[i+1]*(i+1))%mod;
}

int ncr(int n,int r){
    if(r<0 || r>n) return 0;
    return (((fact[n]*invfact[r])%mod)*invfact[n-r])%mod;
}
int dp[10][101];
int recur(int idx,int rem,vector<int>& arr){
    if(idx==arr.size()) return rem==0;
    if(dp[idx][rem]!=-1) return dp[idx][rem];
    int ans=0;
    if(idx==0){
        for(int i=arr[idx];i<=rem-1;i++){
            ans=(ans+(ncr(rem-1,i)*recur(idx+1,rem-i,arr))%mod)%mod;
        }
    }
    else{
        for(int i=arr[idx];i<=rem;i++){
            ans=(ans+(ncr(rem,i)*recur(idx+1,rem-i,arr))%mod)%mod;
        }
    }
    return dp[idx][rem]=ans;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,sum=0,ans=0;
    cin>>n;
    precompute();
    vector<int> arr(10);
    for(int i=0;i<=9;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    memset(dp,-1,sizeof(dp));
    for(int i=sum;i<=n;i++){
        ans=(ans+recur(0,i,arr))%mod;
    }
    cout<<ans<<endl;
}