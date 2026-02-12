#include<bits/stdc++.h>
using namespace std;
int dfs(int node,vector<int>& vis,vector<vector<int>>& adj,int& b){
    if(node==b) return -1e8;
    vis[node]=1;
    int ans=1;
    for(auto &it:adj[node]){
        if(!vis[it]) ans+=dfs(it,vis,adj,b);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,m,a,b,c,d;
        long long l=0,r=0,k=0;
        cin>>n>>m>>a>>b;
        a--;b--;
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(int i=0;i<m;i++){
            cin>>c>>d;
            adj[c-1].push_back(d-1);
            adj[d-1].push_back(c-1);
        }
        vis[a]=1;
        for(auto& it:adj[a]){
            if(!vis[it]){
            k=dfs(it,vis,adj,b);
            if(k>=0) l+=k;
            }
        }
        vis[b]=1;vis[a]=0;
        for(auto& it:adj[b]){
            if(!vis[it]){
            k=dfs(it,vis,adj,a);
            if(k>=0) r+=k;
            }
        }         
        cout<<r*l<<endl;
    }
}