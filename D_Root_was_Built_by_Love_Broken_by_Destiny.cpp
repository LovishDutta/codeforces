#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis,int par,vector<int>& arr){
    vis[node]=1;
    arr.push_back(node);
    bool ans=false;
    for(auto &it:adj[node]){
        if(!vis[it]) ans=ans|dfs(it,adj,vis,node,arr);
        else if(vis[it]&&it!=par) return true;
    }
    return ans;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    vector<int> fact(200005);
    fact[0]=1;
    for(int i=1;i<200005;i++){
        fact[i]=(i*fact[i-1])%mod;
    }
    while(tc--){
        int n,m,u,v,node=0,flag=0;
        cin>>n>>m;
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(int i=0;i<m;i++){
            cin>>u>>v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        for(int i=0;i<n;i++){
            if(adj[i].size()==1){
                node=i;
                break;
            }
        }
        vector<int> arr;
        if(dfs(node,adj,vis,-1,arr)){
            cout<<0<<endl;
            continue;
        }
        int ans=2;
        for(int j=0;j<arr.size();j++){
            int i=arr[j];
            if(adj[i].size()>1){
                int cnt=0;
                for(auto &it:adj[i]) if(adj[it].size()>1) cnt++;
                if(cnt==0){
                    ans=(ans*fact[adj[i].size()])%mod;
                }
                else if(cnt==1){
                    if(flag==0) ans=(ans*2)%mod;
                    ans=(ans*fact[adj[i].size()-1])%mod;
                }
                else if(cnt==2){
                    if(flag==0) ans=(ans*2)%mod;
                    ans=(ans*fact[adj[i].size()-2])%mod;
                }
                else{
                    ans=0;
                    break;
                }
                flag=1;
            }
        }
        cout<<ans<<endl;
    }
}