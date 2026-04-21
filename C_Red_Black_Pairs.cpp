#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(int idx,string& up,string& down,vector<int>& dp){
    int n=up.size(),b=1e12;
    if(idx>=n) return 0;
    if(dp[idx]!=-1) return dp[idx];
    int a=(up[idx]!=down[idx])+recur(idx+1,up,down,dp);
    if(idx<n-1){
        b=(up[idx]!=up[idx+1])+(down[idx]!=down[idx+1])+recur(idx+2,up,down,dp);
    }
    return dp[idx]=min(a,b);
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        cin>>n;
        string up,down;
        cin>>up>>down;
        vector<int> dp(n+3,-1);
        cout<<recur(0,up,down,dp)<<endl;
    }
}