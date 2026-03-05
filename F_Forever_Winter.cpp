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
        for(int i=0;i<m;i++){
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        for(int i=0;i<n;i++){
            if(adj[i].size()==1){
                int ele=adj[i][0];
                b=adj[ele].size()-1;
                for(auto &it: adj[ele]){
                    if(adj[it].size()!=1){
                        a=adj[it].size();
                        break;
                    }
                }
                break;
            }
        }
        cout<<(a)<<" "<<(b)<<endl;
    }
}