#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(int prev,int picked,vector<int>& arr,int& m,vector<vector<int>>& mpp,vector<vector<int>>& dp){
    if(__builtin_popcount(picked)==m) return 0;
    if(dp[picked][prev]!=-1) return dp[picked][prev];
    int ans=-1e15;
    for(int i=0;i<arr.size();i++){
        if((picked&(1<<i))>0) continue;
        int rec=arr[i]+mpp[prev][i];
        ans=max(ans,rec+recur(i,picked|(1<<i),arr,m,mpp,dp));
    }
    return dp[picked][prev]=ans;
}
signed main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
   vector<vector<int>> mpp(n+1, vector<int>(n+1, 0));
    for(int i=0;i<k;i++){
        int a,b,c;
        cin>>a>>b>>c;
        mpp[a-1][b-1]=c;
    } 
    vector<vector<int>> dp(1<<(n),vector<int>(n+1,-1));
    cout<<recur(n,0,arr,m,mpp,dp);
}