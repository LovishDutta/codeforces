#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<vector<int>>& adj,bool prev,vector<int>& x,vector<int>& y,vector<int>& vis){  
    if(prev){
        x.push_back(node);
        vis[node]=1;
    }
    else{ 
        y.push_back(node);
        vis[node]=2;
    }
    for(auto& it:adj[node]){
        if(vis[it]==0){
            if(!dfs(it,adj,!prev,x,y,vis)) return false;
        }
        else if(vis[it]==vis[node]) return false;
    }
    return true;
}
int main(){
        int n,m,a,b,ans=0;
        cin>>n>>m;
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        vector<int> x;
        vector<int> y;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0&&adj[i].size()>0){
                if(!dfs(i,adj,true,x,y,vis)){
                    ans=-1;
                    break;
                }
            }
        }
        if(ans==-1) cout<<-1<<endl;
        else{
            cout<<(int)x.size()<<endl;
            for(int i=0;i<x.size();i++){
                cout<<x[i]+1<<" ";
            }
            cout<<endl;
            cout<<(int)y.size()<<endl;
            for(int i=0;i<y.size();i++){
                cout<<y[i]+1<<" ";
            }
            cout<<endl;
        }
}