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
        unordered_map<int,int> mpp;
        unordered_map<int,int> cnt;
        mpp.reserve(n * 40);
        cnt.reserve(n * 40);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            int ele=arr[i],ct=0;
            if(ele==1){
                cnt[1]++;
                cnt[2]++;
                mpp[2]++;
                mpp[1]+=0;
            }
            else{
             while(ele!=1){
                mpp[ele]+=ct;
                cnt[ele]++;
                if(ele%2) ele++;
                else ele/=2;
                ct++;
            }
            mpp[1]+=ct;
            cnt[1]++;
        }
        }
        int ans=1e15;
        for(auto &it:mpp){
            if(cnt[it.first]==n) ans=min(ans,it.second);
        }
        cout<<ans<<endl;
    }
}