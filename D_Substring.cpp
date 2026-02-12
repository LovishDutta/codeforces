#include<bits/stdc++.h>
using namespace std;

int dfs(int node,char ch,vector<vector<int>>& adj,vector<vector<int>>& dp,string& s){
    if(dp[node][ch-'a']!=-1) return dp[node][ch-'a'];
    int ans=0;
    for(auto& it:adj[node]){
        ans=max(ans,(s[it]==ch)+dfs(it,ch,adj,dp,s));
    }
    return dp[node][ch-'a']=ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(int v : adj[u]){
            indeg[v]--;
            if(indeg[v] == 0)
                q.push(v);
        }
    }
    if(topo.size() != n){
        cout<<-1<<endl;
        return 0;
    }
    int ans=0;
    vector<vector<int>> dp(n,vector<int>(26,-1));
    for(char ch='a';ch<='z';ch++){
        for(int i=0;i<topo.size();i++){
            if(dp[topo[i]][ch-'a']==-1){
                ans=max(ans,(s[topo[i]]==ch)+dfs(topo[i],ch,adj,dp,s));
            }
        }
    }
    cout<<ans<<endl;
}