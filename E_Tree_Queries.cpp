#include<bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int node,vector<int>& vis,vector<vector<int>>& adj,int dpt,vector<int>& depth,vector<int>& par,int parent){
        vis[node]=1;
        depth[node]=dpt;
        par[node]=parent;
        for(auto &it:adj[node]){
            if(vis[it]) continue;
            dfs(it,vis,adj,dpt+1,depth,par,node);
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
    int n,m,a,b,k;
    cin>>n>>m;
    int c=log2(n);
    vector<vector<int>> adj(n),anc(n,vector<int>(c+1,-1));
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<int> vis(n),par(n),depth(n);
    dfs(0,vis,adj,0,depth,par,-1);
    for(int i=0;i<n;i++){
        anc[i][0]=par[i];
    }
    for(int i=1;i<=c;i++){
        for(int j=0;j<n;j++){
            if(anc[j][i-1]!=-1) anc[j][i]=anc[anc[j][i-1]][i-1];
        }
    }
    for(int i=0;i<m;i++){
        cin>>k;
        vector<int> temp(k);
        int maxi=0,md=0,flag=1;
        for(int j=0;j<k;j++){
            cin>>temp[j];
            if(temp[j]==1){
                temp[j]=0;
                continue;
            }
            temp[j]=par[temp[j]-1];
            if(depth[temp[j]]>maxi){
                maxi=depth[temp[j]];
                md=temp[j];
            }
        }
        for(int i=0;i<k;i++){
            if(lca(md,temp[i],anc,depth)!=temp[i]){
                flag=0;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}