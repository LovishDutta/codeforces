#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c=1;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    for(int i=0;i<n;i++) if(adj[i].size()==2) c=0;
    cout<<(c?"YES":"NO")<<endl;
}