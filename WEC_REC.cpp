#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,x,k,cnt=0,ans=0;
        cin>>n>>x>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        map<int,int> mpp;
        for(int i=0;i<n;i++) mpp[arr[i]]++;
        for(auto it=mpp.rbegin();it!=mpp.rend();it++){
            if(cnt>=k||x<=0) break;
            ans+=min((*it).second,x);
            x-=(*it).second;
            cnt++;
        }
        cout<<ans<<endl;
    }
}