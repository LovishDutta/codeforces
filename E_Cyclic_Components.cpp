#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,bool& flag,int parent){
    vis[node]=1;
    if(adj[node].size()!=2) flag=false;
    for(auto &it: adj[node]){
        if(!vis[it]) dfs(it,adj,vis,flag,node);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<int> vis(n,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            bool flag=true;
            dfs(i,adj,vis,flag,-1);
            cnt+=flag;
        }
    }
    cout<<cnt;
}