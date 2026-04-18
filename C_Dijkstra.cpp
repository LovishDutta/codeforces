#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n,m,a,b,c;
        cin>>n>>m;
        vector<vector<int>> edges;
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<m;i++){
            cin>>a>>b>>c;
            edges.push_back({min(a,b),max(a,b),c});
        }
        sort(edges.begin(),edges.end());
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1],wt=edges[i][2],j=i;
            while(j<edges.size()-1&&edges[j+1][0]==u&&edges[j+1][1]==v){
                wt=min(wt,edges[j+1][2]);
                j++;
            }
            i=j;
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int> par(n+1,-1);
        vector<int> dist(n+1,1e12);
        dist[1]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,1});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(dis > dist[node]) continue;
            for(auto &it:adj[node]){
                if(dist[it.first]>dis+it.second){
                    dist[it.first]=dis+it.second;
                    pq.push({dist[it.first],it.first});
                    par[it.first]=node;
                }
            }
        }
        if(par[n]==-1){
            cout<<-1<<endl;
            return 0;
        }
        vector<int> ans;
        ans.push_back(n);
        int node=n;
        while(par[node]!=-1){
            ans.push_back(par[node]);
            node=par[node];
        }
        for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
        cout<<endl;
    }