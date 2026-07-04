#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,l,r,ans1=0,ans2=0;
        cin>>n>>l>>r;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<l-1;i++) ans1+=arr[i];
        for(int i=r;i<n;i++) ans2+=arr[i];
        cout<<max(ans1,ans2)<<endl;
    }
}