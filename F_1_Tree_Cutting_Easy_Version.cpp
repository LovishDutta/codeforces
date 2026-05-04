#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& cnt,vector<int>& arr,int& ans){
    vis[node]=1;
    int a=(arr[node]==1),b=(arr[node]==2);
    for(auto &it:adj[node]){
        if(!vis[it]){
            auto col=dfs(it,adj,vis,cnt,arr,ans);
            if((col.first==0||col.second==0)&&(cnt[1]-col.first==0||cnt[2]-col.second==0)) ans++;
            a+=col.first;
            b+=col.second;
        }
    }
    return {a,b};
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   int n,a,b,ans=0;
   cin>>n;
   vector<int> arr(n),cnt(3,0),vis(n,0);
   for(int i=0;i<n;i++){
    cin>>arr[i];
    cnt[arr[i]]++;
   }
   vector<vector<int>> adj(n);
   for(int i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
   }
   dfs(0,adj,vis,cnt,arr,ans);
   cout<<ans<<endl;
}