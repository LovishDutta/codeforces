#include<bits/stdc++.h>
using namespace std;
// int dfs(int node,vector<vector<pair<int,int>>>& adj,int sum,int ans,vector<int>& b){
//     if(node==adj.size()-1) return ans;
//     int a=1e15;
//     for(auto& it:adj[node]){
//          int ver=it.first;
//          int wt=it.second;
//          if(sum>=wt){
//             a=min(a,dfs(ver,adj,sum+b[ver],max(ans,wt),b));
//          }
//     }
//     return a;
// }
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,m;
        cin>>n>>m;
        vector<int> b(n);
        for(int i=0;i<n;i++) cin>>b[i];
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<m;i++){
            int s,t,w;
            cin>>s>>t>>w;
            adj[s-1].push_back({t-1,w});
        }
        vector<pair<int,long long>> maxi(n,{INT_MAX,-1});
        priority_queue<pair<int, pair<long long,int>>,vector<pair<int, pair<long long,int>>>,greater<pair<int, pair<long long,int>>>> pq;
        pq.push({0,{b[0],0}});
        maxi[0].first=0;
        maxi[0].second=b[0];
        int ans=-1;
        while(!pq.empty()){
            int m=pq.top().first;
            long long sum=pq.top().second.first;
            int node=pq.top().second.second;
            pq.pop();
            if(node==n-1){
                ans=m;
                break;
            }
            for(auto& it:adj[node]){
                if(sum>=max(m,it.second)&&(max(m,it.second)<maxi[it.first].first||sum+b[it.first]>maxi[it.first].second)){
                    maxi[it.first].first=max(m,it.second);
                    maxi[it.first].second=sum+b[it.first];
                    pq.push({max(m,it.second),{sum+b[it.first],it.first}});
                }
            }
        }
        cout<<ans<<endl;
    }
}