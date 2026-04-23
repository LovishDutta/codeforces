#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,d,ans=0,f=1;
        cin>>n>>d;
        vector<int> arr(n),vis(n,0);
        vector<vector<int>> adj(n);
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==0){
                q.push({i,0});
                vis[i]=1;
            }
            int j = (i + n - d) % n;
            adj[i].push_back(j);
        }
        while(!q.empty()){
            int k=q.size();
            for(int i=0;i<k;i++){
                int node=q.front().first;
                int cnt=q.front().second;
                ans=max(ans,cnt);
                q.pop();
                for(auto &it:adj[node]){
                    if(!vis[it]&&arr[it]==1){
                         q.push({it,cnt+1});
                         vis[it]=1;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]&&arr[i]){
                cout<<-1<<endl;
                f=0;
                break;
            }
        }
        if(f) cout<<ans<<endl;
    }
}