#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,a,b,ans=-1,c=1e12;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<int> col(n);
    map<int,vector<int>> mpp;
    for(int i=0;i<n;i++){
        cin>>col[i];
        mpp[col[i]].push_back(i);
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    for(auto &it:mpp){
        int cl=it.first;
        set<int> st;
        for(auto &it2:it.second){
            for(auto &it3:adj[it2]) if(col[it3]!=cl) st.insert(col[it3]);
        }
        if((int)st.size()>ans){
            ans=st.size();
            c=cl;
        }
        else if((int)st.size()==ans) c=min(c,cl);
    }
    cout<<c<<endl;
}