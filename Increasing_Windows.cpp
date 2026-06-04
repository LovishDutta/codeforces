#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
int pwr(int a,int b){
    if(b==0) return 1;
    int p=pwr(a,b/2)%mod;
    if(b%2) return (((p*p)%mod)*a)%mod;
    return (p*p)%mod;
}
vector<int> fact,invfact;
int ncr(int n,int r){
    return (((fact[n]*invfact[n-r])%mod)*invfact[r])%mod;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc; 
    fact.resize(200002);   
    invfact.resize(200002); 
    fact[0]=1;
    for(int i=1;i<200002;i++) fact[i]=(fact[i-1]*i)%mod; 
    invfact[200001]=pwr(fact[200001],mod-2); 
    for(int i=200000;i>=0;i--){
        invfact[i]=(invfact[i+1]*(i+1))%mod;
    }
    while(tc--){
        int n,k,ans=0;
        cin>>n>>k;
        ans=ncr(n-1,n-k);
        for(int i=2;i<=k;i++){
            int val=(pwr(i,k)%mod-pwr(i-1,k)%mod+mod)%mod;
            val=(val*ncr(n-i,n-k))%mod;
            ans=(ans+val)%mod;
        }
        cout<<ans<<endl;
    }
}