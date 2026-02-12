#include<bits/stdc++.h>
using namespace std;
int recur(int i,int j,int pc,bool prev,vector<vector<pair<int,int>>>& adj,vector<vector<vector<vector<long long>>>>& dp){
    if(dp[i][j][pc][prev]!=-1) return dp[i][j][pc][prev];
    if(prev){
        int ans=0;
        for(auto &it:adj[i]){
            if(pc==26||it.second>=pc) ans=max(ans,recur(it.first,j,it.second,false,adj,dp));
        }
        return dp[i][j][pc][prev]=ans;
    }
    else{
        int ans2=1;
        for(auto &it:adj[j]){
            if(it.second>=pc) ans2=min(ans2,recur(i,it.first,it.second,true,adj,dp));
        }
        return dp[i][j][pc][prev]=ans2;
    }
}
int main(){
    int n,m,a,b;
    char c;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        adj[a-1].push_back({b-1,c-'a'});
    }
vector<vector<vector<vector<long long>>>> dp(n,vector<vector<vector<long long>>>(n,vector<vector<long long>>(27,vector<long long>(2, -1))));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(recur(i,j,26,true,adj,dp)) cout<<'A';
            else cout<<'B';
        }
        cout<<endl;
    }
}