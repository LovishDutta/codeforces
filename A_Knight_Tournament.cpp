#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    //cin>>tc;    
    while(tc--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> arr(m,vector<int>(3));
        for(int i=0;i<m;i++) cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        vector<int> ans(n);
        set<int> st;
        for(int i=1;i<=n;i++) st.insert(i);
        for(int i=0;i<m;i++){
            auto it=st.lower_bound(arr[i][0]);
            vector<int> temp;
            for(auto k=it;k!=st.end();k++){
                if(*k>arr[i][1]) break;
                if(*k==arr[i][2]) ans[*k-1]=0;
                else{
                ans[*k-1]=arr[i][2];
                temp.push_back(*k);
                }
            }
            for(auto &it:temp) st.erase(it);
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    }
}