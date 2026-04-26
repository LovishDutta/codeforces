#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,a=0,b;
    cin>>n;
    vector<vector<int>> edges(n-1,vector<int>(2));
    vector<int> deg(n+1,0);
    vector<int> ans(n-1,-1);
    for(int i=0;i<n-1;i++){
        cin>>edges[i][0]>>edges[i][1];
        deg[edges[i][0]]++;
        deg[edges[i][1]]++;
    }
    for(int i=0;i<n-1;i++){
        if(deg[edges[i][0]]==1||deg[edges[i][1]]==1) ans[i]=a++;
    }
    for(int i=0;i<n-1;i++){
        if(ans[i]==-1) cout<<(a++)<<endl;
        else cout<<ans[i]<<endl;
    }
}