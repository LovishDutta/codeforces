#include<bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int node,string& vis,vector<vector<int>>& adj){
    vis[node]='1';
    for(auto &it:adj[node]){
        if(vis[it]=='0') dfs(it,vis,adj);
    }
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,z;
        cin>>n;
        vector<pair<int,int>> a,b;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            cin>>z;
            a.push_back({z,i});
        }
        for(int i=0;i<n;i++){
            cin>>z;
            b.push_back({z,i});
        }
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        for(int i=0;i<n-1;i++){
            adj[a[i+1].second].push_back(a[i].second);
            adj[b[i+1].second].push_back(b[i].second);
        }
        string vis(n,'0');
        dfs(a[0].second,vis,adj);
        dfs(b[0].second,vis,adj);
        cout<<vis<<endl;
    }
}