#include<bits/stdc++.h>
using namespace std;
//#define int long long
int dp[101][200001];
int recur(int idx,int sum,vector<int>& a,vector<int>& b,int k){
    if(idx==a.size()) return sum==0?0:-1e12;
    if(dp[idx][sum+100000]!=-1) return dp[idx][sum+100000];
    int pi=a[idx]+recur(idx+1,sum+(a[idx]-k*b[idx]),a,b,k);
    int npi=recur(idx+1,sum,a,b,k);
    return dp[idx][sum+100000]=max(pi,npi);
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    memset(dp,-1,sizeof(dp));
    int ans=recur(0,0,a,b,k);
    if(ans==0) cout<<-1<<endl;
    else cout<<ans<<endl;
}