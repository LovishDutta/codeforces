#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    //cin>>tc;    
    while(tc--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> arr(n);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<vector<int>> adj(n);
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        vector<int> ans(k+1,0);
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int cnt=it.second;
            int node=it.first;
            if(!vis[node]) ans[arr[node]]=cnt;
            vis[node]=1;
            for(auto &it:adj[node]){
              if(!vis[it]) q.push({it,cnt+1});
            }
        }
        for(int i=1;i<=k;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}