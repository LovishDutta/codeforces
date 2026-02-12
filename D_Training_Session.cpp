#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t,a,b;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
    map<int,int> mpp;
    map<int,vector<pair<int,int>>> mpp2;
    int ans=(n*(n-1)*(n-2))/6;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        mpp[b]++;
        mpp2[a].push_back({a,b});
    }
    for(auto &it2:mpp2){
        for(auto &it: it2.second){
            ans-=(it2.second.size()-1)*(mpp[it.second]-1);
        }
    }
    cout<<ans<<endl;
}
}