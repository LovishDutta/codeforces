#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;    
    while(tc--){
        int n,cnt1=0,cnt2=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int mid1=arr[n/2];
        for(int i=0;i<n;i++){
            if(arr[i]>mid1) cnt1++;
            if(arr[i]<mid1) cnt2++;
        }
        cout<<max(cnt1,cnt2)<<endl;
    }
}