#include<bits/stdc++.h>
using namespace std;
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n;
        cin>>n;
        vector<int> arr(n+1);
        vector<int> ans(n+1,-1),evis(n+1,0),ovis(n+1,0);
        queue<pair<int,int>> eq,oq;
        vector<vector<int>> adj(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            if(arr[i]%2){
                oq.push({0,i});
                ovis[i]=1;
            }
            else{
                 eq.push({0,i});
                 evis[i]=1;
            }
            if(arr[i]+i<=n) adj[arr[i]+i].push_back(i);
            if(i-arr[i]>=1) adj[i-arr[i]].push_back(i);
        }
        while(!oq.empty()){
            int k=oq.size();
            for(int i=0;i<k;i++){
                int dist=oq.front().first;
                int node=oq.front().second;
                if(arr[node]%2==0&&ans[node]==-1) ans[node]=dist;
                oq.pop();
                for(auto &it:adj[node]){
                    if(!ovis[it]){
                        ovis[it]=1;
                        oq.push({dist+1,it});
                    }
                }
            }
        }
        while(!eq.empty()){
            int k=eq.size();
            for(int i=0;i<k;i++){
                int dist=eq.front().first;
                int node=eq.front().second;
                if(arr[node]%2==1&&ans[node]==-1) ans[node]=dist;
                eq.pop();
                for(auto &it:adj[node]){
                    if(!evis[it]){
                        evis[it]=1;
                        eq.push({dist+1,it});
                    }
                }
            }
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}