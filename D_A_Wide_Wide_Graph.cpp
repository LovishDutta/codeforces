#include<bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,int& far,int& maxi,int dist){
    vis[node]=1;
    if(dist>maxi){
        maxi=dist;
        far=node;
    }
    for(auto &it:adj[node]){
        if(!vis[it]) dfs(it,adj,vis,far,maxi,dist+1);
    }
}
void dfs2(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& dist,int dis){
    vis[node]=1;
    dist[node]=max(dist[node],dis);
    for(auto &it:adj[node]){
        if(!vis[it]) dfs2(it,adj,vis,dist,dis+1);
    }
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,a,b,far1=0,maxi1=0,j=0;
    cin>>n;
    vector<vector<int>> adj(n);
    vector<int> vis(n,0),dist(n,0),ans;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    dfs(0,adj,vis,far1,maxi1,0);
    int far2=far1,maxi2=0;
    for(int i=0;i<n;i++) vis[i]=0;
    dfs(far1,adj,vis,far2,maxi2,0);
    for(int i=0;i<n;i++) vis[i]=0;
    dfs2(far1,adj,vis,dist,0);
    for(int i=0;i<n;i++) vis[i]=0;
    dfs2(far2,adj,vis,dist,0);
    sort(dist.begin(),dist.end());
    for(int i=1;i<=n;i++){
        while(j<n&&dist[j]<i) j++;
        cout<<min((j+1),n)<<" ";
    }
}