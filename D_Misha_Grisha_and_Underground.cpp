#include<bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int node,vector<int>& vis,vector<vector<int>>& adj,int dpt,vector<int>& depth){
        vis[node]=1;
        depth[node]=dpt;
        for(auto &it:adj[node]){
            if(vis[it]) continue;
            dfs(it,vis,adj,dpt+1,depth);
        }
    }
int lca(int a,int b,vector<vector<int>>& anc,vector<int>& depth){
    if(depth[a]<depth[b]) swap(a,b);
    if(depth[a]!=depth[b]){
        int diff=depth[a]-depth[b];
        for(int i=0;i<anc[0].size();i++){
            if((diff&(1<<i))>0){
                a=anc[a][i];
            }
        }
    }
    if(a==b) return a;
    for(int i=anc[0].size()-1;i>=0;i--){
        if(anc[a][i]!=anc[b][i]){
            a=anc[a][i];
            b=anc[b][i];
        }
    }
    return anc[a][0];
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q,a,b,c;
    cin>>n>>q;
    int cl=log2(n);
    vector<int> par(n,-1),vis(n),depth(n,0);
    vector<vector<int>> adj(n),anc(n,vector<int>(cl+1,-1));
    for(int i=1;i<n;i++){
        cin>>par[i];
        par[i]--;
        adj[par[i]].push_back(i);
        adj[i].push_back(par[i]);
    }
    dfs(0,vis,adj,1,depth);
    for(int i=0;i<n;i++){
        anc[i][0]=par[i];
    }
    for(int i=1;i<=cl;i++){
        for(int j=0;j<n;j++){
            if(anc[j][i-1]!=-1) anc[j][i]=anc[anc[j][i-1]][i-1];
        }
    }
    for(int i=0;i<q;i++){
        cin>>a>>b>>c;
        a--,b--,c--;
        int x=depth[a]+depth[b]-2*depth[lca(a,b,anc,depth)],y=depth[c]+depth[b]-2*depth[lca(c,b,anc,depth)],z=depth[c]+depth[a]-2*depth[lca(c,a,anc,depth)];
        cout<<max((x+y-z)/2+1,max((y+z-x)/2+1,(x+z-y)/2+1))<<endl;
    }
}