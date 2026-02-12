#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int ind=upper_bound(arr.begin(),arr.end(),arr[i]+2)-arr.begin()-1;
            if(ind-i>1&&arr[ind]-arr[i]<=2){
                ans+=((ind-i-1)*(ind-i))/2;
            }
        }
        cout<<ans<<endl;
    }
}