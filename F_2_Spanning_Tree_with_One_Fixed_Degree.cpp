#include<bits/stdc++.h>
using namespace std;
class Disjointset{
    vector<int> size,parent;
    public:
    Disjointset(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findUpar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionbysize(int u,int v){
        int a=findUpar(u);
        int b=findUpar(v);
        if(a==b) return;
        if(size[a]<size[b]){
            parent[a]=b;
            size[b]+=size[a];
        }
        else{
            parent[b]=a;
            size[a]+=size[b];
        }
    }
};
void dfs(int node,int& start,vector<vector<int>>& adj,vector<int>& vis,vector<int>& ans){
    vis[node]=1;
    for(auto &it: adj[node]){
        if(!vis[it]) dfs(it,start,adj,vis,ans);
        else if(it==0&&node!=start) ans.push_back(node);
    }
}
int main(){
    int n,m,d,a,b;
    cin>>n>>m>>d;
    vector<vector<int>> adj(n);
    vector<pair<int,int>> edges;
    vector<int> vis(n);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
        if(a!=1&&b!=1) edges.push_back({a-1,b-1});
    }
    vis[0]=1;
    vector<int> vec;
    vector<pair<int,int>> final;
    Disjointset ds(n);
    for(auto &it: adj[0]){
        if(!vis[it]){
            final.push_back({1,it+1});
            ds.unionbysize(0,it);
            dfs(it,it,adj,vis,vec);
        }
    }
    if(final.size()>d){
        cout<<"NO"<<endl;
        return 0;
    }
    int k=0;
    while(final.size()<d&&k<vec.size()){
        ds.unionbysize(0,vec[k]);
        final.push_back({1,vec[k]+1});
        k++;
    }
    if(final.size()<d){
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=0;i<edges.size();i++){
        if(ds.findUpar(edges[i].first)!=ds.findUpar(edges[i].second)){
            ds.unionbysize(edges[i].first,edges[i].second);
            final.push_back({edges[i].first+1,edges[i].second+1});
        }
        if(final.size()>=n){
        cout<<"NO"<<endl;
        return 0;
    }
    }
    if(final.size()==n-1){
        cout<<"YES"<<endl;
        for(int i=0;i<final.size();i++){
            cout<<final[i].first<<" "<<final[i].second<<endl;
        }
    }
    else{
        cout<<"NO"<<endl;
        return 0;
    }
}