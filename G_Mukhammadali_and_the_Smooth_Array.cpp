#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define int long long
int recur(int i,vector<int>& a,vector<int>& b,vector<int>&dp){
    if(i>a.size()) return 0;
    
    if(dp[i]!=-1) return dp[i];
    
    int mini;
    
    for(int j=0;j<i;j++){
        int prev=a[j];
        if(a[i]==prev){
            mini=recur(i+1,a,b,dp);
        }
        else if(a[i]>prev){
            mini=min(recur(i+1,a,b,dp),(b[i]+recur(i+1,a,b,dp)));
        }
        else{
            mini=(b[i]+recur(i+1,a,b,dp));
        }
    }

    return dp[i]=mini;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> c(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    a[0]=INT_MIN;
    vector<int>dp(n+1,-1);
    cout<<recur(1,a,c,dp)<<endl;
}

int32_t main() {
    fastio;
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}
