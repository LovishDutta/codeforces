#include<bits/stdc++.h>
using namespace std;
#define int long long
class dsu{
    public:
    vector<int> par,size;
    dsu(int n){
        par.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    int upar(int node){
        if(node==par[node]) return node;
        return par[node]=upar(par[node]);
    }
    void uni(int a,int b){
        int ua=upar(a);
        int ub=upar(b);
        if(ua==ub) return;
        if(size[ua]>size[ub]){
            par[ub]=ua;
            size[ua]+=size[ub];
        }
        else{
            par[ua]=ub;
            size[ub]+=size[ua];
        }
    }

};
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,m,a,d,k;
        cin>>n>>m;
        dsu ds=dsu(n+1);
        set<int> ans;
        vector<vector<vector<pair<int,int>>>> arr(11,vector<vector<pair<int,int>>>(11));
        for(int i=0;i<m;i++){
            cin>>a>>d>>k;
            arr[d][a%d].push_back({a,a+d*k});
        }
        for(int i=1;i<=10;i++){
            for(int j=0;j<i;j++){
                if(arr[i][j].size()==0) continue;
                sort(arr[i][j].begin(),arr[i][j].end());
                int prev=arr[i][j][0].first;
                for(int z=0;z<arr[i][j].size();z++){
                    int start=arr[i][j][z].first;
                    int end=arr[i][j][z].second;
                    if(start<prev) start=prev;
                    prev=max(prev,end);
                    for(int y=start;y<=end;y+=i){
                        ds.uni(start,y);
                    }
                }
            }
        }
        for(int i=1;i<=n;i++) ans.insert(ds.upar(i));
        cout<<ans.size()<<endl;
    }
}