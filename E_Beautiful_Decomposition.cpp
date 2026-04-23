#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(int idx,string& s,vector<int>& zeroone,int mode,vector<vector<int>>& dp){
    if(idx>=s.size()) return 0;
    if(dp[idx][mode]!=-1) return dp[idx][mode];
    if(mode==0){
        if(s[idx]=='1'){
            int single=1+recur(idx+1,s,zeroone,mode,dp);
            int use2=2+recur(zeroone[idx],s,zeroone,mode,dp);
            int super2=2+recur(idx+1,s,zeroone,1,dp);
            super2=min(super2,3+recur(idx+1,s,zeroone,2,dp));
            return dp[idx][mode]=min(single,min(use2,super2));
        }
        else return dp[idx][mode]=recur(idx+1,s,zeroone,mode,dp);
    }
    else if(mode==1){
        if(s[idx]=='0') return dp[idx][mode]=(idx==s.size()-1?0:1)+recur(idx+1,s,zeroone,mode,dp);
        else{
            int a=recur(idx+1,s,zeroone,mode,dp);
            int b=1+recur(idx+1,s,zeroone,2,dp);
            return dp[idx][mode]=min(a,b);
        }
    }
    else{
        if(s[idx]=='0'){
            int a=1e9;
            if(idx!=0) a=recur(idx+1,s,zeroone,mode,dp);
            int b=(idx==s.size()-1?-1:1)+recur(idx+1,s,zeroone,1,dp);
            return dp[idx][mode]=min(a,b);
        }
        else{
            if(idx==s.size()-1) return dp[idx][mode]=recur(idx+1,s,zeroone,2,dp);
            return dp[idx][mode]=1+recur(idx+1,s,zeroone,2,dp);
        }
    }
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        string s;
        cin>>s;
        int n=s.size(),val=n;
        vector<int> zeroone(n,n);
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        for(int i=n-1;i>=0;i--){
            zeroone[i]=val;
            if(i>0&&s[i]=='1'&&s[i-1]=='0') val=i;
        }
        cout<<recur(0,s,zeroone,0,dp);
}