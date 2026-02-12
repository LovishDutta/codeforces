#include<bits/stdc++.h>
using namespace std;
#define int long long
int mini(vector<int>& arr,int idx,int i){
    int ans=1e15;
    for(int k=idx;k<min(idx+i,(int)arr.size());k++) ans=min(ans,arr[k]);
    return ans;
}
// int recur(int idx,int k,vector<int>& arr,vector<vector<int>>& dp){
//     if(idx>=arr.size()) return 0;
//     if(dp[idx][k]!=-1) return dp[idx][k];
//     int ans=1e15;
//     for(int i=1;i<=min(k+1,(int)arr.size()-idx);i++){
//         ans=min(ans,mini(arr,idx,i)*i+recur(idx+i,k-i+1,arr,dp));
//     }
//     return dp[idx][k]=ans;
// }
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<vector<int>> dp(n+1,vector<int>(k+2,1e15));
        //cout<<recur(0,k,arr,dp)<<endl;
        for(int i=0;i<=k+1;i++) dp[n][i]=0;
        for(int idx=n-1;idx>=0;idx--){
            for(int j=0;j<=k;j++){
                 int ans = 1e15;
                for(int i=1;i<=min(j+1,n-idx);i++){
                    ans=min(ans,mini(arr,idx,i)*i+dp[idx+i][j-i+1]);
                }
                dp[idx][j]=ans;
            }
        }
        cout<<dp[0][k]<<endl;
    }
}