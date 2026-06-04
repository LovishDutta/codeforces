#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x,s;
int dp[3001][3001];
int recur(int idx,int empty,int seated,string& s1){
    int tot=idx+1,ans=1e12,nempty=x-empty;
    if(idx==s1.size()) return 0;
    if(dp[idx][empty]!=-1) return dp[idx][empty];
    ans = 1 + recur(idx + 1, empty, seated, s1);
    if(s1[idx]=='I'){
        if(empty>0) ans=min(ans,recur(idx+1,empty-1,seated+1,s1));
    }
    else if(s1[idx]=='E'){
        if(nempty>0&&seated<nempty*s) ans=min(ans,recur(idx+1,empty,seated+1,s1));
    }
    else{
        if(empty>0) ans=min(ans,recur(idx+1,empty-1,seated+1,s1));
        if(nempty>0&&seated<nempty*s) ans=min(ans,recur(idx+1,empty,seated+1,s1));
    }
    return dp[idx][empty]=ans;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        string s1;
        cin>>n>>x>>s>>s1;
        for(int i=0;i<n;i++){
            for(int j=0;j<=x;j++){
                dp[i][j]=-1;
            }
        }
        cout<<n-recur(0,x,0,s1)<<endl;

    }
}