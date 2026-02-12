#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
long long pw(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
int recur(int node,vector<vector<pair<int,int>>>& adj,vector<int>& vis,int& cnt){
    vis[node]=1;
    cnt=cnt+1;
    for(auto& it: adj[node]){
        if(!vis[it.first]&&it.second==0) recur(it.first,adj,vis,cnt);
    }
    return cnt;
}
signed main(){
        int n,k,a,b,c;
        cin>>n>>k;
        vector<vector<pair<int,int>>> adj(n);
        vector<int> vis(n,0);
        for(int i=0;i<n-1;i++){
            cin>>a>>b>>c;
            adj[a-1].push_back({b-1,c});
            adj[b-1].push_back({a-1,c});
        }
        vector<int> arr;
        for(int i=0;i<n;i++){
            int cnt=0;
            if(!vis[i]) arr.push_back(recur(i,adj,vis,cnt));
        }
        int ans=pw(n,k);
        for(int i=0;i<arr.size();i++) ans=(ans - pw(arr[i],k) + mod) % mod;
        cout<<ans<<endl;
}