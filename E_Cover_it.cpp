#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m,a,b;
        cin>>n>>m;
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        vector<int> ansvis(n,0);
        vector<int> ans;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        for(int i=0;i<n;i++){
            if(ans.size()==n/2) break;
            if(adj[i].size()==1&&(!vis[i])){
                ans.push_back(adj[i][0]+1);
                ansvis[adj[i][0]]=1;
                vis[adj[i][0]]=1;
                for(auto &it:adj[adj[i][0]]) vis[it]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(ans.size()==n/2) break;
            if(ansvis[i]) continue;
            int cnt=(!vis[i]);
            for(auto &it:adj[i]) if(!vis[it]) cnt++;
            if(cnt>2){
                ans.push_back(i+1);
                ansvis[i]=1;
                vis[i]=1;
                for(auto &it:adj[i]) vis[it]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(ans.size()==n/2) break;
            if(ansvis[i]) continue;
            int cnt=(!vis[i]);
            for(auto &it:adj[i]) if(!vis[it]) cnt++;
            if(cnt==2){
                ans.push_back(i+1);
                ansvis[i]=1;
                vis[i]=1;
                for(auto &it:adj[i]) vis[it]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(ans.size()==n/2) break;
            if(ansvis[i]) continue;
            int cnt=(!vis[i]);
            for(auto &it:adj[i]) if(!vis[it]) cnt++;
            if(cnt>0){
                ans.push_back(i+1);
                ansvis[i]=1;
                vis[i]=1;
                for(auto &it:adj[i]) vis[it]=1;
            }
        }
        cout<<ans.size()<<endl;
        for(auto &it:ans) cout<<it<<" ";
        cout<<endl;
    }
}