#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,x;

int recur(int idx,int startend,int cnt,vector<int>& arr,vector<vector<vector<int>>>& dp){
    if(idx==n) return cnt==0?0:-1e16;
    if(dp[idx][startend][cnt]!=-1) return dp[idx][startend][cnt]; 
    if(startend==0){
       int ns=recur(idx+1,0,cnt,arr,dp);
       if(cnt>0) ns=max(ns,recur(idx+1,0,cnt-1,arr,dp));
       int s= arr[idx]-x+recur(idx+1,1,cnt,arr,dp);
       if(cnt>0) s=max(s,arr[idx]+x+recur(idx+1,1,cnt-1,arr,dp));
       int se= arr[idx]-x+recur(idx+1,2,cnt,arr,dp);
       if(cnt>0) se=max(se,arr[idx]+x+recur(idx+1,2,cnt-1,arr,dp));
       return dp[idx][startend][cnt]=max(s,max(se,ns));
    }
    else{
        if(startend==2){
            return cnt<=n-idx?0:-1e16;
        }
        else{
            int sub=(arr[idx]-x)+max(recur(idx+1,1,cnt,arr,dp),recur(idx+1,2,cnt,arr,dp));
            int add=-1e16;
            if(cnt>0) add=arr[idx]+x+max(recur(idx+1,1,cnt-1,arr,dp),recur(idx+1,2,cnt-1,arr,dp));
            return dp[idx][startend][cnt]=max(add,sub);
        }
    }
}
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        cin>>n>>k>>x;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<vector<vector<int>>> dp(n+2,vector<vector<int>>(3,vector<int>(k+2,-1)));
        cout<<recur(0,0,k,arr,dp)<<endl;
    }
}