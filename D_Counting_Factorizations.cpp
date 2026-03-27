#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
int dp[4050][2024];
int inv(int ele,int pow){
    if(pow==0) return 1;
    int ans=(inv(ele,pow/2))%mod;
    if(pow%2) return (ele*((ans*ans)%mod))%mod;
    return (ans*ans)%mod;
}
bool isprime(int ele){
    for(int i=2;i*i<=ele;i++) if(ele%i==0) return false;
    return (ele!=1);
}
int recur(int idx,int cnt,vector<pair<int,int>>& arr,int& n,vector<int>& fact,vector<int>& prim,vector<int>& invfact){
    if(cnt>n) return 0;
    if(idx==arr.size()) return cnt==n?fact[n]:0;
    if(dp[idx][cnt]!=-1) return dp[idx][cnt];
    int base=0,pow=0;
    if(prim[idx]) base=(recur(idx+1,cnt+arr[idx].second-1,arr,n,fact,prim,invfact)*invfact[arr[idx].second-1])%mod;
    pow=(recur(idx+1,cnt+arr[idx].second,arr,n,fact,prim,invfact)*invfact[arr[idx].second])%mod;
    return dp[idx][cnt]=(base+pow)%mod;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,a,pr=1;
    cin>>n;
    map<int,int> mpp;
    vector<int> fact(2*n+5);
    fact[0]=1;
    for(int i=0;i<2*n+5;i++){
       if(i<2*n){
        cin>>a;
        mpp[a]++;
       }
       if(i>0) fact[i]=(i*fact[i-1])%mod;
    }
    vector<int> invfact(2*n+5);
    for(int i=0;i<2*n+5;i++){
        invfact[i]=inv(fact[i],mod-2);
    }
    vector<pair<int,int>> arr;
    for(auto &it:mpp){
        arr.push_back({it.first,it.second});
    }
    vector<int> prim(arr.size());
for(int i=0;i<arr.size();i++){
    prim[i] = isprime(arr[i].first);
}
    memset(dp,-1,sizeof(dp));
    cout<<recur(0,0,arr,n,fact,prim,invfact);
}