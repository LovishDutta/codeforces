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
        for(int i=0;i<n;i++) cin>>arr[i];
        int ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                int j=i;
                while(j<n-1&&arr[j+1]==0) j++;
                ans=max(ans,j-i+1);
            }
        }
        cout<<ans<<endl;
    }
}