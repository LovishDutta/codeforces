#include<bits/stdc++.h>
using namespace std;
#define int long long
class Disjointset{
    public:
    vector<int> size,parent;
    Disjointset(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findUpar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionbysize(int u,int v){
        int a=findUpar(u);
        int b=findUpar(v);
        if(a==b) return;
        if(size[a]<size[b]){
            parent[a]=b;
            size[b]+=size[a];
        }
        else{
            parent[b]=a;
            size[a]+=size[b];
        }
    }
};
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n-1,vector<int>(3));
    vector<int> q(m);
    for(int i=0;i<n-1;i++){
        cin>>arr[i][2]>>arr[i][1]>>arr[i][0];
        arr[i][2]--;
        arr[i][1]--;
    }
    for(int i=0;i<m;i++) cin>>q[i];
    sort(arr.begin(),arr.end());
    int ans=0,idx=0;
    vector<int> vec;
    Disjointset ds(n);
    for(int i=1;i<=m;i++){
        while(idx<n-1&&arr[idx][0]<=i){
            int ele1=ds.size[ds.findUpar(arr[idx][1])],ele2=ds.size[ds.findUpar(arr[idx][2])];
            ans-=(ele1*(ele1-1))/2;
            ans-=(ele2*(ele2-1))/2;
            ds.unionbysize(arr[idx][1],arr[idx][2]);
            int ele3=ds.size[ds.findUpar(arr[idx][1])];
            ans+=(ele3*(ele3-1))/2;
            idx++;
        }
        vec.push_back(ans);
    }
    for(int i=0;i<m;i++) cout<<vec[q[i]-1]<<" ";
}