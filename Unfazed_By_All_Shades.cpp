#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
int modpow(int a,int b){
    if(a==0&&b==0) return 1;
    if(b==0) return 1;
    int mult=modpow(a,b/2)%mod;
    if(b%2) return (a*((mult*mult)%mod))%mod;
    else return (mult*mult)%mod;
}
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
void dfs2(int node,vector<vector<int>>& adj,vector<int>& vis,int& maxi,int dis,set<int>& st){
    vis[node]=1;
    if(dis==maxi){
        st.insert(node);
    }
    for(auto &it:adj[node]){
        if(!vis[it]) dfs2(it,adj,vis,maxi,dis+1,st);
    }
}
bool cd(int src, int target, int d, vector<vector<int>>& adj) {
    queue<pair<int,int>> q;
    int n = adj.size();

    vector<int> vis(n, 0);
    q.push({src, 0});
    vis[src] = 1;

    while (!q.empty()) {
        int node=q.front().first;
        int dist=q.front().second;
        q.pop();

        if (node == target) {
            return dist == d;
        }

        for (auto &it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push({it, dist + 1});
            }
        }
    }

    return false;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
    int n,a,b,far1=0,maxi1=0,j=0,x;
    cin>>n>>x;
    vector<vector<int>> adj(n);
    vector<int> vis(n,0);
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    dfs(0,adj,vis,far1,maxi1,0);
    int far2=far1,maxi2=0,cnt=0;
    for(int i=0;i<n;i++) vis[i]=0;
    dfs(far1,adj,vis,far2,maxi2,0);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(cd(i,j,maxi2,adj)) cnt++;
        }
    }
    int ans=x%mod;
    ans=(ans*modpow(x,n-2))%mod;
    ans=(ans*cnt)%mod;
    cout<<ans<<endl;
}
}