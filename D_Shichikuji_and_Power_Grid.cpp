#include<bits/stdc++.h>
using namespace std;
#define int long long
class Disjointset{
    vector<int> size,parent;
    public:
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
        int n,a,b;
        cin>>n;
        vector<pair<int,int>> coords;
        vector<int> c(n);
        vector<int> k(n);
        for(int i=0;i<n;i++){
            cin>>a>>b;
            coords.push_back({a,b});
        }
        for(int i=0;i<n;i++) cin>>c[i];
        for(int i=0;i<n;i++) cin>>k[i];
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<coords.size();i++){
            for(int j=0;j<=i;j++){
                if(i==j) pq.push({c[i],{i,i}});
                else pq.push({(abs(coords[i].first-coords[j].first)+abs(coords[i].second-coords[j].second))*(k[i]+k[j]),{i,j}});
            }
        }
        Disjointset ds(n);
        set<int> elec;
        set<int> st;
        int cost=0;
        vector<pair<int,int>> ans;
        while(!pq.empty()){
            int ct=pq.top().first;
            int n1=pq.top().second.first;
            int n2=pq.top().second.second;
            pq.pop();
            if(n1==n2){
                int up=ds.findUpar(n1);
                if(elec.find(up)==elec.end()){
                    cost+=ct;
                    st.insert(n1);
                    elec.insert(up);
                }
            }
            else{
                int up1=ds.findUpar(n1);
                int up2=ds.findUpar(n2);
                if(up1==up2) continue;
                else{
                    if(elec.find(up1)!=elec.end()&&elec.find(up2)!=elec.end()) continue;
                    else if(elec.find(up1)!=elec.end()||elec.find(up2)!=elec.end()){
                        ds.unionbysize(n1,n2);
                        ans.push_back({n1,n2});
                        elec.insert(ds.findUpar(n1));
                        cost+=ct;
                    }
                    else{
                        cost+=ct;
                        ds.unionbysize(n1,n2);
                        ans.push_back({n1,n2});
                    }
                }

            }
        }
        cout<<cost<<endl;
        cout<<st.size()<<endl;
        for(auto& it: st) cout<<(it+1)<<" ";
        cout<<endl;
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<(ans[i].first+1)<<" "<<(ans[i].second+1)<<endl;
        }
}