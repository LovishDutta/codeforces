#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n,m,k,a,b,c;
        cin>>n>>m>>k;
        vector<int> special(k);
        vector<vector<int>> edges;
        vector<vector<pair<int,int>>> adj(n+1);
       vector<int> self(n+1,0);
        for(int i=0;i<k;i++){
             cin>>special[i];
        }
        for(int i=0;i<m;i++){
            cin>>a>>b>>c;
            if(a==b){
                self[a]=min(self[a],c);
            }
            else edges.push_back({a,b,c});
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
        vector<int> dist(n+1,1e15);
        dist[special[0]]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,special[0]});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(dis > dist[node]) continue;
            for(auto &it:adj[node]){
                if(dist[it.first]>max(dis,it.second)){
                    dist[it.first]=max(dis,it.second);
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<k;i++) maxi=max(maxi,dist[special[i]]);
        for(int i=0;i<k;i++) cout<<max(maxi,self[special[i]])<<" ";
        cout<<endl;
    }