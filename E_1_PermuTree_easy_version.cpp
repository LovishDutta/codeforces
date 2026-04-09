#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(int idx,int a,int& tot,vector<int>& arr,vector<vector<int>>& dp){
    if(idx==arr.size()) return a*(tot-a);
    if(dp[idx][a]!=-1) return dp[idx][a];
    return dp[idx][a]=max(recur(idx+1,a+arr[idx],tot,arr,dp),recur(idx+1,a,tot,arr,dp));
}
int dfs(int node,vector<vector<int>>& adj,vector<int>& vis,int& final){
    vis[node]=1;
    int ans=0;
    vector<int> arr;
    for(auto &it:adj[node]){
        if(!vis[it]){
            int ele=dfs(it,adj,vis,final);
            ans+=ele;
            arr.push_back(ele);
        }
    }
    vector<vector<int>> dp(arr.size()+1,vector<int>(ans+1,-1));
    final+=recur(0,0,ans,arr,dp);
    return ans+1;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,a,final=0;
    cin>>n;
    vector<vector<int>> adj(n);
    vector<int> vis(n,0);
    for(int i=1;i<n;i++){
        cin>>a;
        adj[i].push_back(a-1);
        adj[a-1].push_back(i);
    }
    dfs(0,adj,vis,final);
    cout<<final<<endl;
}