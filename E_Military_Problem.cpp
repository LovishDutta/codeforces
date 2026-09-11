#include<bits/stdc++.h>
using namespace std;
#define int long long
int dfs(int node,vector<int>& vis,vector<vector<int>>& adj,vector<int>& tr,vector<int>& ct){
    vis[node]=1;
    tr.push_back(node);
    int cnt=1;
    for(auto &it:adj[node]){
        if(!vis[it]) cnt+=dfs(it,vis,adj,tr,ct);
    }
    ct[node]=cnt;
    return cnt;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n,q,a,b;
        cin>>n>>q;
        vector<vector<int>> adj(n);
        vector<int> vis(n),tr,idx(n),ct(n);
        for(int i=1;i<n;i++){
            cin>>a;
            adj[i].push_back(a-1);
            adj[a-1].push_back(i);
        }
        for(int i=0;i<n;i++) sort(adj[i].begin(),adj[i].end());
        dfs(0,vis,adj,tr,ct);
        for(int i=0;i<n;i++) idx[tr[i]]=i;
        for(int i=0;i<q;i++){
            cin>>a>>b;
            if(ct[a-1]<b) cout<<-1<<endl;
            else cout<<tr[idx[a-1]+b-1]+1<<endl;
        }
}