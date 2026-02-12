#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        int ans=arr[n-1];
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=arr[i+1]) arr[i]=max(0LL,arr[i+1]-1);
             ans+=arr[i];
        }
        cout<<ans<<endl;
}