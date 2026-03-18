#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n;
        cin>>n;
        vector<vector<int>> arr(n,vector<int>(n));
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
                mpp[arr[i][j]]++;
            }
        }
        int maxi=(n-1)*(n),ans=1;
        for(auto &it:mpp) if(it.second>maxi) ans=0;
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}