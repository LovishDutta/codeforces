#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(int idx,int mode,vector<int>& arr,vector<vector<int>>& dp){
    if(idx==arr.size()) return 0;
    if(dp[idx][mode]!=-1) return dp[idx][mode];
    int ans=arr.size();
    if(arr[idx]==0) ans=min(ans,recur(idx+1,0,arr,dp));
    else if(mode==0){
        ans=min(ans,recur(idx+1,0,arr,dp)+1);
        ans=min(ans,recur(idx+1,2,arr,dp)+2);
        ans=min(ans,recur(idx+1,3,arr,dp)+2);
        if(arr[idx]<=2) ans=min(ans,recur(idx+1,4,arr,dp)+1);
        if(arr[idx]<=4) ans=min(ans,recur(idx+1,1,arr,dp)+2);
    }
    else if(mode==1){
        if(arr[idx]<=4) ans=min(ans,recur(idx+1,0,arr,dp));
        else{
        ans=min(ans,recur(idx+1,0,arr,dp)+1);
        ans=min(ans,recur(idx+1,2,arr,dp)+2);
        ans=min(ans,recur(idx+1,3,arr,dp)+2);
        }
    }
    else if(mode==2){
        if(arr[idx]<=2) ans=min(ans,recur(idx+1,0,arr,dp));
        else{
        ans=min(ans,recur(idx+1,0,arr,dp)+1);
        ans=min(ans,recur(idx+1,2,arr,dp)+2);
        if(arr[idx]<=4){
            ans=min(ans,recur(idx+1,1,arr,dp)+2);
            ans=min(ans,recur(idx+1,3,arr,dp)+1);
        }
        else ans=min(ans,recur(idx+1,3,arr,dp)+2);
        }
    }
    else if(mode==3){
        if(arr[idx]<=4){
        ans=min(ans,recur(idx+1,4,arr,dp)+1);
        ans=min(ans,recur(idx+1,1,arr,dp)+2);
        }
        ans=min(ans,recur(idx+1,0,arr,dp)+1);
        ans=min(ans,recur(idx+1,2,arr,dp)+2);
        ans=min(ans,recur(idx+1,3,arr,dp)+2);
    }
    else if(mode==4){
        if(arr[idx]<=2) ans=min(ans,recur(idx+1,0,arr,dp));
        else{
        ans=min(ans,recur(idx+1,0,arr,dp)+1);
        ans=min(ans,recur(idx+1,2,arr,dp)+2);
        if(arr[idx]<=4){
            ans=min(ans,recur(idx+1,1,arr,dp)+2);
            ans=min(ans,recur(idx+1,3,arr,dp)+1);
        }
        else ans=min(ans,recur(idx+1,3,arr,dp)+2);
        }
    }
    return dp[idx][mode]=ans;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<vector<int>> dp(n+1,vector<int>(5,-1));
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<recur(0,0,arr,dp)<<endl;
    }
}