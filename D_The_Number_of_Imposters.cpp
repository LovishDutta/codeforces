#include<bits/stdc++.h>
using namespace std;
#define int long long
int dfs(int node,vector<vector<pair<int,int>>>& adj,vector<int>& vis,bool cur){
    if(cur) vis[node]=1;
    else vis[node]=2;
    int ans=cur;
    for(auto &it:adj[node]){
        if(vis[it.first]==0){
            if(cur){
                if(it.second==1) ans+=dfs(it.first,adj,vis,0);
                else ans+=dfs(it.first,adj,vis,1);
            }
            else{
                if(it.second==1) ans+=dfs(it.first,adj,vis,1);
                else ans+=dfs(it.first,adj,vis,0);
            }
        }
        else{
            if(cur){
                if((it.second==0&&vis[it.first]==2)||((it.second==1&&vis[it.first]==1))) return -1e9;
            }
            else if((it.second==0&&vis[it.first]==1)||((it.second==1&&vis[it.first]==2))) return -1e9;
        }
    }
    return ans;
}
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,m,a,b,c,ans=0;
        string s;
        cin>>n>>m;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<m;i++){
            cin>>a>>b>>s;
            if(s=="imposter") c=1;
            else c=0;
            adj[a-1].push_back({b-1,c});
            adj[b-1].push_back({a-1,c});
        }
        vector<int> vis1(n,0);
        vector<int> vis2(n,0);
        for(int i=0;i<n;i++){
            if(vis1[i]==0){
                ans+=max(dfs(i,adj,vis1,0),dfs(i,adj,vis2,1));
                if(ans<0) break;
            }
        }
        cout<<(ans<=0?-1:ans)<<endl;
    }
}