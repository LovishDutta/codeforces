#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,a,b,c,flag=0;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    vector<vector<int>> arr(n);
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        adj[a-1].push_back({b-1,c});
        adj[b-1].push_back({a-1,c});
    }
    for(int i=0;i<n;i++){
        cin>>a;
        for(int j=0;j<a;j++){
            cin>>b;
            arr[i].push_back(b);
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n,1e15);
    dist[0]=0;
    pq.push({0,0});
    while(!pq.empty()){
        int time=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(node==n-1){
            cout<<time<<endl;
            flag=1;
            break;
        }
        if(time>dist[node]) continue;
        int newtime=time;
        if(arr[node].size()>0){

        int idx=lower_bound(arr[node].begin(),arr[node].end(),time)-arr[node].begin();
        if(idx<arr[node].size()&&arr[node][idx]==time){
            int diff=time-idx,low=idx,high=arr[node].size()-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(arr[node][mid]-mid<=diff) low=mid+1;
                else high=mid-1;
            }
            newtime=arr[node][high]+1;
        }
        }
        for(auto &it:adj[node]){
            if(newtime+it.second<dist[it.first]){
                dist[it.first]=newtime+it.second;
                pq.push({dist[it.first],it.first});
            }
        }
    }
    if(!flag) cout<<-1;
}