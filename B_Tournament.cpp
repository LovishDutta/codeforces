#include<bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,stack<int>& st){
    vis[node]=1;
    for(auto &it:adj[node]){
        if(!vis[it]) dfs(it,adj,vis,st);
    }
    st.push(node);
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n,a,b;
        cin>>n;
        vector<vector<int>> adj(n+1);
        vector<int> freq(n+1,0);
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<(n*(n-1))/2-1;i++){
            cin>>a>>b;
            adj[b].push_back(a);
            freq[b]++;
            freq[a]++;
        }
        for(int i=1;i<=n;i++){
            if(freq[i]!=n-1) ans.push_back(i);
            freq[i]=0;
        }
        for(int i=1;i<=n;i++){
            if(!freq[i]) dfs(i,adj,freq,st);
        }
        while(!st.empty()){
            if(st.top()==ans[0]){
                cout<<ans[1]<<" "<<ans[0];
                break;
            }
            else if(st.top()==ans[1]){
                cout<<ans[0]<<" "<<ans[1];
                break;
            }
            st.pop();
        }
    }