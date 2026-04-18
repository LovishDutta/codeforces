#include<bits/stdc++.h>
using namespace std;
#define int long long
int dfs(int node,vector<vector<int>>& adj,vector<int>& vis,int& ans,int& k){
    vis[node]=1;
    int n=adj.size();
    int tot=1;
    for(auto &it:adj[node]){
        if(!vis[it]){
            int cnt=dfs(it,adj,vis,ans,k);
            tot+=cnt;
            if(n-cnt>=k) ans+=cnt;
        }
    }
    if(tot>=k) ans+=(n-tot);
    return tot;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k,a,b,ans=0;
        cin>>n>>k;
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        if(n>=k) ans+=n;
        dfs(1,adj,vis,ans,k);
        cout<<ans<<endl;
    }
}