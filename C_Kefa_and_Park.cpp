#include<bits/stdc++.h>
using namespace std;
int dfs(int node,vector<vector<int>>& adj,int& m,vector<int>& arr,int cats){
    int ans=0;
    if(adj[node].size()==0&&node!=0){
        if(cats<=m) return 1;
        return 0;
    }
    for(auto &it:adj[node]){
        if(arr[it]+cats<=m){
            if(cats!=0&&arr[it]!=0) ans+=dfs(it,adj,m,arr,arr[it]+cats);
            else ans+=dfs(it,adj,m,arr,arr[it]);
        }
    }
    return ans;
}
int main(){
        int n,m;
        cin>>n>>m;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            if(x<y)
            adj[x-1].push_back(y-1);
            else adj[y-1].push_back(x-1);
        }
        cout<<dfs(0,adj,m,arr,arr[0])<<endl;
}