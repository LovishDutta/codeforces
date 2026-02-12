#include<bits/stdc++.h>
using namespace std;
int dfs(int node,int level,vector<vector<int>>& adj,vector<int>& vis,vector<int>& arr){
    vis[node]=level;
    arr[node]=level;
    for(auto& it:adj[node]){
        if(vis[it]==-1) arr[node]=max(arr[node],dfs(it,level+1,adj,vis,arr));
    }
    return arr[node];
}
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,a,b,ans=1e8;
        cin>>n;
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        vector<int> vis(n,-1);
        vector<int> arr(n,0);
        dfs(0,0,adj,vis,arr);
        sort(arr.begin(),arr.end());
        sort(vis.begin(),vis.end());
        for(int i=0;i<=vis[n-1];i++){
            ans=min(ans,(lower_bound(arr.begin(),arr.end(),i)-arr.begin())+n-(upper_bound(vis.begin(),vis.end(),i)-vis.begin()));
        }
        cout<<ans<<endl;
    }
}