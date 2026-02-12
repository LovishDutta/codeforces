#include<bits/stdc++.h>
using namespace std;
#define int long long
int dfs(int node,vector<vector<int>>& adj,int par,int& maxicnt,int cnt,int& maxi){
    if(cnt>maxicnt){
        maxicnt=cnt;
        maxi=node;
    }
    int ans=0;
    for(auto &it:adj[node]){
        if(it!=par) ans=max(1+dfs(it,adj,node,maxicnt,cnt+1,maxi),ans);
        
    }
    return ans;
}
void dfs2(int node,vector<vector<int>>& adj,int par,vector<int>& leafdist,int cnt){
    leafdist[node]=max(leafdist[node],cnt);
    for(auto &it:adj[node]){
        if(it!=par) dfs2(it,adj,node,leafdist,cnt+1); 
    }
}

signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,c,k,a,b;
        cin>>n>>k>>c;
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<int> zerodist(n,-1);
        while(!q.empty()){
            int node=q.front().first;
            int dist=q.front().second;
            zerodist[node]=dist;
            q.pop();
            for(auto &it:adj[node]){
                if(zerodist[it]==-1) q.push({it,dist+1});
            }
        }
        vector<int> leafdist(n,0);
        int maxicnt=0,maxi1=0,maxi2=0;
        dfs(0,adj,-1,maxicnt,0,maxi1);
        maxicnt=0;
        dfs(maxi1,adj,-1,maxicnt,0,maxi2);
        int ans=0;
        dfs2(maxi1,adj,-1,leafdist,0);
        dfs2(maxi2,adj,-1,leafdist,0);
        for(int i=0;i<n;i++){
            ans=max(ans,k*leafdist[i]-c*zerodist[i]);
        }
        cout<<ans<<endl;
    }
}