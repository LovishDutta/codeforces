#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
int recur(int idx,int prev1,int prev2,vector<int>& arr,vector<vector<vector<int>>>& dp){
    if(idx==arr.size()) return 1;
    if(dp[idx][prev1][prev2]!=-1) return dp[idx][prev1][prev2];
    int cnt=0;
    if(prev1==1){
        if(arr[idx]==arr[idx-1]) cnt=(cnt+recur(idx+1,1,prev1,arr,dp))%mod;
        cnt=(cnt+recur(idx+1,0,prev1,arr,dp))%mod;
    }
    else{
        if(prev2==2){
            if(arr[idx]==1) cnt=(cnt+recur(idx+1,1,prev1,arr,dp))%mod;
        }
        else{
            if(arr[idx]==arr[idx-2]+1) cnt=(cnt+recur(idx+1,1,prev1,arr,dp))%mod;
        }
    }
    return dp[idx][prev1][prev2]=cnt;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,cnt=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        if(arr[0]==0) cnt=recur(1,1,2,arr,dp);
        cnt=(cnt+recur(1,0,2,arr,dp))%mod;
        cout<<cnt<<endl;
    }
}