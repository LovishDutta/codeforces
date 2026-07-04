#include<bits/stdc++.h>
using namespace std;
#define int long long
int dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& arr,int& ans){
    vis[node]=1;
    vector<int> temp;
    int sum=0,n=vis.size(),ret=0;
    for(auto &it:adj[node]){
        if(!vis[it]){
            int val=dfs(it,adj,vis,arr,ans);
            temp.push_back(val);
            sum+=val;
        }
    }
    temp.push_back(n-1-sum);
    int sq=sqrt(arr[node]);
    if(sq*sq==arr[node]){
        int p1=0,p2=0,p3=0;
        for(int i=0;i<temp.size();i++){
            p1+=temp[i];
            p2+=temp[i]*temp[i];
            p3+=temp[i]*temp[i]*temp[i];
        }
        ans+=(p1*p1-p2)/2+(((p1*p1-p2)/2)*p1-p1*p2+p3)/3;
    }
    return sum+1;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,a,b,ans=0;
        cin>>n;
        vector<int> arr(n),vis(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        dfs(0,adj,vis,arr,ans);
        cout<<ans<<endl;
    }
}