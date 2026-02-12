#include<bits/stdc++.h>
using namespace std;
int recur(string& x,string& y,int i,int mod,vector<vector<int>>& dp){
    if(i==x.size()) return 0;
    if(dp[i][mod]!=-1) return dp[i][mod];
    if((x[i]=='0'&&y[i]=='0')){
        if(mod) return dp[i][mod]=1+min(recur(x,y,i+1,(mod+1)%2,dp),recur(x,y,i+1,(mod)%2,dp));
        else return dp[i][mod]=min(2+recur(x,y,i+1,(mod+1)%2,dp),recur(x,y,i+1,(mod)%2,dp));
    }
    else if(x[i]=='0'&&y[i]=='1'){
        if(mod) return dp[i][mod]=min(2+recur(x,y,i+1,(mod+1)%2,dp),recur(x,y,i+1,(mod)%2,dp));
        else return dp[i][mod]=1+min(recur(x,y,i+1,(mod+1)%2,dp),recur(x,y,i+1,(mod)%2,dp));
    }
    else if(x[i]=='1'&&y[i]=='0'){
        if(mod) return dp[i][mod]=min(2+recur(x,y,i+1,(mod)%2,dp),recur(x,y,i+1,(mod+1)%2,dp));
        else return dp[i][mod]=1+min(recur(x,y,i+1,(mod+1)%2,dp),recur(x,y,i+1,(mod)%2,dp));
    }
    else{
        if(mod) return dp[i][mod]=1+min(recur(x,y,i+1,(mod+1)%2,dp),recur(x,y,i+1,(mod)%2,dp));
        else return dp[i][mod]=min(2+recur(x,y,i+1,(mod)%2,dp),recur(x,y,i+1,(mod+1)%2,dp));
    }
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        string x,y;
        cin>>x>>y;
        vector<vector<int>> dp(x.size()+1,vector<int>(2,-1));
        cout<<recur(x,y,0,0,dp)<<endl;
    }
}