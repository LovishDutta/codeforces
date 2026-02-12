#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(int idx,bool flip,vector<int>& arr,vector<vector<int>>& dp){
    if(idx==arr.size()) return 0;
    if(dp[idx][flip]!=-1e15) return dp[idx][flip]; 
    int ele=arr[idx];
    if(flip) ele*=-1;
    int flp=-1e15;
    if(idx<arr.size()-1) flp=ele*(-1)+recur(idx+1,true,arr,dp);
    int nflp=ele+recur(idx+1,false,arr,dp);
    return dp[idx][flip]=max(flp,nflp);
}
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<vector<int>> dp(n+1,vector<int>(2,-1e15));
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<recur(0,false,arr,dp)<<endl;
    }
}