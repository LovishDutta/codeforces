#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    vector<int> spf(5e5+1);
    for(int i=1;i<=5e5;i++) spf[i]=i;
    for(int i=2;i<=5e5;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=5e5;j+=i){
                spf[j]=i;
            }
        }
    }
    while(tc--){
        int n,x,ans=1;
        cin>>n>>x;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            while(arr[i]>1){
                mpp[spf[arr[i]]]++;
                arr[i]/=spf[arr[i]];
            }
        }
        for(auto &it:mpp) ans=(ans*(it.second+1))%mod;
        cout<<ans<<endl;
    }
}