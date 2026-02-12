#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[201][201][202];
int recur(int i,vector<int>& arr,int& k,int x,int prev){
if(i==arr.size()) return (x==0)?0:-1e15;
if(x==0) return (arr.size()-prev<=k)?0:-1e15;
if(dp[i][x][prev]!=-1) return dp[i][x][prev];
int pick=-1e15,notpick=-1e15,p=(prev==arr.size())?-1:prev;
if(x>0) pick=arr[i]+recur(i+1,arr,k,x-1,i);
if(i-p+1<=k) notpick=recur(i+1,arr,k,x,prev);
return dp[i][x][prev]=max(pick,notpick);
}
signed main(){
        int n,k,x;
        cin>>n>>k>>x;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        memset(dp,-1,sizeof(dp));
        int ans=recur(0,arr,k,x,arr.size());
        cout<<(ans<0?-1:ans);
}