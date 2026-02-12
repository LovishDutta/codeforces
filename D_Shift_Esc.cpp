#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
long long recur(int i,int j,int si,vector<vector<int>>& arr,vector<vector<vector<int>>>& dp){
    if(i==n-1&&j==m-1) return arr[i][(j+si)%m];
    if(dp[i][j][si]!=-1) return dp[i][j][si];
    int ans=LLONG_MAX;
    if(j<m-1||i==n-1) ans=min(ans,arr[i][(j+si)%m]+recur(i,j+1,si,arr,dp)); 
    if(i<n-1||j==m-1){
        // for(int z=0;z<m;z++){
        //     ans=min(ans,k*z+arr[i][(j+si)%m]+recur(i+1,j,z,arr,dp));
        // }
       
    }
    return dp[i][j][si]=ans;
}

signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
       
        cin>>n>>m>>k;
        vector<vector<int>> arr(n,vector<int>(m));
        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(m, vector<long long>(m, -1))
        );
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        long long ans=LLONG_MAX;
        for(int i=0;i<m;i++){
            ans=min(ans,k*i+recur(0,0,i,arr,dp));
        }
        cout<<ans<<endl;
    }
}