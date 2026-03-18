#include<bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,int& blue,int& red,int col,bool& flag){
    vis[node]=col;
    if(col==1) blue=blue+1;
    else red=red+1;
    bool ans=true;
    for(auto &it:adj[node]){
        if(vis[it]==0) dfs(it,adj,vis,blue,red,col==1?2:1,flag);
        else if(vis[it]==col) flag=false;
    }
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m,a,b;
        cin>>n>>m;
        vector<vector<int>> adj(n);
        for(int i=0;i<m;i++){
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        vector<int> vis(n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                int blue=0,red=0;
                bool flag=true;
                dfs(i,adj,vis,blue,red,1,flag);
                if(flag) ans+=max(blue,red);
            }
        }
        cout<<ans<<endl;
    }
}