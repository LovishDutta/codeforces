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
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
        int ans=0;
        for(int x=1;x<=105;x++){
            int y=x;
            for(int i=0;i<n;i++){
                if(y<arr[i].first) y=arr[i].first;
                else if(y>arr[i].second) y=arr[i].second;
            }
            ans=max(ans,y);
        }
        cout<<ans<<endl;
    }
}