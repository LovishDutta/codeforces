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
        vector<int> arr(n);
        map<int,int> mpp;
        vector<int> vec(n+1,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mpp[arr[i]]++;
        }
        for(auto &it:mpp){
            for(int i=it.first;i<=n;i+=it.first){
                vec[i]+=it.second;
            }
        }
        int maxi=0;
        for(int i=1;i<=n;i++){
            maxi=max(maxi,vec[i]);
        }
        cout<<maxi<<endl;
    }
}