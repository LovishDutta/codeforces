#include<bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int node,vector<vector<int>>& adj,vector<int>& vis){
    vis[node] = 1;
    for(int child : adj[node]){
        if(!vis[child]){
            dfs(child,adj,vis);
        }
    }
}
bool cmp(const pair<string,int>& a, const pair<string,int>& b){
    int c1 = count(a.first.begin(), a.first.end(), '1');
    int c2 = count(b.first.begin(), b.first.end(), '1'); 
    if(c1 == c2) 
        return a.second < b.second;
    return c1 < c2;
}
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,flag=1;
        cin>>n;
        vector<pair<string,int>> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i].first;
            arr[i].second=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&arr[i].first[j]=='1'&&arr[j].first[i]=='1'){
                    flag=0;
                    break;
                }
                if(arr[i].first[i]=='0'){
                    flag=0;
                    break;
                }
            }
        }
        if(!flag){
            cout<<"No"<<endl;
            continue;
        }
        sort(arr.begin(),arr.end(),cmp);
        vector<int> vis(n,0);
        vector<pair<int,int>> ans;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=arr[i].second&&arr[i].first[j]=='1'&&!vis[j]){
                    vis[j]=1;
                    ans.push_back({arr[i].second,j});
                    adj[arr[i].second].push_back(j);
                    cout<<arr[i].second<<" "<<j<<endl;
                }
            }
        }
        if(ans.size()!=n-1){
            cout<<"No"<<endl;
            continue;
        }
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            dfs(arr[i].second,adj,vis);
            for(int j=0;j<n;j++){
                if(vis[j] != (arr[i].first[j]=='1')){
                flag = 0;
                break;
                }
            }
        }
        if(!flag){
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
        }
    }
}