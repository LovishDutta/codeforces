#include<bits/stdc++.h>
using namespace std;
int dfs(int node,vector<vector<int>>& adj,vector<int>& vis,int& cut){
    int ans=1;
    vis[node]=1;
    for(auto& it: adj[node]){
        if(!vis[it]){
            ans+=dfs(it,adj,vis,cut);
        }
    }
    if(ans%2==0){
        cut++;
        return 0;
    }
    return ans;
}
int main(){
        int n;
        cin>>n;
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        vector<int> vis(n,0);
        int cut=0;
        dfs(0,adj,vis,cut);
        if(n%2) cout<<-1<<endl;
        else cout<<cut-1<<endl;
}