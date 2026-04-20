#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
void dfs(int node,vector<vector<int>>& adj,vector<int>& dist,int cnt,vector<vector<int>>& distcnt,int& maxi){
    dist[node]=cnt;
    distcnt[cnt].push_back(node);
    maxi=max(maxi,cnt);
    for(auto &it:adj[node]){
        if(dist[it]==0) dfs(it,adj,dist,cnt+1,distcnt,maxi);
    }
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,a,maxi=1,gain=0;
        cin>>n;
        vector<vector<int>> adj(n);
        vector<int> par(n);
        par[0]=-1;
        for(int i=1;i<n;i++){
            cin>>par[i];
            adj[i].push_back(par[i]-1);
            adj[par[i]-1].push_back(i);
            par[i]--;
        }
        vector<int> dist(n,0);
        vector<int> val(n,0);
        vector<int> tax(n,0);
        vector<vector<int>> distcnt(n+2);
        dfs(0,adj,dist,1,distcnt,maxi);
        for(int i=maxi;i>1;i--){
            for(auto &it:distcnt[i]){
                val[it]=(gain-tax[par[it]]+mod)%mod;
            }
            gain=0;
            for(auto &it:distcnt[i]){
                gain=(gain+(val[it]-tax[it])+1+mod)%mod;
                tax[par[it]]=(tax[par[it]]+(val[it]-tax[it])+1+mod)%mod;
            }

        }
        cout<<(gain+1)%mod<<endl;
    }
}