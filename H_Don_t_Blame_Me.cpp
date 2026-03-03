#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
int recur(int idx,int an,vector<int>& arr,vector<vector<int>>& dp,int& k){
    if(idx==arr.size()) return (__builtin_popcount(an)==k?1:0);
    if(dp[idx][an]!=-1) return dp[idx][an];
    return dp[idx][an]=(recur(idx+1,an&arr[idx],arr,dp,k)%mod+recur(idx+1,an,arr,dp,k)%mod)%mod;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<vector<int>> dp(n,vector<int>(64,-1));
        cout<<recur(0,63,arr,dp,k)+(k==6?-1:0)<<endl;
    }
}