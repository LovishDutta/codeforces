#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,k,a,b,cnt=0;
        cin>>n>>k;
        vector<set<int>> adj(n);
        queue<int> q;
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            adj[a-1].insert(b-1);
            adj[b-1].insert(a-1);
        }
        for(int i=0;i<n;i++){
            if(adj[i].size()==1) q.push(i);
        }
        for(int i=0;i<k;i++){
            int s=q.size();
            if(s==0) break;
            cnt+=s;
            for(int j=0;j<s;j++){
                int node=q.front();
                q.pop();
                adj[*(adj[node].begin())].erase(node);
                if(adj[*(adj[node].begin())].size()==1) q.push(*(adj[node].begin()));
            }
        }
        if(n==1&&k>=1) cout<<0<<endl;
        else cout<<(n-cnt>=0?n-cnt:0)<<endl;
    }
}