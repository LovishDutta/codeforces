#include<bits/stdc++.h>
using namespace std;
#define int long long 
int dp[100001][32][2][3];
int recur(int idx,int maxi,int sign,int start,vector<int>& arr){
    if(idx==arr.size()||start==2) return -1*maxi;
    if(dp[idx][maxi][sign][start]!=-1) return dp[idx][maxi][sign][start];
    if(start==0){
        int ns=recur(idx+1,maxi,sign,0,arr);
        int s=max(0LL,arr[idx]+recur(idx+1,abs(arr[idx]),arr[idx]>0,1,arr));
        return dp[idx][maxi][sign][start]=max(ns,s);
    }
    else if(start==1){
        int m=maxi;
        if(!sign) m*=-1;
        m=max(m,arr[idx]);
        int ne=arr[idx]+recur(idx+1,abs(m),m>0,1,arr);
        int e=arr[idx]+recur(idx+1,abs(m),m>0,2,arr);
        return dp[idx][maxi][sign][start]=max(ne,e);
    }
}
signed main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    memset(dp,-1LL,sizeof(dp));
    cout<<recur(0,31,0,0,arr);
}