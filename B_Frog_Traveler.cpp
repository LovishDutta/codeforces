#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1),dist(n+1,1e15),par(n+1),ans,land(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    queue<pair<int,int>> pq;
    dist[n]=0;
    pq.push({0,n});
    int prev=n,node=0;
    while(!pq.empty()){
        int depth=pq.front().second;
        int cnt=pq.front().first;
        pq.pop();
        if(dist[depth]<cnt) continue;
        if(depth==0) break;
        for(int i=depth-a[depth];i<=min(depth-1,prev-1);i++){
            if(dist[i+b[i]]>cnt+1){
                dist[i+b[i]]=cnt+1;
                pq.push({dist[i+b[i]],i+b[i]});
                par[i+b[i]]=depth;
                land[i+b[i]]=i;
            }
        }
        prev=min(prev,depth-a[depth]);

    }
    if(dist[0]==1e15) cout<<-1;
    else{
        cout<<dist[0]<<endl;
        while(node!=n){
            ans.push_back(land[node]);
            node=par[node];
        }
        for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
    }
}