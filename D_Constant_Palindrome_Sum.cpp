#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> diff(2*k+2,0);
        for(int i=0;i<n/2;i++){
            int maxi=max(arr[i],arr[n-1-i])+k,mini=min(arr[i],arr[n-i-1])+1;
            diff[2]+=2;
            diff[2*k+1]-=2;
            diff[mini]-=1;
            diff[maxi+1]+=1;
            diff[arr[i]+arr[n-i-1]]-=1;
            diff[arr[i]+arr[n-i-1]+1]+=1;
        }
        int ans=diff[2];
        for(int i=3;i<=2*k;i++){
            diff[i]+=diff[i-1];
            ans=min(ans,diff[i]);
        }
        cout<<ans<<endl;
    }
}