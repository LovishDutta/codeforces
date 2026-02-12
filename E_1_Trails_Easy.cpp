#include<bits/stdc++.h>
using namespace std;

#define int long long
int m,n;
long long mod=1e9+7;
long long recur(int shrt,int day,int cabin,vector<int>& s,vector<int>& l,vector<vector<vector<int>>>& dp){
    if(!day){
        return 1;
    }
    if(dp[shrt][day][cabin]!=-1) return dp[shrt][day][cabin];
    long long ans=0;
    if(cabin!=m){
        if(s[cabin]) ans=(ans+(s[cabin]*recur(1,day,m,s,l,dp)))%mod;
        if(l[cabin]) ans=(ans+l[cabin]*recur(0,day,m,s,l,dp))%mod;
    }
    else{
        for(int i=0;i<m;i++){
        if(shrt){
           if(s[i]) ans=(ans+s[i]*recur(1,day-1,i,s,l,dp))%mod;
           if(l[i]) ans=(ans+l[i]*recur(0,day-1,i,s,l,dp))%mod;
        }
        else if(s[i]) ans=(ans+s[i]*recur(1,day-1,i,s,l,dp))%mod;
    }
    }
    return dp[shrt][day][cabin]=(ans%mod);
}
signed main(){
    cin>>m>>n;
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(n+1, vector<int>(m+1, -1)));
        vector<int> s(m,0);
        vector<int> l(m,0);
        for(int i=0;i<m;i++) cin>>s[i];
        for(int i=0;i<m;i++) cin>>l[i];
        cout<<recur(0,n,0,s,l,dp)<<endl;
}