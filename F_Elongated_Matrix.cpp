#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int dp[(1LL<<16)+1][17][17];
int recur(int mask,int prev,int start,vector<vector<int>>& arr,vector<vector<int>>& adjcost,vector<vector<int>>& wrapcost){
    int cnt=__builtin_popcount(mask),ans=0,k=1e12;
    if(cnt==n) return wrapcost[prev][start];
    if(dp[mask][prev][start]!=-1) return dp[mask][prev][start];
    for(int i=0;i<n;i++){
        int k2=1e12;
        if((mask&(1LL<<i))==0){
            if(cnt>0) k2=adjcost[i][prev];
            k2=min(k2,recur(mask|(1LL<<i),i,cnt==0?i:start,arr,adjcost,wrapcost));
            ans=max(ans,k2);
        }
    }
    return dp[mask][prev][start]=ans;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    vector<vector<int>> adjcost(n,vector<int>(n,1e12));
    vector<vector<int>> wrapcost(n,vector<int>(n,1e12));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                adjcost[i][j]=min(adjcost[i][j],abs(arr[i][k]-arr[j][k]));
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m-1;k++){
                wrapcost[i][j]=min(wrapcost[i][j],abs(arr[i][k]-arr[j][k+1]));
            }
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<recur(0,0,0,arr,adjcost,wrapcost);
}