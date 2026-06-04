#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
       int n,maxi=0,ans=1e9;
       cin>>n;
       vector<int> arr(n);
       for(int i=0;i<n;i++){
           cin>>arr[i];
           maxi=max(maxi,arr[i]);
        }
       vector<int> freq(maxi+1);
       vector<int> dp(maxi+1);
       for(int i=0;i<n;i++) freq[arr[i]]++;
       for(int i=0;i<=maxi;i++){
        if(freq[i]>0){
            dp[i]=max(dp[i],freq[i]);
            for(int j=i*2;j<=maxi;j+=i){
                if(freq[j]>0){
                    dp[j]=max(dp[j],dp[i]+freq[j]);
                }
            }
            ans=min(ans,n-dp[i]);
        }
       }
       cout<<ans<<endl;
    }
}